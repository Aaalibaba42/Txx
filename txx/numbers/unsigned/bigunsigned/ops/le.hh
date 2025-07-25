#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "functions/base/ternary.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "list/ops/reverse.hh"
#include "literals/bits.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace LeImpl
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

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Le<LHS, RHS>;

    template <Bit_t... LHS, Bit_t... RHS>
    struct Le<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<Length_v<LList>, Length_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedLowerEqImpl_v<Reverse_v<List<LHS...>>,
                                     Reverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            LEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace LeImpl
