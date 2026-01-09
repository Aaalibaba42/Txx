#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace IsEmptyImpl
{
    template <Any_t L>
        requires List_t<L>
    struct IsEmpty<L>;

    template <>
    struct IsEmpty<List<>>
    {
        using result = True;
    };

    template <Any_t H, Any_t... Rest>
    struct IsEmpty<List<H, Rest...>>
    {
        using result = False;
    };
} // namespace IsEmptyImpl
