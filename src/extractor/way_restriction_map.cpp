#include "extractor/way_restriction_map.hpp"

namespace osrm
{
namespace extractor
{

WayRestrictionMap::WayRestrictionMap(const std::vector<TurnRestriction> &turn_restrictions)
{
    // map all way restrictions into access containers
    const auto prepare_way_restriction = [this](const auto &restriction) {
        if (restriction.Type() != RestrictionType::WAY_RESTRICTION)
            return;

        const auto &way = restriction.AsWayRestriction();
        restriction_starts.insert(
            std::make_pair(std::make_pair(way.in_restriction.via, way.in_restriction.to), 0));
        restriction_ends.insert(
            std::make_pair(std::make_pair(way.out_restriction.from, way.out_restriction.via), 0));
    };
    std::for_each(turn_restrictions.begin(), turn_restrictions.end(), prepare_way_restriction);
}

// check if an edge between two nodes is a restricted turn
bool WayRestrictionMap::IsStart(const NodeID from, const NodeID to) const
{
    return restriction_starts.count(std::make_pair(from, to)) > 0;
}
bool WayRestrictionMap::IsEnd(const NodeID from, const NodeID to) const
{
    return restriction_ends.count(std::make_pair(from, to)) > 0;
}

} // namespace extractor
} // namespace osrm
