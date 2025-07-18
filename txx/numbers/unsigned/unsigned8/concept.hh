#pragma once

#include "bits/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace Unsigned8TImpl
{
    template <Bit_t Bit0, Bit_t Bit1, Bit_t Bit2, Bit_t Bit3, Bit_t Bit4,
              Bit_t Bit5, Bit_t Bit6, Bit_t Bit7>
    void unsigned8_t_stub(
        Unsigned8<Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7>);

    template <typename T>
    concept Unsigned8_t = requires(T us) {
        { unsigned8_t_stub(us) };
    };
} // namespace Unsigned8TImpl

using Unsigned8TImpl::Unsigned8_t;
