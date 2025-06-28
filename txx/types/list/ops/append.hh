#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/meta/any.hh"

namespace ListAppendImpl
{
    template <Any_t Elem, List_t List>
    struct ListAppend;

    template <Any_t Elem, List_t List>
    using ListAppend_v = ListAppend<Elem, List>::result;

    template <Any_t Elem, Any_t... Rest>
    struct ListAppend<Elem, List<Rest...>>
    {
        using result = List<Rest..., Elem>;
    };
} // namespace ListAppendImpl

using ListAppendImpl::ListAppend_v;
