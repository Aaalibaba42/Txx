#pragma once

#include "types/functions/ternary.hh"
#include "types/functions/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bits/ops/fullsubtractor.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/numbers/unsigned/bigunsigned/concept.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/numbers/unsigned/bigunsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/bigunsigned/utils/fromList.hh"

namespace BigUnsignedSubImpl
{
    template <List_t LHS, List_t RHS, Bit_t Borrow>
    struct SubBigUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Borrow>
    using SubBigUnsignedCarry_v = SubBigUnsignedCarry<LHS, RHS, Borrow>::result;

    template <Bit_t Borrow>
    struct SubBigUnsignedCarry<List<>, List<>, Borrow>
    {
        using result = Ternary_v<IsSame_v<Borrow, One>, List<>, List<>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<L0, LRest...>, List<>, Borrow>
    {
        using FS = FullSubtractor<L0, Zero, Borrow>;
        using tail =
            SubBigUnsignedCarry_v<List<LRest...>, List<>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<Zero, R0, Borrow>;
        using tail =
            SubBigUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<L0, R0, Borrow>;
        using tail = SubBigUnsignedCarry_v<List<LRest...>, List<RRest...>,
                                           typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedSub;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedSub_v = BigUnsignedSub<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedSub<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = BigUnsignedCanonicalize_v<ToBigUnsigned_v<
            SubBigUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>>;
    };

    struct BigUnsignedSubFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedSub_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedSubImpl

using BigUnsignedSubImpl::BigUnsignedSub_v;
using BigUnsignedSubImpl::BigUnsignedSubFunc;
