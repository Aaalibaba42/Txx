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

namespace BigUnsignedAddImpl
{
    template <List_t LHS, List_t RHS, Bit_t Carry>
    struct AddBigUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Carry>
    using AddBigUnsignedCarry_v = AddBigUnsignedCarry<LHS, RHS, Carry>::result;

    // Both Lists are empty, add the remaining carry
    template <Bit_t Carry>
    struct AddBigUnsignedCarry<List<>, List<>, Carry>
    {
        using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
    };

    // RHS is empty, propagate on LHS
    template <Bit_t L0, Bit_t... LRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<L0, LRest...>, List<>, Carry>
    {
        using FA = FullAdder<L0, Carry>;
        using tail =
            AddBigUnsignedCarry_v<List<LRest...>, List<>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    // LHS is empty, propagate on RHS
    template <Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<>, List<R0, RRest...>, Carry>
    {
        using FA = FullAdder<R0, Carry>;
        using tail =
            AddBigUnsignedCarry_v<List<>, List<RRest...>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    // Base case
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Carry>
    {
        using FA1 = FullAdder<L0, R0>;
        using FA2 = FullAdder<typename FA1::Sum, Carry>;

        using result_carry = FA1::Carry;
        using result_sum = FA2::Sum;
        using next_carry =
            FullAdder<typename FA1::Carry, typename FA2::Carry>::Sum;

        using tail =
            AddBigUnsignedCarry_v<List<LRest...>, List<RRest...>, next_carry>;
        using result = ListPrepend_v<result_sum, tail>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedAdd;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedAdd_v = BigUnsignedAdd<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedAdd<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = ToBigUnsigned_v<
            AddBigUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>;
    };
} // namespace BigUnsignedAddImpl

using BigUnsignedAddImpl::BigUnsignedAdd_v;
