#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/meta/any.hh"

template <Any_t Elem, List_t List>
struct ListPrepend;

template <Any_t Elem, List_t List>
using ListPrepend_v = ListPrepend<Elem, List>::result;

template <Any_t Elem, Any_t... Rest>
struct ListPrepend<Elem, List<Rest...>>
{
    using result = List<Elem, Rest...>;
};
