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
struct UnsignedGreaterThanImpl;

template <List_t LHS, List_t RHS>
using UnsignedGreaterThanImpl_v = UnsignedGreaterThanImpl<LHS, RHS>::result;

template <>
struct UnsignedGreaterThanImpl<List<>, List<>>
{
    using result = False;
};

template <Bit_t... RRest>
struct UnsignedGreaterThanImpl<List<>, List<RRest...>>
{
    using result = False;
};

template <Bit_t... LRest>
struct UnsignedGreaterThanImpl<List<LRest...>, List<>>
{
    using result = True;
};

template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
struct UnsignedGreaterThanImpl<List<SameBit, LRest...>, List<SameBit, RRest...>>
{
    using result = UnsignedGreaterThanImpl_v<List<LRest...>, List<RRest...>>;
};

template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
struct UnsignedGreaterThanImpl<List<L0, LRest...>, List<R0, RRest...>>
{
    // The LHS is greater than RHS if LHS has the One (thus RHS has the Zero)
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

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedGT;

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedGT_v = UnsignedGT<LHS, RHS>::result;

template <Bit_t... LHS, Bit_t... RHS>
struct UnsignedGT<Unsigned<LHS...>, Unsigned<RHS...>>
{
    using LList = List<LHS...>;
    using RList = List<RHS...>;
    using result = Ternary_v<
        // If they are the same size
        IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,
        // First One encountered from the end is biggest
        UnsignedGreaterThanImpl_v<ListReverse_v<List<LHS...>>,
                                  ListReverse_v<List<RHS...>>>,
        // The lengthiest number is the biggest
        GTImplIsLHSLongest_v<LList, RList>>;
};
