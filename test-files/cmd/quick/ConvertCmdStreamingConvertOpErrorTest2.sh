#!/bin/bash
set -e

rm -rf test-output/cmd/quick/ConvertCmdTest
mkdir -p test-output/cmd/quick/ConvertCmdTest

# pass in more than one convert op to a streaming convert; should get an error
hoot convert -D writer.xml.sort.by.id="false" -D convert.ops="hoot::PoiCriterion;hoot::BuildingCriterion" test-files/ToyTestA.osm.pbf test-output/cmd/quick/ConvertCmdTest/ToyTestA.osm
