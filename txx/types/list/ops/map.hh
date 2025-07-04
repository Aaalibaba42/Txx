#pragma once

#include "types/functions/function.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/functions/apply.hh"

namespace ListMapImpl
{
    template <Function_t Func, List_t List>
    struct ListMap;

    template <Function_t Func, List_t List>
    using ListMap_v = ListMap<Func, List>::result;

    template <Function_t Func>
    struct ListMap<Func, List<>>
    {
        using result = List<>;
    };

    template <Function_t Func, Any_t Head, Any_t... Tail>
    struct ListMap<Func, List<Head, Tail...>>
    {
        using result =
            ListPrepend_v<Apply_v<Func, Head>, ListMap_v<Func, List<Tail...>>>;
    };

    struct ListMapFunc
    {
        using is_function = IsFunction;

        template <Function_t Func, List_t List>
        struct apply
        {
            using result = ListMap_v<Func, List>;
        };
    };
} // namespace ListMapImpl

using ListMapImpl::ListMapFunc;
using ListMapImpl::ListMap_v;
