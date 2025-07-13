#pragma once

#include "bits/concept.hh"
#include "literals/bits.hh"

// lsb is first Bit (Little-endian)
//
// Underflowing will lead to undefined behavior
template <Bit_t Bit0 = Zero, Bit_t Bit1 = Zero, Bit_t Bit2 = Zero,
          Bit_t Bit3 = Zero, Bit_t Bit4 = Zero, Bit_t Bit5 = Zero,
          Bit_t Bit6 = Zero, Bit_t Bit7 = Zero>
struct Unsigned8
{};
