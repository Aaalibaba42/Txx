#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "functions/is_same.hh"
#include "functions/ternary.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "list/ops/reverse.hh"
#include "literals/bits.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace BigUnsignedLTImpl
{

    template <List_t LHS, List_t RHS>
    struct BigUnsignedLowerThanImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedLowerThanImpl_v =
        BigUnsignedLowerThanImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedLowerThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct BigUnsignedLowerThanImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<SameBit, LRest...>,
                                    List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedLowerThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        // The LHS is lower than RHS if LHS has the Zero (thus RHS has the One)
        using result = IsSame_v<L0, Zero>;
    };

    template <List_t LHS, List_t RHS>
    struct LTImplIsLHSLongest;

    template <List_t LHS, List_t RHS>
    using LTImplIsLHSLongest_v = LTImplIsLHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct LTImplIsLHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = LTImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct LTImplIsLHSLongest<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct LTImplIsLHSLongest<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct LTImplIsLHSLongest<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedLT;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedLT_v = BigUnsignedLT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedLT<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedLowerThanImpl_v<ListReverse_v<List<LHS...>>,
                                       ListReverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            LTImplIsLHSLongest_v<LList, RList>>;
    };

    struct BigUnsignedLTFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedLT_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedLTImpl

using BigUnsignedLTImpl::BigUnsignedLT_v;
using BigUnsignedLTImpl::BigUnsignedLTFunc;
