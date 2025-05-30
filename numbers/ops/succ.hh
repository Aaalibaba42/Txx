#pragma once

#include "numbers/numbers.hh"

template <typename Number>
struct Succ;

template <typename Number>
using Succ_v = Succ<Number>::result;

// adds a 1 at the end if we add one
template <>
struct Succ<Number<>>
{
    using result = One;
};

template <>
struct Succ<Number<Zero>>
{
    using result = Number<One>;
};

template <typename... Bits>
struct Succ<Number<Zero, Bits...>>
{
    using result = Number<One, Bits...>;
};

template <typename... Bits>
struct Succ<Number<One, Bits...>>
{
    // FIXME This can't work, we need to extract the `Bits...` from Number, or
    // find another way to achieve this result
    using result = Number<Zero, Succ_v<Number<Bits...>>>;
};
