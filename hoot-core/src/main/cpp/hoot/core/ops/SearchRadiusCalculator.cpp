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

#include "SearchRadiusCalculator.h"

// Hoot
#include <hoot/core/util/Factory.h>
#include <hoot/core/ops/MapCleaner.h>
#include <hoot/core/algorithms/rubber-sheet/RubberSheet.h>
#include <hoot/core/visitors/RemoveElementsVisitor.h>
#include <hoot/core/criterion/StatusCriterion.h>
#include <hoot/core/criterion/ChainCriterion.h>
#include <hoot/core/io/OsmMapWriterFactory.h>
#include <hoot/core/util/MapProjector.h>
#include <hoot/core/elements/OsmMap.h>
#include <hoot/core/util/StringUtils.h>

using namespace std;

namespace hoot
{

HOOT_FACTORY_REGISTER(OsmMapOperation, SearchRadiusCalculator)

SearchRadiusCalculator::SearchRadiusCalculator()
{
  setConfiguration(conf());
}

void SearchRadiusCalculator::setConfiguration(const Settings& conf)
{
  ConfigOptions config(conf);
  setCircularError(config.getCircularErrorDefaultValue());
  setRubberSheetRef(config.getRubberSheetRef());
  setRubberSheetMinTies(config.getRubberSheetMinimumTies());
  setPrecision(config.getWriterPrecision());
  _elementCriterion = config.getSearchRadiusCalculatorElementCriterion().trimmed();
}

void SearchRadiusCalculator::apply(std::shared_ptr<OsmMap>& map)
{
  //make a copy of the map with previously conflated data removed, as the rubber sheeting can't
  //use it
  std::shared_ptr<OsmMap> mapWithOnlyUnknown1And2(new OsmMap(map));

  LOG_VARD(map->getElementCount());
  LOG_DEBUG(
    "Element count before search radius calculation filtering: " <<
    StringUtils::formatLargeNumber(mapWithOnlyUnknown1And2->getElementCount()));

  // don't care about conflated data and invalid data
  LOG_INFO("Removing invalid and previously conflated data for search radius calculation...");
  size_t elementCountTemp = mapWithOnlyUnknown1And2->getElementCount();
  RemoveElementsVisitor elementRemover1;
  elementRemover1.setRecursive(true);
  elementRemover1.addCriterion(ElementCriterionPtr(new StatusCriterion(Status::Conflated)));
  mapWithOnlyUnknown1And2->visitRw(elementRemover1);
  RemoveElementsVisitor elementRemover2;
  elementRemover2.setRecursive(true);
  elementRemover2.addCriterion(ElementCriterionPtr(new StatusCriterion(Status::Invalid)));
  mapWithOnlyUnknown1And2->visitRw(elementRemover2);
  if (mapWithOnlyUnknown1And2->getElementCount() < elementCountTemp)
  {
    LOG_INFO(
      "Filtered out: " <<
      StringUtils::formatLargeNumber(elementCountTemp - mapWithOnlyUnknown1And2->getElementCount()) <<
      " invalid or conflated elements.");
    elementCountTemp = mapWithOnlyUnknown1And2->getElementCount();
  }

  // If a match candidate criterion was specified, filter out elements that don't fit the criterion.
  // If no match candidate criterion was specified, then we'll use elements of all types.
  // TODO: This logic doesn't support Generic Conflation calling scripts who implement the
  // isMatchCandidate function. - see #3048
  if (!_elementCriterion.isEmpty())
  {
    LOG_INFO(
      "Removing elements not satisfying: " << _elementCriterion <<
      " for search radius calculation...");
    std::shared_ptr<ElementCriterion> candidateCriterion(
      Factory::getInstance().constructObject<ElementCriterion>(_elementCriterion));
    RemoveElementsVisitor elementRemover3(true);
    elementRemover3.setRecursive(true);
    elementRemover3.addCriterion(candidateCriterion);
    mapWithOnlyUnknown1And2->visitRw(elementRemover3);
  }

  LOG_VARD(map->getElementCount());
  if (mapWithOnlyUnknown1And2->getElementCount() < elementCountTemp)
  {
    LOG_INFO(
      "Filtered out: " <<
      StringUtils::formatLargeNumber(elementCountTemp - mapWithOnlyUnknown1And2->getElementCount()) <<
      " elements not satisfying candidate criterion.");
  }

  if (map->getElementCount() > mapWithOnlyUnknown1And2->getElementCount())
  {
    //should this be a warning?
    LOG_DEBUG(
      "Skipping " <<
      StringUtils::formatLargeNumber(map->getElementCount() - mapWithOnlyUnknown1And2->getElementCount()) <<
      " features with conflated or invalid status out of " <<
      StringUtils::formatLargeNumber(map->getElementCount()) << " total features.");
  }
  if (mapWithOnlyUnknown1And2->getElementCount() == 0)
  {
    _result = _circularError;
    LOG_INFO(
      "Unable to automatically calculate search radius.  All input features have been " <<
      "filtered out. Using default search radius value = " << _result);
    return;
  }

  LOG_DEBUG(
    "Element count after search radius calculation filtering: " <<
    StringUtils::formatLargeNumber(mapWithOnlyUnknown1And2->getElementCount()));

  std::shared_ptr<RubberSheet> rubberSheet(new RubberSheet());
  rubberSheet->setReference(_rubberSheetRef);
  rubberSheet->setMinimumTies(_minTies);
  rubberSheet->setFailWhenMinimumTiePointsNotFound(false);
  rubberSheet->setLogWarningWhenRequirementsNotFound(false);
  try
  {
    rubberSheet->calculateTransform(mapWithOnlyUnknown1And2);
  }
  catch (const HootException& e)
  {
    //In many cases, the input map will have already been cleaned by this point...but possibly not
    //(direct call to the stats command, for example).  Try to clean it to get around this error.
    LOG_DEBUG("Rubber sheeting error: " << e.getWhat());
    LOG_DEBUG(
      "An error occurred calculating the rubber sheet transform during automatic search radius " <<
      "calculation.  Cleaning the data and attempting to calculate the transform again...");
    try
    {
      MapCleaner().apply(mapWithOnlyUnknown1And2);
      rubberSheet.reset(new RubberSheet());
      rubberSheet->setReference(_rubberSheetRef);
      rubberSheet->setMinimumTies(_minTies);
      rubberSheet->setFailWhenMinimumTiePointsNotFound(false);
      rubberSheet->setLogWarningWhenRequirementsNotFound(false);
      rubberSheet->calculateTransform(mapWithOnlyUnknown1And2);
    }
    catch (const HootException& e)
    {
      _result = _circularError;
      LOG_DEBUG(e.getWhat());
      LOG_INFO(
        QString("Unable to automatically calculate search radius: \n") +
        QString("Using default search radius value = ") + QString::number(_result));
      return;
    }
  }

  vector<double> tiePointDistances;
  try
  {
    tiePointDistances = rubberSheet->calculateTiePointDistances();
  }
  catch (const HootException&)
  {
    //unrecoverable error...we'll end up using the default search distance instead
  }

  _calculateSearchRadius(tiePointDistances);
}

void SearchRadiusCalculator::_calculateSearchRadius(const vector<double>& tiePointDistances)
{
  if (tiePointDistances.size() < 2)
  {
    _result = _circularError;
    LOG_INFO(
      QString("Unable to automatically calculate search radius.  Not enough tie points.  ") +
      QString("Using default search radius value = ") + QString::number(_result));
  }
  else
  {
    _result = 2 * _calculateStandardDeviation(tiePointDistances);
    LOG_DEBUG("Calculated search radius = " + QString::number(_result, 'g', 2));
  }
}

double SearchRadiusCalculator::_calculateStandardDeviation(const vector<double>& samples)
{
  double sumSquares = 0.0;
  for (size_t i = 0; i < samples.size(); i++)
  {
    const double v = samples[i];
    sumSquares += v * v;
  }
  return sqrt(sumSquares / (double)(samples.size() - 1));
}

}
