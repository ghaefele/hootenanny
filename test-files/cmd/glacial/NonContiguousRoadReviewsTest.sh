#!/bin/bash
set -e

# See https://github.com/ngageoint/hootenanny/issues/586

mkdir -p $HOOT_HOME/tmp/
mkdir -p test-output/cmd/glacial/NonContiguousRoadReviewsTest

hoot conflate -C Testing.conf --warn -C ReferenceConflation.conf -C NetworkAlgorithm.conf \
 test-files/Congo_MGCP_Roads_Bridges_subset.osm \
 test-files/Congo_OSM_Roads_Bridges_subset.osm \
 test-output/cmd/glacial/NonContiguousRoadReviewsTest/output.osm

hoot diff test-output/cmd/glacial/NonContiguousRoadReviewsTest/output.osm \
          test-files/cmd/glacial/NonContiguousRoadReviewsTest/output.osm || \
     diff test-output/cmd/glacial/NonContiguousRoadReviewsTest/output.osm \
          test-files/cmd/glacial/NonContiguousRoadReviewsTest/output.osm
