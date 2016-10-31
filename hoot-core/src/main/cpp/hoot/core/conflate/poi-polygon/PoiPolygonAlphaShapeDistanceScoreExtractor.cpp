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
 * @copyright Copyright (C) 2015 DigitalGlobe (http://www.digitalglobe.com/)
 */
#include "PoiPolygonAlphaShapeDistanceScoreExtractor.h"

// hoot
//#include <hoot/core/util/ConfigOptions.h>
#include <hoot/core/Factory.h>
#include <hoot/core/util/ElementConverter.h>
#include <hoot/core/conflate/AlphaShapeGenerator.h>

// geos
#include <geos/util/TopologyException.h>
#include <geos/geom/Geometry.h>

namespace hoot
{

HOOT_FACTORY_REGISTER(FeatureExtractor, PoiPolygonAlphaShapeDistanceScoreExtractor)

PoiPolygonAlphaShapeDistanceScoreExtractor::PoiPolygonAlphaShapeDistanceScoreExtractor()
{
}

/*void PoiPolygonAlphaShapeDistanceScoreExtractor::setConfiguration(const Settings& conf)
{
  ConfigOptions config = ConfigOptions(conf);
  //setNameScoreThreshold(config.getPoiPolygonMatchNameThreshold());
}*/

double PoiPolygonAlphaShapeDistanceScoreExtractor::extract(const OsmMap& map,
                                                           const ConstElementPtr& poi,
                                                           const ConstElementPtr& poly) const
{
  ElementConverter elementConverter(map.shared_from_this());
  shared_ptr<Geometry> polyGeom = elementConverter.convertToGeometry(poly);
  if (QString::fromStdString(polyGeom->toString()).toUpper().contains("EMPTY"))
  {
    throw geos::util::TopologyException();
  }
  shared_ptr<Geometry> poiGeom = elementConverter.convertToGeometry(poi);

  OsmMapPtr polyMap(new OsmMap());
  ElementPtr polyTemp(poly->clone());
  polyMap->addElement(polyTemp);
  shared_ptr<Geometry> polyAlphaShape = AlphaShapeGenerator(1000.0, 0.0).generateGeometry(polyMap);
  //oddly, even if the area is zero calc'ing the distance can have a positive effect
  /*if (polyAlphaShape->getArea() == 0.0)
  {
    return -1.0;
  }*/
  return polyAlphaShape->distance(poiGeom.get());
}

}