#pragma once

#include "functions/base.hh"
#include "functions/base/apply.hh"
#include "functions/base/ternary.hh"
#include "functions/concept.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace FilterImpl
{
    template <Any_t Pred, Any_t L>
        requires Function_t<Pred> && List_t<L>
    struct Filter<Pred, L>;

    template <Function_t Pred>
    struct Filter<Pred, List<>>
    {
        using result = List<>;
    };

    template <Function_t Pred, Any_t Head, Any_t... Tail>
    struct Filter<Pred, List<Head, Tail...>>
    {
        using keep = Apply_v<Pred, Head>;
        using filtered_tail = Filter_v<Pred, List<Tail...>>;
        using with_head = Prepend_v<Head, filtered_tail>;
        using result = Ternary_v<keep, with_head, filtered_tail>;
    };
} // namespace FilterImpl
