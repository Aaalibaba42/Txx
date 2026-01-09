#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"

namespace TakeImpl
{
    template <Any_t N, Any_t L>
        requires BigUnsigned_t<N> && List_t<L>
    struct Take<N, L>;

    template <>
    struct Take<BigUnsigned<>, List<>>
    {
        using result = List<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct Take<BigUnsigned<>, List<Head, Tail...>>
    {
        using result = List<>;
    };

    // Means N > 0, since canonical repr of bu0 is no template va arg
    template <Bit_t B, Bit_t... Bs>
    struct Take<BigUnsigned<B, Bs...>, List<>>
    {
        using result = List<>;
    };

   template <Bit_t B, Bit_t... Bs, Any_t Head, Any_t... Tail>
    struct Take<BigUnsigned<B, Bs...>, List<Head, Tail...>>
    {
        using result =
            Prepend_v<Head, Take_v<Sub_v<BigUnsigned<B, Bs...>, BigUnsigned<One>>, List<Tail...>>>;
    };
} // namespace TakeImpl
