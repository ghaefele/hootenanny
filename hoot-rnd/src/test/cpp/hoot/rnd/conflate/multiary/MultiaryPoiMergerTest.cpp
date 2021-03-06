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
 * @copyright Copyright (C) 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */

// Hoot
#include <hoot/core/TestUtils.h>
#include <hoot/core/conflate/matching/MatchFactory.h>
#include <hoot/core/conflate/merging/MergerFactory.h>
#include <hoot/core/conflate/UnifyingConflator.h>
#include <hoot/core/io/OsmJsonReader.h>
#include <hoot/core/io/OsmJsonWriter.h>
#include <hoot/core/util/Factory.h>
#include <hoot/core/util/Log.h>
#include <hoot/core/util/MapProjector.h>
#include <hoot/rnd/conflate/multiary/MultiaryUtilities.h>

using namespace std;

namespace hoot
{

class MultiaryPoiMergerTest : public HootTestFixture
{
  CPPUNIT_TEST_SUITE(MultiaryPoiMergerTest);
  CPPUNIT_TEST(basicTest);
  CPPUNIT_TEST_SUITE_END();

public:

  MultiaryPoiMergerTest()
  {
    setResetType(ResetAll);
  }

  /**
   * Simple conflation test case. Should merge 1/2 and 3/4. There should be a review generated
   * between 1/2 and 3/4 due to the amenity=pub tag.
   */
  void basicTest()
  {
    QString testJsonStr =
      "{                                      \n"
      " 'elements': [                         \n"
      " { 'type': 'node', 'id': -1, 'lat': 2.0, 'lon': -3.0, \n"
      "   'tags': { 'amenity': 'pub', 'name': 'My Restaurant', 'hoot:hash': 'AAA' } },\n"
      " { 'type': 'node', 'id': -2, 'lat': 3.0, 'lon': -3.0, \n"
      "   'tags': { 'amenity': 'pub', 'name': 'my Restaurant', 'hoot:hash': 'BBB' } },\n"
      " { 'type': 'node', 'id': -3, 'lat': 14.0, 'lon': -3.0, \n"
      "   'tags': { 'amenity': 'pub', 'name': 'Not the same', 'hoot:hash': 'CCC' } },\n"
      " { 'type': 'node', 'id': -4, 'lat': 14.0, 'lon': -3.0, \n"
      "   'tags': { 'place': 'locality', 'name': 'Not the same', 'hoot:hash': 'DDD' } }\n"
      "]                                      \n"
      "}                                      \n";

    OsmMapPtr map = OsmJsonReader().loadFromString(testJsonStr);
    map->setProjection(MapProjector::createOrthographic(0, 0));

    map->getNode(-1)->setStatus(Status::fromInput(0));
    map->getNode(-2)->setStatus(Status::fromInput(1));
    map->getNode(-3)->setStatus(Status::fromInput(2));
    map->getNode(-4)->setStatus(Status::fromInput(3));

    MultiaryUtilities::conflate(map);

    OsmJsonWriter writer;
    writer.setIncludeCircularError(false);
    QString result = writer.toString(map);

    //LOG_VAR(TestUtils::toQuotedString(OsmJsonWriter().toString(map)));
    HOOT_STR_EQUALS("{\"version\": 0.6,\"generator\": \"Hootenanny\",\"elements\": [\n"
                    "{\"type\":\"node\",\"id\":-1,\"lat\":2,\"lon\":-3,\"tags\":{\"amenity\":\"pub\",\"hoot:hash\":\"\",\"name\":\"My Restaurant\",\"alt_name\":\"my Restaurant\",\"source:hash\":\"AAA;BBB\"}},\n"
                    "{\"type\":\"node\",\"id\":-3,\"lat\":14,\"lon\":-3,\"tags\":{\"amenity\":\"pub\",\"hoot:hash\":\"\",\"name\":\"Not the same\",\"source:hash\":\"CCC;DDD\",\"place\":\"locality\"}},\n"
                    "{\"type\":\"relation\",\"id\":-1,\"members\":[\n"
                    "{\"type\":\"node\",\"ref\":-3,\"role\":\"reviewee\"},\n"
                    "{\"type\":\"node\",\"ref\":-1,\"role\":\"reviewee\"}],\"tags\":{\"hoot:review:type\":\"POI\",\"hoot:review:note\":\"Somewhat similar (12m) - very close together, similar POI type\",\"hoot:review:members\":\"2\",\"hoot:review:needs\":\"yes\",\"hoot:review:score\":\"-1\"}]\n"
                    "}\n", result);
  }

};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MultiaryPoiMergerTest, "glacial");

}
