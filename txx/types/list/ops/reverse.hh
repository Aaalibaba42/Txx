#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/meta/any.hh"

template <List_t In, List_t Acc = List<>>
struct Reverse;

template <List_t In, List_t Acc = List<>>
using Reverse_v = Reverse<In, Acc>::result;

template <List_t Acc>
struct Reverse<List<>, Acc>
{
    using result = Acc;
};

template <Any_t Head, Any_t... Tail, List_t Acc>
struct Reverse<List<Head, Tail...>, Acc>
{
    using result = Reverse_v<List<Tail...>, Prepend_v<Head, Acc>>;
};
