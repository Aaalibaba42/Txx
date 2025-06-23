#pragma once

#include "control_flow/ternary.hh"
#include "traits/is_same.hh"
#include "types/bits/ops/fulladder.hh"
#include "types/list/ops/prepend.hh"
#include "types/numbers/unsigned/casts/fromList.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/unsigned.hh"

template <List_t List, Bit_t Carry>
struct AddCarry;

template <List_t List, Bit_t Carry>
using AddCarry_v = AddCarry<List, Carry>::result;

template <Bit_t Carry>
struct AddCarry<List<>, Carry>
{
    using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
};

template <Bit_t Curr, Bit_t... Rest, Bit_t Carry>
struct AddCarry<List<Curr, Rest...>, Carry>
{
    using FA = FullAdder<Curr, Carry>;

    using tail = AddCarry_v<List<Rest...>, typename FA::Carry>;

    using result = Prepend_v<typename FA::Sum, tail>;
};

template <Unsigned_t Num>
struct UnsignedInc;

template <Unsigned_t Num>
using UnsignedInc_v = UnsignedInc<Num>::result;

template <Bit_t... Bits>
struct UnsignedInc<Unsigned<Bits...>>
{
    using result = ToUnsigned_v<AddCarry_v<List<Bits...>, One>>;
};
