#pragma once

#include "bits/concept.hh"
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

namespace GtImpl
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

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Gt<LHS, RHS>;

    template <Bit_t... LHS, Bit_t... RHS>
    struct Gt<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<
            // If they are the same size
            IsSame_v<Length_v<LList>, Length_v<RList>>,
            // First One encountered from the end is biggest
            BigUnsignedGreaterThanImpl_v<Reverse_v<List<LHS...>>,
                                         Reverse_v<List<RHS...>>>,
            // The lengthiest number is the biggest
            GTImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace GtImpl
