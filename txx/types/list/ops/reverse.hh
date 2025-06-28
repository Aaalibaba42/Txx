#pragma once

#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/meta/any.hh"

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
} // namespace ListReverseImpl

using ListReverseImpl::ListReverse_v;
