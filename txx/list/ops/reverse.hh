#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace ReverseImpl
{
    template <Any_t In, Any_t Acc>
        requires List_t<In> && List_t<Acc>
    struct ReverseRec;

    template <List_t Acc>
    struct ReverseRec<List<>, Acc>
    {
        using result = Acc;
    };

    template <Any_t Head, Any_t... Tail, List_t Acc>
    struct ReverseRec<List<Head, Tail...>, Acc>
    {
        using result = ReverseRec<List<Tail...>, Prepend_v<Head, Acc>>::result;
    };

    template <Any_t L>
        requires List_t<L>
    struct Reverse<L>
    {
        using result = ReverseRec<L, List<>>::result;
    };
} // namespace ReverseImpl
