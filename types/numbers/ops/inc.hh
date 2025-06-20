#pragma once

#include "types/numbers/numbers.hh"
#include "types/bools/control_flow/if.hh"
#include "traits/is_same.hh"

#include "fulladder.hh"

template <typename Number, typename Carry = One>
struct IncImpl;

template <typename Carry>
struct IncImpl<Number<>, Carry>
{
    using result = If_v<is_same_v<Carry, One>, Number<One>, Number<>>;
};

template <typename Bit, typename... Rest, typename Carry>
struct IncImpl<Number<Bit, Rest...>, Carry>
{
    using FA = FullAdder<Bit, Carry>;
    using Tail = IncImpl<Number<Rest...>, typename FA::Carry>::result;
    using result = Number<typename FA::Sum, typename Tail::Bits...>;
};

template <typename... Bits>
struct Inc
{
    using result = IncImpl<Number<Bits...>>::result;
};

template <typename Number, typename Carry = One>
using Inc_v = Inc<Number, Carry>::result;
