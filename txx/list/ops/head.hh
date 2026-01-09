#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace HeadImpl
{
    template <Any_t L>
        requires List_t<L>
    struct Head<L>;

    template <Any_t H, Any_t... Tail>
    struct Head<List<H, Tail...>>
    {
        using result = H;
    };
} // namespace HeadImpl
