#pragma once

#include "functions/is_same.hh"
#include "bits/concept.hh"
#include "literals/bits.hh"
#include "literals/bools.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "functions/function.hh"
#include "functions/ternary.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "list/ops/length.hh"
#include "list/ops/reverse.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace BigUnsignedGTImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedGreaterThanImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedGreaterThanImpl_v =
        BigUnsignedGreaterThanImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedGreaterThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct BigUnsignedGreaterThanImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<SameBit, LRest...>,
                                      List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedGreaterThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        // The LHS is greater than RHS if LHS has the One (thus RHS has the
        // Zero)
        using result = IsSame_v<L0, One>;
    };

    template <List_t LHS, List_t RHS>
    struct GTImplIsRHSLongest;

    template <List_t LHS, List_t RHS>
    using GTImplIsLHSLongest_v = GTImplIsRHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct GTImplIsRHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = GTImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct GTImplIsRHSLongest<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct GTImplIsRHSLongest<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct GTImplIsRHSLongest<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedGT;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedGT_v = BigUnsignedGT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedGT<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedGreaterThanImpl_v<ListReverse_v<List<LHS...>>,
                                         ListReverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            GTImplIsLHSLongest_v<LList, RList>>;
    };

    struct BigUnsignedGTFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedGT_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedGTImpl

using BigUnsignedGTImpl::BigUnsignedGTFunc;
using BigUnsignedGTImpl::BigUnsignedGT_v;
