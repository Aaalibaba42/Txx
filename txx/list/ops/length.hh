#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

namespace LengthImpl
{
    template <Any_t L>
        requires List_t<L>
    struct Length<L>;

    template <>
    struct Length<List<>>
    {
        using result = BigUnsigned<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct Length<List<Head, Tail...>>
    {
        using result = Inc_v<Length_v<List<Tail...>>>;
    };
} // namespace LengthImpl
