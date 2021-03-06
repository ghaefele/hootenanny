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
#ifndef ORCRITERION_H
#define ORCRITERION_H

#include <hoot/core/criterion/ChainCriterion.h>

namespace hoot
{

/**
 * Filters an element if any of the child criterion return true.
 */
class OrCriterion : public ChainCriterion
{
public:

  static std::string className() { return "hoot::OrCriterion"; }

  OrCriterion() {}
  OrCriterion(ElementCriterion* child1, ElementCriterion* child2) :
    ChainCriterion(child1, child2)
  {
  }
  OrCriterion(ElementCriterionPtr child1, ElementCriterionPtr child2) :
    ChainCriterion(child1, child2)
  {
  }

  virtual bool isSatisfied(const ConstElementPtr& e) const override;

  virtual ElementCriterionPtr clone()
  { return ElementCriterionPtr(new OrCriterion(_criteria[0]->clone(), _criteria[1]->clone())); }

  virtual QString getDescription() const { return "Allows for combining criteria (logical OR )"; }
};

}

#endif // ORCRITERION_H
