#pragma once

#include "functions/is_same.hh"
#include "bits/concept.hh"
#include "bits/literals.hh"
#include "bools/literals.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "list/ops/reverse.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace BigUnsignedGEImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedGreaterEqImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedGreaterEqImpl_v =
        BigUnsignedGreaterEqImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedGreaterEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct BigUnsignedGreaterEqImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<SameBit, LRest...>,
                                    List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedGreaterEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        // The LHS is greater than RHS if LHS has the One (thus RHS has the
        // Zero)
        using result = IsSame_v<L0, One>;
    };

    template <List_t LHS, List_t RHS>
    struct GEImplIsRHSLongest;

    template <List_t LHS, List_t RHS>
    using GEImplIsLHSLongest_v = GEImplIsRHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct GEImplIsRHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = GEImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct GEImplIsRHSLongest<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct GEImplIsRHSLongest<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct GEImplIsRHSLongest<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedGE;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedGE_v = BigUnsignedGE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedGE<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedGreaterEqImpl_v<ListReverse_v<List<LHS...>>,
                                       ListReverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            GEImplIsLHSLongest_v<LList, RList>>;
    };

    struct BigUnsignedGEFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedGE_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedGEImpl

using BigUnsignedGEImpl::BigUnsignedGE_v;
using BigUnsignedGEImpl::BigUnsignedGEFunc;
