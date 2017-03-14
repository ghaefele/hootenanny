/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2016, 2017 DigitalGlobe (http://www.digitalglobe.com/)
 */

#include "OsmApiDbBulkWriter2.h"

#include <QDateTime>
#include <QFileInfo>
#include <QStringBuilder>

#include <hoot/core/util/HootException.h>
#include <hoot/core/util/Factory.h>
#include <hoot/core/util/Settings.h>
#include <hoot/core/util/DbUtils.h>

#include <tgs/System/SystemInfo.h>

namespace hoot
{

using namespace Tgs;

unsigned int OsmApiDbBulkWriter2::logWarnCount = 0;

HOOT_FACTORY_REGISTER(OsmMapWriter, OsmApiDbBulkWriter2)

OsmApiDbBulkWriter2::OsmApiDbBulkWriter2() :
OsmApiDbBulkWriter(),
_offline(true)
{

}

OsmApiDbBulkWriter2::~OsmApiDbBulkWriter2()
{
  close();
}

bool OsmApiDbBulkWriter2::isSupported(QString urlStr)
{
  QUrl url(urlStr);
  return _database.isSupported(url) && (_disableWriteAheadLogging || _writeMultiThreaded);
}

void OsmApiDbBulkWriter2::finalizePartial()
{
  if (_writeStats.nodesWritten == 0)
  {
    LOG_DEBUG("No data was written.");
    return;
  }

  LOG_INFO("Input records parsed stats:");
  _logStats();

  // Do we have an unfinished changeset that needs flushing?
  if (_changesetData.changesInChangeset > 0)
  {
    _writeChangesetToTable();
  }
  //If there was only one changeset written total, this won't have yet been incremented, so do it
  //now.
  if (_changesetData.changesetsWritten == 0)
  {
    _changesetData.changesetsWritten++;
  }

  //retain the sql output file if that option was selected
  if (!_sqlFileCopyLocation.isEmpty())
  {
    _retainSqlOutputFile();
  }

  if (_executeSql)
  {
    _writeDataToDb();
    LOG_INFO("Final database write stats:");
  }
  else
  {
    LOG_INFO("Skipping SQL execution against database due to configuration...");
    LOG_INFO("Final SQL file write stats:");
  }
  _logStats();
}

void OsmApiDbBulkWriter2::_retainOutputFiles()
{
  QFileInfo baseFileInfo(_outputFileCopyLocation);
  for (QStringList::const_iterator sectionNamesItr = _sectionNames.begin();
       sectionNamesItr != _sectionNames.end(); sectionNamesItr++)
  {
    if (_outputSections[*sectionNamesItr].first.get())
    {
      const QString outputPath = baseFileInfo.path() + "/" + baseFileInfo.baseName() + "-" +
        *_sectionNamesItr + "." + baseFileInfo.completeSuffix();
      QFileInfo fileToCopyInfo(_outputSections[*sectionNamesItr]->fileName());
      LOG_INFO(
        "Copying " << SystemInfo::humanReadable(fileToCopyInfo.size()) << " CSV output file " <<
        "to " << outputPath << "...");
      if (!_outputSections[*sectionNamesItr].first->copy(outputPath))
      {
        LOG_WARN("Unable to copy CSV output file to " << outputPath);
      }
      else
      {
        LOG_DEBUG("Copied CSVL file output to " << outputPath);
      }
    }
  }
}

void OsmApiDbBulkWriter2::_writeDataToDb()
{
  LOG_INFO(
    "Executing element SQL for " << _formatPotentiallyLargeNumber(_getTotalRecordsWritten()) <<
    " records.  17 separate SQL COPY statements will be executed...");

  //TODO: finish
  QString cmd = "";
  LOG_DEBUG(cmd);
  if (system(cmd.toStdString().c_str()) != 0)
  {
    throw HootException("Failed executing bulk element SQL write against the OSM API database.");
  }
  LOG_DEBUG("Element SQL execution complete.");
}

void OsmApiDbBulkWriter2::setConfiguration(const Settings& conf)
{
  OsmApiDbBulkWriter::setConfiguration(conf);

  const ConfigOptions confOptions(conf);
  setDisableWriteAheadLogging(confOptions.getOsmapidbBulkWriterDisableWriteAheadLogging());
  setWriteMultithreaded(confOptions.getOsmapidbBulkWriterMultithreaded());
}

}