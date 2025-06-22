#pragma once

#include "control_flow/ternary.hh"
#include "traits/is_same.hh"
#include "types/bits/ops/fulladder.hh"
#include "types/list/ops/prepend.hh"
#include "types/numbers/unsigned/casts/fromList.hh"
#include "types/numbers/unsigned/unsigned.hh"

template <typename List, typename Carry>
struct AddCarry;

template <typename Carry>
struct AddCarry<TypeList<>, Carry>
{
    using result = Ternary_v<IsSame_v<Carry, One>, TypeList<One>, TypeList<>>;
};

template <typename Curr, typename... Rest, typename Carry>
struct AddCarry<TypeList<Curr, Rest...>, Carry>
{
    using FA = FullAdder<Curr, Carry>;

    using tail =
        typename AddCarry<TypeList<Rest...>, typename FA::Carry>::result;

    using result = Prepend_v<typename FA::Sum, tail>;
};

template <typename Num>
struct UnsignedInc;

template <typename... Bits>
struct UnsignedInc<Unsigned<Bits...>>
{
    using result =
        ToUnsigned_v<typename AddCarry<TypeList<Bits...>, One>::result>;
};
template <typename Num>
using UnsignedInc_v = UnsignedInc<Num>::result;
