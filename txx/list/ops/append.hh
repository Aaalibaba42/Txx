#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace AppendImpl
{
    template <Any_t Elem, Any_t List>
        requires List_t<List>
    struct Append<Elem, List>;

    template <Any_t Elem, Any_t... Rest>
    struct Append<Elem, List<Rest...>>
    {
        using result = List<Rest..., Elem>;
    };
} // namespace AppendImpl
