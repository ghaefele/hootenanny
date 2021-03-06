#!/bin/bash
set -e

mkdir -p test-output/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest
cp test-files/DcTigerRoads.osm test-files/DcTigerRoadsHighwayExactMatchInputs.osm

hoot conflate -C Testing.conf -D match.creators="hoot::HighwayMatchCreator" -D merger.creators="hoot::HighwayMergerCreator" -D "writer.include.debug.tags=true" -D "writer.include.conflate.score.tags=true" -D "uuid.helper.repeatable=true" test-files/DcTigerRoads.osm test-files/DcTigerRoadsHighwayExactMatchInputs.osm test-output/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest/output.osm

hoot diff test-output/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest/output.osm test-files/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest/output.osm || diff test-output/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest/output.osm test-files/cmd/glacial/ConflateCmdHighwayExactMatchInputsTest/output.osm
