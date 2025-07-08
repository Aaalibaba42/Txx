#pragma once

#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace ListReverseImpl
{
    template <List_t In, List_t Acc = List<>>
    struct ListReverse;

    template <List_t In, List_t Acc = List<>>
    using ListReverse_v = ListReverse<In, Acc>::result;

    template <List_t Acc>
    struct ListReverse<List<>, Acc>
    {
        using result = Acc;
    };

    template <Any_t Head, Any_t... Tail, List_t Acc>
    struct ListReverse<List<Head, Tail...>, Acc>
    {
        using result = ListReverse_v<List<Tail...>, ListPrepend_v<Head, Acc>>;
    };

    struct ListReverseFunc
    {
        using is_function = IsFunction;

        template <List_t L>
        struct apply
        {
            using result = ListReverse_v<L>;
        };
    };
} // namespace ListReverseImpl

using ListReverseImpl::ListReverseFunc;
using ListReverseImpl::ListReverse_v;
