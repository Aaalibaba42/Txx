#pragma once

#include "bits/concept.hh"
#include "bits/ops/fulladder.hh"
#include "casts/big_unsigned.hh"
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

namespace AddImpl
{
    template <List_t LHS, List_t RHS, Bit_t Carry>
    struct AddCarry;

    template <List_t LHS, List_t RHS, Bit_t Carry>
    using AddCarry_v = AddCarry<LHS, RHS, Carry>::result;

    // Both Lists are empty, add the remaining carry
    template <Bit_t Carry>
    struct AddCarry<List<>, List<>, Carry>
    {
        using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
    };

    // RHS is empty, propagate on LHS
    template <Bit_t L0, Bit_t... LRest, Bit_t Carry>
    struct AddCarry<List<L0, LRest...>, List<>, Carry>
    {
        using FA = FullAdder<L0, Carry>;
        using tail = AddCarry_v<List<LRest...>, List<>, typename FA::Carry>;
        using result = Prepend_v<typename FA::Sum, tail>;
    };

    // LHS is empty, propagate on RHS
    template <Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddCarry<List<>, List<R0, RRest...>, Carry>
    {
        using FA = FullAdder<R0, Carry>;
        using tail = AddCarry_v<List<>, List<RRest...>, typename FA::Carry>;
        using result = Prepend_v<typename FA::Sum, tail>;
    };

    // Base case
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddCarry<List<L0, LRest...>, List<R0, RRest...>, Carry>
    {
        using FA1 = FullAdder<L0, R0>;
        using FA2 = FullAdder<typename FA1::Sum, Carry>;

        using result_carry = FA1::Carry;
        using result_sum = FA2::Sum;
        using next_carry =
            FullAdder<typename FA1::Carry, typename FA2::Carry>::Sum;

        using tail = AddCarry_v<List<LRest...>, List<RRest...>, next_carry>;
        using result = Prepend_v<result_sum, tail>;
    };

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Add<LHS, RHS>;

    template <Bit_t... LHS, Bit_t... RHS>
    struct Add<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result =
            ToBigUnsigned_v<AddCarry_v<List<LHS...>, List<RHS...>, Zero>>;
    };
} // namespace AddImpl
