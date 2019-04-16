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
 * @copyright Copyright (C) 2014, 2015, 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */

// CPP Unit
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>

// Hoot
#include <hoot/core/TestUtils.h>
#include <hoot/core/elements/OsmMap.h>
#include <hoot/core/io/OsmXmlReader.h>
#include <hoot/core/io/OsmXmlWriter.h>
#include <hoot/core/util/Log.h>
#include <hoot/core/util/MapProjector.h>
#include <hoot/rnd/perty/PertyWayGeneralizeVisitor.h>

// Qt
#include <QFileInfo>

using namespace std;

namespace hoot
{

class PertyWayGeneralizeVisitorTest : public HootTestFixture
{
  CPPUNIT_TEST_SUITE(PertyWayGeneralizeVisitorTest);
  CPPUNIT_TEST(runTest1);
  CPPUNIT_TEST(runTest2);
  CPPUNIT_TEST(runTest3);
  CPPUNIT_TEST(runTest4);
  CPPUNIT_TEST(runTest5);
  CPPUNIT_TEST(runTest6);
  CPPUNIT_TEST(runTest7);
  CPPUNIT_TEST(runTest8);
  CPPUNIT_TEST(runTest9);
  CPPUNIT_TEST_SUITE_END();

public:

  QMap<QString, OsmMapPtr> _inputMapCache;

  PertyWayGeneralizeVisitorTest()
    : HootTestFixture("test-files/rnd/perty/PertyWayGeneralizeVisitorTest/",
                      "test-output/rnd/perty/PertyWayGeneralizeVisitorTest/")
  {
    setResetType(ResetBasic);
  }

  void runTest(const QString inputFile, const int randomNumberGeneratorSeed,
               const double generalizeProbability, const double epsilon, const QString outputFile,
               const QString outputCompareFile, const bool enableDebugLogging = false)
  {
    Log::WarningLevel levelBefore = Log::getInstance().getLevel();
    if (enableDebugLogging)
    {
      Log::getInstance().setLevel(Log::Debug);
    }

    OsmMapPtr map(new OsmMap());
    if (_inputMapCache.contains(inputFile))
    {
      map.reset(new OsmMap(_inputMapCache[inputFile]));
    }
    else
    {
      OsmXmlReader reader;
      reader.setDefaultStatus(Status::Unknown1);
      reader.setUseDataSourceIds(true);
      reader.read(inputFile, map);
      if (!_inputMapCache.contains(inputFile))
      {
        OsmMapPtr newMap(new OsmMap(map));
        _inputMapCache[inputFile] = newMap;
      }
    }

    const int numNodesBefore = map->getNodes().size();
    LOG_VARD(numNodesBefore);
    const int numWaysBefore = map->getWays().size();
    LOG_VARD(numWaysBefore);

    MapProjector::projectToPlanar(map);
    PertyWayGeneralizeVisitor wayGeneralizeVisitor;
    boost::minstd_rand rng;
    rng.seed(randomNumberGeneratorSeed);
    wayGeneralizeVisitor.setRng(rng);
    wayGeneralizeVisitor.setWayGeneralizeProbability(generalizeProbability);
    wayGeneralizeVisitor.setEpsilon(epsilon);
    map->visitRw(wayGeneralizeVisitor);
    MapProjector::projectToWgs84(map);

    const int numNodesRemoved = numNodesBefore - map->getNodes().size();
    CPPUNIT_ASSERT_EQUAL(0, numNodesRemoved);
    LOG_VARD(numNodesRemoved);
    const int numWaysRemoved = numWaysBefore - map->getWays().size();
    CPPUNIT_ASSERT_EQUAL(0, numWaysRemoved);
    LOG_VARD(numWaysRemoved);

    OsmXmlWriter writer;
    writer.setIncludeHootInfo(true);
    writer.write(map, outputFile);

    HOOT_FILE_EQUALS(outputCompareFile, outputFile);

    if (enableDebugLogging)
    {
      Log::getInstance().setLevel(levelBefore);
    }
  }

  void runTest1()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.1,
      5.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-1.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-1.osm");
  }

  void runTest2()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.5,
      5.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-2.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-2.osm");
  }

  void runTest3()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      1.0,
      5.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-3.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-3.osm");
  }

  void runTest4()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.1,
      10.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-4.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-4.osm");
  }

  void runTest5()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.5,
      10.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-5.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-5.osm");
  }

  void runTest6()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      1.0,
      10.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-6.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-6.osm");
  }

  void runTest7()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.1,
      50.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-7.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-7.osm");
  }

  void runTest8()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      0.5,
      50.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-8.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-8.osm");
  }

  void runTest9()
  {
    runTest(
      _inputPath + "PertyWayGeneralizeVisitorTest-in-1.osm",
      1,
      1.0,
      50.0,
      _outputPath + "PertyWayGeneralizeVisitorTest-out-9.osm",
      _inputPath + "PertyWayGeneralizeVisitorTest-out-9.osm");
  }
};

//CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(PertyDuplicatePoiOpTest, "current");
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(PertyWayGeneralizeVisitorTest, "quick");

}
