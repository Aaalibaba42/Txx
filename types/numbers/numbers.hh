#pragma once

#include "types/list/list.hh"

struct Zero
{};
struct One
{};

// lsb is first Bit (should make comparisons way easier, since it the same
// offset boths sides for bits of same significance)
template <typename... BitPack>
struct Number
{
    using Bits = TypeList<BitPack...>;
};
