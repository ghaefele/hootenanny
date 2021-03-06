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
 * @copyright Copyright (C) 2015, 2016, 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */
#include "ConflateCaseTestSuite.h"

// hoot
#include <hoot/core/HootConfig.h>
#include <hoot/core/cmd/ConflateCmd.h>
#include <hoot/core/test/ConflateCaseTest.h>
#include <hoot/core/util/HootException.h>
#include <hoot/core/util/Log.h>
#include <hoot/core/util/Settings.h>
#include <hoot/core/util/ConfPath.h>

// Qt
#include <QDir>
#include <QFileInfo>

namespace hoot
{

ConflateCaseTestSuite::ConflateCaseTestSuite(const QString& dir, bool hideDisableTests)
  : AbstractTestSuite(dir),
    _hideDisableTests(hideDisableTests),
    _numTests(0)
{
  QStringList confs;
  loadDir(dir, confs);
  LOG_VART(_numTests);
}

void ConflateCaseTestSuite::_loadBaseConfig(const QString& testConfigFile, QStringList& confs)
{
  // need to grab the whole current config here to avoid errors when calling loadJson
  Settings tempConfig = conf();
  tempConfig.loadJson(ConfPath::search(testConfigFile));
  if (tempConfig.hasKey(Settings::BASE_CONFIG_OPTION_KEY))
  {
    const QStringList baseConfigs =
      tempConfig.getString(Settings::BASE_CONFIG_OPTION_KEY).trimmed().split(",");
    for (int i = 0; i < baseConfigs.size(); i++)
    {
      const QString baseConfig = baseConfigs.at(i);
      if (!baseConfig.isEmpty() && !confs.contains(baseConfig))
      {
        confs.append(baseConfig);
      }
    }
  }
}

void ConflateCaseTestSuite::loadDir(const QString& dir, QStringList confs)
{
  if (dir.endsWith(".off"))
  {
    return;
  }
  QDir d(dir);

  QFileInfo fi(d.absoluteFilePath("Config.conf"));

  if (fi.exists())
  {
    const QString testConfFile = fi.absoluteFilePath();

    // Check for a specified base config option, which allows the test to load a separate base
    // configuration as its starting point. The other settings in its config file will override
    // whatever is in the base configuration.
    _loadBaseConfig(testConfFile, confs);

    // load the test's config file
    confs.append(testConfFile);

    LOG_VART(confs);
  }

  // a list of strings paths to ignore if this string is found in the path.
  QStringList ignoreList;

# ifndef HOOT_HAVE_RND
  ignoreList << "hoot-rnd";
# endif
# ifndef HOOT_HAVE_SERVICES
  ignoreList << "hoot-services";
# endif

  QStringList dirs = d.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
  for (int i = 0; i < dirs.size(); i++)
  {
    QString path = d.absoluteFilePath(dirs[i]);

    bool ignore = false;

    for (int i = 0; i < ignoreList.size(); i++)
    {
      if (path.contains(ignoreList[i]))
      {
        ignore = true;
      }
    }

    if (ignore)
    {
      if (!_hideDisableTests)
        LOG_WARN("Disabling: " + path);
    }
    else
    {
      loadDir(path, confs);
    }
  }

  if (dirs.size() > 0)
  {
    // this is entirely a preference thing. I want people to keep the tests clean and uncluttered.
    if (QFileInfo(d, "Input1.osm").exists() ||
        QFileInfo(d, "Input2.osm").exists() ||
        QFileInfo(d, "Output.osm").exists())
    {
      throw HootException("Please put conflate test cases in a directory w/o sub directories.");
    }
  }
  else
  {
    addTest(new ConflateCaseTest(d, confs));
    _numTests++;
  }
}

}
