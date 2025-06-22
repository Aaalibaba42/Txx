#pragma once

#include "types/list/list.hh"

// lsb is first Bit (should make comparisons way easier, since it the same
// offset boths sides for bits of same significance)
template <typename... BitPack>
struct Unsigned
{
    // Not particularly elegant, but had to do it to get back the template
    // arguments
    using Bits = TypeList<BitPack...>;
};
