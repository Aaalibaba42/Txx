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

template <List_t LHS, List_t RHS>
struct UnsignedLowerThanImpl;

template <List_t LHS, List_t RHS>
using UnsignedLowerThanImpl_v = UnsignedLowerThanImpl<LHS, RHS>::result;

template <>
struct UnsignedLowerThanImpl<List<>, List<>>
{
    using result = False;
};

template <Bit_t... RRest>
struct UnsignedLowerThanImpl<List<>, List<RRest...>>
{
    using result = True;
};

template <Bit_t... LRest>
struct UnsignedLowerThanImpl<List<LRest...>, List<>>
{
    using result = False;
};

template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
struct UnsignedLowerThanImpl<List<SameBit, LRest...>, List<SameBit, RRest...>>
{
    using result = UnsignedLowerThanImpl_v<List<LRest...>, List<RRest...>>;
};

template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
struct UnsignedLowerThanImpl<List<L0, LRest...>, List<R0, RRest...>>
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

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedLT;

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedLT_v = UnsignedLT<LHS, RHS>::result;

template <Bit_t... LHS, Bit_t... RHS>
struct UnsignedLT<Unsigned<LHS...>, Unsigned<RHS...>>
{
    using LList = List<LHS...>;
    using RList = List<RHS...>;
    using result = Ternary_v<
        // If they are the same size
        IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
        // First One encountered from the end is biggest
        UnsignedLowerThanImpl_v<ListReverse_v<List<LHS...>>,
                                ListReverse_v<List<RHS...>>>,
        // The lengthiest number is the biggest
        LTImplIsLHSLongest_v<LList, RList>>;
};
