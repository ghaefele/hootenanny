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
 * @copyright Copyright (C) 2015, 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */
#ifndef BUILDINGMERGER_H
#define BUILDINGMERGER_H

// hoot
#include <hoot/core/conflate/merging/MergerBase.h>

// Standard
#include <set>

namespace hoot
{

/**
 * Merges two buildings
 */
class BuildingMerger : public MergerBase
{
public:

  static std::string className() { return "hoot::BuildingMerger"; }

  static int logWarnCount;

  BuildingMerger();
  /**
   * Constructed with a set of element matching pairs. The pairs are generally Unknown1 as first
   * and Unknown2 as second.
   */
  explicit BuildingMerger(const std::set<std::pair<ElementId, ElementId>>& pairs);

  virtual void apply(const OsmMapPtr& map, std::vector<std::pair<ElementId, ElementId>>& replaced) override;

  /**
   * Creates a single building out of a group of buildings
   *
   * @param map map which owns the buildings being combined
   * @param eids element IDs for the buildings to combine
   * @param preserveTypes if true, differing building type tags will be preserved in the assembled
   * building relation
   * @return a building element
   */
  static std::shared_ptr<Element> buildBuilding(const OsmMapPtr& map,
                                                const std::set<ElementId>& eids,
                                                const bool preserveTypes = false);

  virtual QString toString() const override;

  /**
   * Utility method that allows for merging an unlimited number of buildings
   *
   * The map passed may or may not contain constituent elements (way nodes, relation members).
   *
   * @param map a map containing the buildings to be merged
   * @param mergeTargetId the ID of the building which all other buildings should be merged into
   */
  static void mergeBuildings(OsmMapPtr map, const ElementId& mergeTargetId);

  virtual QString getDescription() const { return "Merges buildings"; }

  void setKeepMoreComplexGeometryWhenAutoMerging(bool keepMoreComplex)
  { _keepMoreComplexGeometryWhenAutoMerging = keepMoreComplex; }
  void setMergeManyToManyMatches(bool merge) { _mergeManyToManyMatches = merge; }

protected:

  virtual PairsSet& _getPairs() override { return _pairs; }
  virtual const PairsSet& _getPairs() const override { return _pairs; }

private:

  std::set<std::pair<ElementId, ElementId>> _pairs;

  //If true, merging always keeps the more complex of the two building geometries.  If false,
  //merging keeps the geometry of the reference building.
  bool _keepMoreComplexGeometryWhenAutoMerging;
  // The default behavior is to review many to many matches. Setting this to true allows them to
  // all be merged together.
  bool _mergeManyToManyMatches;
  // set to true if the current building merge involves two buildings, each part of multiple matches
  bool _manyToManyMatch;

  /*
   * Creates a building out of the current set of building element IDs
   *
   * @param map map which owns the buildings being combined
   * @param unknown1 if true, elements with unknown1 status are assembled into a building; if false,
   * then buildings with unknown2 status are assembled
   * @return a building element
   */
  std::shared_ptr<Element> _buildBuilding(const OsmMapPtr& map, const bool unknown1) const;

  QSet<ElementId> _getMultiPolyMemberIds(const ConstElementPtr& element) const;

  void _removeRedundantAltTypeTags(Tags& tags);
};

}

#endif // BUILDINGMERGER_H
