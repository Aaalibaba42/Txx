#pragma once

#include "types/list/concept.hh"
#include "types/meta/any.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/numbers/unsigned/ops/inc.hh"

template <List_t L>
struct ListLength;

template <List_t L>
using ListLength_v = typename ListLength<L>::result;

template <>
struct ListLength<List<>>
{
    using result = Unsigned<>;
};

template <Any_t Head, Any_t... Tail>
struct ListLength<List<Head, Tail...>>
{
    using result = UnsignedInc_v<ListLength_v<List<Tail...>>>;
};
