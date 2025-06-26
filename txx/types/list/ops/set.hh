#pragma once

#include "types/list/concept.hh"
#include "types/meta/any.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/ops/sub.hh"

template <List_t List, Any_t Elem, Unsigned_t Position>
struct Set;

template <List_t List, Any_t Elem, Unsigned_t Position>
using Set_v = typename Set<List, Elem, Position>::result;

// List is empty
template <Any_t Elem, Unsigned_t Position>
struct Set<List<>, Elem, Position>
{
    static_assert(false, "ListSet: index out of bounds");
};

// List is empty  and position is 0
// template <Any_t Elem>
// struct Set<List<>, Elem, Unsigned<>>
// {
//     using result = List<Elem>;
// };

// We found the correct position
template <Any_t Head, Any_t... Tail, Any_t Elem>
struct Set<List<Head, Tail...>, Elem, Unsigned<>>
{
    using result = List<Elem, Tail...>;
};

// List is not empty, and position is not 0
template <Any_t Head, Any_t... Tail, Any_t Elem, Unsigned_t Position>
struct Set<List<Head, Tail...>, Elem, Position>
{
    using result = Prepend_v<
        Head,
        Set_v<List<Tail...>, Elem, UnsignedSub_v<Position, Unsigned<One>>>>;
};
