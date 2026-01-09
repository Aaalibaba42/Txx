#pragma once

#include "functions/base.hh"
#include "functions/base/apply.hh"
#include "functions/base/ternary.hh"
#include "functions/concept.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace AnyImpl
{
    template <Any_t Pred, Any_t L>
        requires Function_t<Pred> && List_t<L>
    struct Any<Pred, L>;

    template <Function_t Pred>
    struct Any<Pred, List<>>
    {
        using result = False;
    };

    template <Function_t Pred, Any_t Head, Any_t... Tail>
    struct Any<Pred, List<Head, Tail...>>
    {
        using result = Ternary_v<Apply_v<Pred, Head>, True, Any_v<Pred, List<Tail...>>>;
    };
} // namespace AnyImpl
