#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace TailImpl
{
    template <Any_t L>
        requires List_t<L>
    struct Tail<L>;

    template <Any_t H, Any_t... Rest>
    struct Tail<List<H, Rest...>>
    {
        using result = List<Rest...>;
    };
} // namespace TailImpl
