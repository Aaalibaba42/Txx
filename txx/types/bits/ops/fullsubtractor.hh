#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"

// Some of these could be factorized, but it would be less explicit.
// This is more readable, doesn't hide the logic, and *shouldn't* lose much on
// compilation time nor template instantiation depth.

template <Bit_t LHS, Bit_t RHS, Bit_t Borrow>
struct FullSubtractor;

template <>
struct FullSubtractor<Zero, Zero, Zero>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<Zero, Zero, One>
{
    using Diff = One;
    using Borrow = One;
};

template <>
struct FullSubtractor<Zero, One, Zero>
{
    using Diff = One;
    using Borrow = One;
};

template <>
struct FullSubtractor<Zero, One, One>
{
    using Diff = Zero;
    using Borrow = One;
};

template <>
struct FullSubtractor<One, Zero, Zero>
{
    using Diff = One;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, Zero, One>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, One, Zero>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, One, One>
{
    using Diff = One;
    using Borrow = One;
};
