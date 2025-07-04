#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"

namespace FullAdderImpl
{
    template <Bit_t Bit, Bit_t Carry>
    struct FullAdder;

    template <>
    struct FullAdder<Zero, Zero>
    {
        using Sum = Zero;
        using Carry = Zero;
    };

    template <>
    struct FullAdder<Zero, One>
    {
        using Sum = One;
        using Carry = Zero;
    };

    template <>
    struct FullAdder<One, Zero>
    {
        using Sum = One;
        using Carry = Zero;
    };

    template <>
    struct FullAdder<One, One>
    {
        using Sum = Zero;
        using Carry = One;
    };
} // namespace FullAdderImpl

using FullAdderImpl::FullAdder;
