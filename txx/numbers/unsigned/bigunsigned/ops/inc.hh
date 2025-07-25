#pragma once

#include "bits/concept.hh"
#include "bits/ops/fulladder.hh"
#include "casts/big_unsigned.hh"
#include "casts/list.hh"
#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "functions/base/ternary.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace IncImpl
{
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

    template <Any_t Num>
        requires BigUnsigned_t<Num>
    struct Inc<Num>;

    template <Bit_t... Bits>
    struct Inc<BigUnsigned<Bits...>>
    {
        using result = ToBigUnsigned_v<AddCarry_v<List<Bits...>, One>>;
    };

    template <>
    struct Inc<BigUnsigned<>>
    {
        using result = BigUnsigned<One>;
    };
} // namespace IncImpl
