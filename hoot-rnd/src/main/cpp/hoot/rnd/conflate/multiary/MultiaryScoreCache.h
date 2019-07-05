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
#ifndef __MULTIARY_SCORE_CACHE_H__
#define __MULTIARY_SCORE_CACHE_H__

// hoot
#include <hoot/core/conflate/matching/MatchCreator.h>
#include <hoot/core/conflate/merging/MergerBase.h>
#include <hoot/rnd/conflate/multiary/MultiaryCluster.h>

namespace hoot
{

/**
 * Scores two elements or clusters using a provided MatchCreator for the scoring.
 *
 * @todo At this point scores are not cached.
 */
class MultiaryScoreCache
{
public:

  /**
   * @brief MultiaryScoreCache
   * @param map Map that contains the original elements to score.
   * @param matchCreator The MatchCreator that will be used for scoring.
   */
  MultiaryScoreCache(const ConstOsmMapPtr& map, const std::shared_ptr<MatchCreator>& matchCreator);

  /**
   * Return the explain text that was generated by the Match during the last scoring.
   */
  QString getLastExplainText() const { return _lastExplainText; }

  /**
   * Return the score between the two merged clusters. If any pair of the elements is explicity
   * a miss between c1 & c2 a hard miss is returned.
   */
  MatchClassification getScore(MultiaryClusterPtr c1, MultiaryClusterPtr c2);

  /**
   * Calculate the score between e1 and e2. If the MatchCreator returns no match a hard miss is
   * returned.
   */
  MatchClassification getScore(ConstElementPtr e1, ConstElementPtr e2);

private:

  QString _lastExplainText;
  ConstOsmMapPtr _map;
  std::shared_ptr<MatchCreator> _matchCreator;
};

typedef std::shared_ptr<MultiaryScoreCache> MultiaryScoreCachePtr;

}

#endif // __MULTIARY_SCORE_CACHE_H__
