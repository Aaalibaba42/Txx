#pragma once

#include "functions/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace ListFoldRImpl
{
    template <Function_t Func, List_t List, Any_t Acc>
    struct ListFoldR;

    template <Function_t Func, List_t List, Any_t Acc>
    using ListFoldR_v = ListFoldR<Func, List, Acc>::result;

    template <Function_t Func, Any_t Acc>
    struct ListFoldR<Func, List<>, Acc>
    {
        using result = Acc;
    };

    template <Function_t Func, Any_t Head, Any_t... Tail, Any_t Acc>
    struct ListFoldR<Func, List<Head, Tail...>, Acc>
    {
        using result =
            Apply_v<Func, Head, ListFoldR_v<Func, List<Tail...>, Acc>>;
    };

    struct ListFoldRFunc
    {
        using is_function = IsFunction;

        template <Function_t Func, List_t List, Any_t Acc>
        struct apply
        {
            using result = ListFoldR_v<Func, List, Acc>;
        };
    };
} // namespace ListFoldRImpl

using ListFoldRImpl::ListFoldRFunc;
using ListFoldRImpl::ListFoldR_v;
