#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace ConcatImpl
{
    template <Any_t L1, Any_t L2>
        requires List_t<L1> && List_t<L2>
    struct Concat<L1, L2>;

    template <Any_t... L2Elems>
    struct Concat<List<>, List<L2Elems...>>
    {
        using result = List<L2Elems...>;
    };

    template <Any_t Head, Any_t... Tail, Any_t... L2Elems>
    struct Concat<List<Head, Tail...>, List<L2Elems...>>
    {
        using result =
            Prepend_v<Head, Concat_v<List<Tail...>, List<L2Elems...>>>;
    };
} // namespace ConcatImpl
