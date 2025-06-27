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
struct UnsignedLowerEqImpl;

template <List_t LHS, List_t RHS>
using UnsignedLowerEqImpl_v = UnsignedLowerEqImpl<LHS, RHS>::result;

template <>
struct UnsignedLowerEqImpl<List<>, List<>>
{
    using result = True;
};

template <Bit_t... RRest>
struct UnsignedLowerEqImpl<List<>, List<RRest...>>
{
    using result = True;
};

template <Bit_t... LRest>
struct UnsignedLowerEqImpl<List<LRest...>, List<>>
{
    using result = False;
};

template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
struct UnsignedLowerEqImpl<List<SameBit, LRest...>, List<SameBit, RRest...>>
{
    using result = UnsignedLowerEqImpl_v<List<LRest...>, List<RRest...>>;
};

template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
struct UnsignedLowerEqImpl<List<L0, LRest...>, List<R0, RRest...>>
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

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedLE;

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedLE_v = UnsignedLE<LHS, RHS>::result;

template <Bit_t... LHS, Bit_t... RHS>
struct UnsignedLE<Unsigned<LHS...>, Unsigned<RHS...>>
{
    using LList = List<LHS...>;
    using RList = List<RHS...>;
    using result = Ternary_v<
        // If they are the same size
        IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
        // First One encountered from the end is biggest
        UnsignedLowerEqImpl_v<ListReverse_v<List<LHS...>>,
                              ListReverse_v<List<RHS...>>>,
        // The lengthiest number is the biggest
        LEImplIsLHSLongest_v<LList, RList>>;
};
