#pragma once

#include "types/bits/concept.hh"

// lsb is first Bit (Big-endian)
//
// Range of definition is [0; +inf[
//
// Underflowing will lead to undefined behavior
//
// Upper bound of definition is limited by the compiler's template instantiation
// limits
template <Bit_t... BitPack>
struct Unsigned
{};
