#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/meta/any.hh"

template <Any_t Elem, List_t List>
struct Append;

template <Any_t Elem, List_t List>
using Append_v = Append<Elem, List>::result;

template <Any_t Elem, Any_t... Rest>
struct Append<Elem, List<Rest...>>
{
    using result = List<Rest..., Elem>;
};
