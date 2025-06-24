#pragma once

#include "types/bits/concept.hh"

// lsb is first Bit (should make comparisons way easier, since it the same
// offset boths sides for bits of same significance)
template <Bit_t... BitPack>
struct Unsigned
{};
