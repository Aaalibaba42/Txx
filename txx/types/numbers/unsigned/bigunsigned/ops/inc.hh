#pragma once

#include "control_flow/ternary.hh"
#include "traits/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bits/ops/fulladder.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/numbers/unsigned/bigunsigned/concept.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/numbers/unsigned/bigunsigned/utils/fromList.hh"
#include "types/function/function.hh"

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
