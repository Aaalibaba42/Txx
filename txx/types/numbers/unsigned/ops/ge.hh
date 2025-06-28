#pragma once

#include "traits/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bools/literals.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/length.hh"
#include "types/list/ops/reverse.hh"
#include "types/numbers/unsigned/concept.hh"

namespace UnsignedGEImpl
{
    template <List_t LHS, List_t RHS>
    struct UnsignedGreaterEqImpl;

    template <List_t LHS, List_t RHS>
    using UnsignedGreaterEqImpl_v = UnsignedGreaterEqImpl<LHS, RHS>::result;

    template <>
    struct UnsignedGreaterEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct UnsignedGreaterEqImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<SameBit, LRest...>,
                                 List<SameBit, RRest...>>
    {
        using result = UnsignedGreaterEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<L0, LRest...>, List<R0, RRest...>>
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

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedGE;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedGE_v = UnsignedGE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedGE<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
            // First One encountered from the end is biggest
            UnsignedGreaterEqImpl_v<ListReverse_v<List<LHS...>>,
                                    ListReverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            GEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace UnsignedGEImpl

using UnsignedGEImpl::UnsignedGE_v;
