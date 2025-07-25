#pragma once

#include "functions/base.hh"
#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace FoldRImpl
{
    template <Any_t Func, Any_t List, Any_t Acc>
        requires Function_t<Func> && List_t<List>
    struct FoldR<Func, List, Acc>;

    template <Function_t Func, Any_t Acc>
    struct FoldR<Func, List<>, Acc>
    {
        using result = Acc;
    };

    template <Function_t Func, Any_t Head, Any_t... Tail, Any_t Acc>
    struct FoldR<Func, List<Head, Tail...>, Acc>
    {
        using result = Apply_v<Func, Head, FoldR_v<Func, List<Tail...>, Acc>>;
    };
} // namespace FoldRImpl
