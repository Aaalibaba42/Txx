#pragma once

#include "types/bits/concept.hh"

// lsb is first Bit (Little-endian)
//
// Underflowing will lead to undefined behavior
template <Bit_t Bit0, Bit_t Bit1, Bit_t Bit2, Bit_t Bit3, Bit_t Bit4,
          Bit_t Bit5, Bit_t Bit6, Bit_t Bit7>
struct Unsigned8
{};
