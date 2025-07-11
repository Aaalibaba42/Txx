#pragma once

#include "functions/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace ListFoldLImpl
{
    template <Function_t Func, Any_t Acc, List_t List>
    struct ListFoldL;

    template <Function_t Func, Any_t Acc, List_t List>
    using ListFoldL_v = ListFoldL<Func, Acc, List>::result;

    template <Function_t Func, Any_t Acc>
    struct ListFoldL<Func, Acc, List<>>
    {
        using result = Acc;
    };

    template <Function_t Func, Any_t Acc, Any_t Head, Any_t... Tail>
    struct ListFoldL<Func, Acc, List<Head, Tail...>>
    {
        using result =
            ListFoldL_v<Func, Apply_v<Func, Acc, Head>, List<Tail...>>;
    };

    struct ListFoldLFunc
    {
        using is_function = IsFunction;

        template <Function_t Func, Any_t Acc, List_t List>
        struct apply
        {
            using result = ListFoldL_v<Func, Acc, List>;
        };
    };
} // namespace ListFoldLImpl

using ListFoldLImpl::ListFoldLFunc;
using ListFoldLImpl::ListFoldL_v;
