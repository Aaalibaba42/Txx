#pragma once

#include "bits/concept.hh"
#include "bits/ops/fullsubtractor.hh"
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
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace SubImpl
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
        using result = Prepend_v<typename FS::Diff, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<Zero, R0, Borrow>;
        using tail =
            SubBigUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
        using result = Prepend_v<typename FS::Diff, tail>;
    };
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<L0, R0, Borrow>;
        using tail = SubBigUnsignedCarry_v<List<LRest...>, List<RRest...>,
                                           typename FS::Borrow>;
        using result = Prepend_v<typename FS::Diff, tail>;
    };

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Sub<LHS, RHS>;

    template <Bit_t... LHS, Bit_t... RHS>
    struct Sub<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = Canonicalize_v<ToBigUnsigned_v<
            SubBigUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>>;
    };
} // namespace SubImpl
