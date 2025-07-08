#pragma once

#include "bits/concept.hh"
#include "bits/ops/fulladder.hh"
#include "functions/function.hh"
#include "functions/is_same.hh"
#include "functions/ternary.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/utils/fromList.hh"

namespace BigUnsignedIncImpl
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

        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <BigUnsigned_t Num>
    struct BigUnsignedInc;

    template <BigUnsigned_t Num>
    using BigUnsignedInc_v = BigUnsignedInc<Num>::result;

    template <Bit_t... Bits>
    struct BigUnsignedInc<BigUnsigned<Bits...>>
    {
        using result = ToBigUnsigned_v<AddCarry_v<List<Bits...>, One>>;
    };

    struct BigUnsignedIncFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t Num>
        struct apply
        {
            using result = BigUnsignedInc_v<Num>;
        };
    };
} // namespace BigUnsignedIncImpl

using BigUnsignedIncImpl::BigUnsignedInc_v;
using BigUnsignedIncImpl::BigUnsignedIncFunc;
