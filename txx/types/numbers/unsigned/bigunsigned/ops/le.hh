#pragma once

#include "traits/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bools/literals.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/length.hh"
#include "types/list/ops/reverse.hh"
#include "types/numbers/unsigned/bigunsigned/concept.hh"

namespace BigUnsignedLEImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedLowerEqImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedLowerEqImpl_v = BigUnsignedLowerEqImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedLowerEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct BigUnsignedLowerEqImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<SameBit, LRest...>,
                                  List<SameBit, RRest...>>
    {
        using result = BigUnsignedLowerEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        // The LHS is lower than RHS if LHS has the Zero (thus RHS has the One)
        using result = IsSame_v<L0, Zero>;
    };

    template <List_t LHS, List_t RHS>
    struct LEImplIsLHSLongest;

    template <List_t LHS, List_t RHS>
    using LEImplIsLHSLongest_v = LEImplIsLHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct LEImplIsLHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = LEImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct LEImplIsLHSLongest<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct LEImplIsLHSLongest<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct LEImplIsLHSLongest<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedLE;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedLE_v = BigUnsignedLE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedLE<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedLowerEqImpl_v<ListReverse_v<List<LHS...>>,
                                     ListReverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            LEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace BigUnsignedLEImpl

using BigUnsignedLEImpl::BigUnsignedLE_v;
