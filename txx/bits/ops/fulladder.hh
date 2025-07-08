#pragma once

#include "bits/concept.hh"
#include "bits/literals.hh"

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

    // TODO: This would need to return a Tuple to be made a function

} // namespace FullAdderImpl

using FullAdderImpl::FullAdder;
