#pragma once

#include "functions/base.hh"
#include "functions/concept.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace MapImpl
{
    template <Any_t Func, Any_t L>
        requires Function_t<Func> && List_t<L>
    struct Map<Func, L>;

    template <Function_t Func>
    struct Map<Func, List<>>
    {
        using result = List<>;
    };

    template <Function_t Func, Any_t Head, Any_t... Tail>
    struct Map<Func, List<Head, Tail...>>
    {
        using result =
            Prepend_v<Apply_v<Func, Head>, Map_v<Func, List<Tail...>>>;
    };
} // namespace MapImpl
