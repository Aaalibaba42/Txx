#pragma once

#include "types/list/concept.hh"
#include "types/meta/any.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/ops/sub.hh"

template <List_t L, Any_t Elem, Unsigned_t Position>
struct ListSet;

template <List_t L, Any_t Elem, Unsigned_t Position>
using ListSet_v = typename ListSet<L, Elem, Position>::result;

// List is empty
template <Any_t Elem, Unsigned_t Position>
struct ListSet<List<>, Elem, Position>
{
    static_assert(false, "ListSet: index out of bounds");
};

// We found the correct position
template <Any_t Head, Any_t... Tail, Any_t Elem>
struct ListSet<List<Head, Tail...>, Elem, Unsigned<>>
{
    using result = List<Elem, Tail...>;
};

// List is not empty, and position is not 0
template <Any_t Head, Any_t... Tail, Any_t Elem, Unsigned_t Position>
struct ListSet<List<Head, Tail...>, Elem, Position>
{
    using result = ListPrepend_v<
        Head,
        ListSet_v<List<Tail...>, Elem, UnsignedSub_v<Position, Unsigned<One>>>>;
};
