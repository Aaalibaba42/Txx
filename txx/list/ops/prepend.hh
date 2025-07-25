#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace PrependImpl
{
    template <Any_t Elem, Any_t L>
        requires List_t<L>
    struct Prepend<Elem, L>;

    template <Any_t Elem, Any_t... Rest>
    struct Prepend<Elem, List<Rest...>>
    {
        using result = List<Elem, Rest...>;
    };
} // namespace PrependImpl
