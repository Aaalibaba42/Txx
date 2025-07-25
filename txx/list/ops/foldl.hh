#pragma once

#include "functions/base.hh"
#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace FoldLImpl
{
    template <Any_t Func, Any_t Acc>
        requires Function_t<Func>
    struct FoldL<Func, Acc, List<>>
    {
        using result = Acc;
    };

    template <Any_t Func, Any_t Acc, Any_t Head, Any_t... Tail>
        requires Function_t<Func>
    struct FoldL<Func, Acc, List<Head, Tail...>>
    {
        using result = FoldL_v<Func, Apply_v<Func, Acc, Head>, List<Tail...>>;
    };
} // namespace FoldLImpl
