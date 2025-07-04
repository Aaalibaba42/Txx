#pragma once

#include "types/functions/function.hh"
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

    struct ListAppendFunc
    {
        using is_function = IsFunction;

        template <Any_t Elem, List_t List>
        struct apply
        {
            using result = ListAppend_v<Elem, List>;
        };
    };
} // namespace ListAppendImpl

using ListAppendImpl::ListAppendFunc;
using ListAppendImpl::ListAppend_v;
