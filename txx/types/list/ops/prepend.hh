#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/meta/any.hh"

template <Any_t Elem, List_t List>
struct Prepend;

template <Any_t Elem, List_t List>
using Prepend_v = Prepend<Elem, List>::result;

template <Any_t Elem, Any_t... Rest>
struct Prepend<Elem, List<Rest...>>
{
    using result = List<Elem, Rest...>;
};
