#pragma once

#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace ListPrependImpl
{
    template <Any_t Elem, List_t L>
    struct ListPrepend;

    template <Any_t Elem, List_t L>
    using ListPrepend_v = ListPrepend<Elem, L>::result;

    template <Any_t Elem, Any_t... Rest>
    struct ListPrepend<Elem, List<Rest...>>
    {
        using result = List<Elem, Rest...>;
    };

    struct ListPrependFunc
    {
        using is_function = IsFunction;

        template <Any_t Elem, List_t L>
        struct apply
        {
            using result = ListPrepend_v<Elem, L>;
        };
    };
} // namespace ListPrependImpl

using ListPrependImpl::ListPrependFunc;
using ListPrependImpl::ListPrepend_v;
