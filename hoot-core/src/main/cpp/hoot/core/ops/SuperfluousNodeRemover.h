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

#ifndef SUPERFLUOUSNODEREMOVER_H
#define SUPERFLUOUSNODEREMOVER_H

// GEOS
#include <geos/geom/Envelope.h>

// Hoot
#include <hoot/core/util/Units.h>
#include <hoot/core/io/Serializable.h>
#include <hoot/core/ops/Boundable.h>
#include <hoot/core/ops/OsmMapOperation.h>
#include <hoot/core/info/OperationStatusInfo.h>

// Standard
#include <set>

namespace hoot
{

class OsmMap;

/**
 * Removes all the nodes from a map that aren't part of a way.
 *
 * If the bounds have been set via Boundable's setBounds then only nodes that are both not part
 * of a way and inside the bounds will be removed. This is most useful when performing tile based
 * operations such as the FourPassDriver.
 */
class SuperfluousNodeRemover : public OsmMapOperation, public Serializable, public Boundable,
  public OperationStatusInfo
{
public:

  static std::string className() { return "hoot::SuperfluousNodeRemover"; }

  SuperfluousNodeRemover();

  virtual void apply(std::shared_ptr<OsmMap>& map);

  virtual std::string getClassName() const { return className(); }

  virtual void readObject(QDataStream& is);

  static std::shared_ptr<OsmMap> removeNodes(const std::shared_ptr<const OsmMap>& map);

  static void removeNodes(std::shared_ptr<OsmMap>& map, const geos::geom::Envelope& e);

  virtual void setBounds(const geos::geom::Envelope &bounds);

  virtual void writeObject(QDataStream& os) const;

  virtual QString getDescription() const { return "Removes all nodes not part of a way"; }

  virtual QString getInitStatusMessage() const { return "Removing superfluous nodes..."; }

  virtual QString getCompletedStatusMessage() const
  { return "Removed " + QString::number(_numAffected) + " superfluous nodes"; }

protected:

  geos::geom::Envelope _bounds;
  std::set<long> _usedNodes;
};

}

#endif // SUPERFLUOUSNODEREMOVER_H
