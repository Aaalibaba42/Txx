#pragma once

#include "types/numbers/numbers.hh"
#include "control_flow/if.hh"
#include "traits/is_same.hh"
#include "types/numbers/ops/fulladder.hh"
#include "types/numbers/casts/fromList.hh"
#include "types/list/ops/prepend.hh"

template <typename List, typename Carry>
struct AddCarry;

template <typename Carry>
struct AddCarry<TypeList<>, Carry>
{
    using result = If_v<IsSame_v<Carry, One>, TypeList<One>, TypeList<>>;
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
struct Inc;

template <typename... Bits>
struct Inc<Number<Bits...>>
{
    using result =
        ToNumber_v<typename AddCarry<TypeList<Bits...>, One>::result>;
};
template <typename Num>
using Inc_v = Inc<Num>::result;
