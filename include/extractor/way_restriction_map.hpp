#ifndef OSRM_EXTRACTOR_WAY_RESTRICTION_MAP_HPP_
#define OSRM_EXTRACTOR_WAY_RESTRICTION_MAP_HPP_

#include <utility>
#include <vector>

// to access the turn restrictions
#include <boost/unordered_map.hpp>

#include "extractor/restriction.hpp"
#include "util/typedefs.hpp"

// Given the compressed representation of via-way turn restrictions, we provide a fast access into
// the restrictions to indicate which turns may be restricted due to a way in between
namespace osrm
{
namespace extractor
{

class WayRestrictionMap
{
  public:
    WayRestrictionMap(const std::vector<TurnRestriction> &turn_restrictions);

    // check if an edge between two nodes is a restricted turn
    bool IsStart(const NodeID from, const NodeID to) const;
    bool IsEnd(const NodeID from, const NodeID to) const;

  private:
    // acces to the turn restrictions based on the via way they use
    boost::unordered_multimap<std::pair<NodeID, NodeID>, std::size_t> restriction_starts;
    boost::unordered_multimap<std::pair<NodeID, NodeID>, std::size_t> restriction_ends;
};

} // namespace extractor
} // namespace osrm

#endif // OSRM_EXTRACTOR_WAY_RESTRICTION_MAP_HPP_
