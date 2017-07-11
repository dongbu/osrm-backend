#include "util/guidance/entry_class.hpp"

#include <boost/assert.hpp>

#include <climits>

namespace osrm
{
namespace util
{
namespace guidance
{

void EntryClass::activate(std::uint32_t index)
{
    BOOST_ASSERT(index < CHAR_BIT * sizeof(FlagBaseType));
    enabled_entries_flags |= (FlagBaseType{1} << index);
}

bool EntryClass::allowsEntry(std::uint32_t index) const
{
    BOOST_ASSERT(index < CHAR_BIT * sizeof(FlagBaseType));
    return 0 != (enabled_entries_flags & (FlagBaseType{1} << index));
}

bool EntryClass::operator==(const EntryClass &other) const
{
    return enabled_entries_flags == other.enabled_entries_flags;
}

bool EntryClass::operator<(const EntryClass &other) const
{
    return enabled_entries_flags < other.enabled_entries_flags;
}

} // namespace guidance
} // namespace extractor
} // namespace osrm
