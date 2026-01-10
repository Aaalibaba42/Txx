#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "literals/bits.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/dec.hh"

namespace DropImpl
{
    template <Any_t N, Any_t L>
        requires BigUnsigned_t<N> && List_t<L>
    struct Drop<N, L>;

    template <>
    struct Drop<BigUnsigned<>, List<>>
    {
        using result = List<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct Drop<BigUnsigned<>, List<Head, Tail...>>
    {
        using result = List<Head, Tail...>;
    };

    // Means N > 0, since canonical repr of bu0 is no template va arg
    template <Bit_t B, Bit_t... Bs>
    struct Drop<BigUnsigned<B, Bs...>, List<>>
    {
        using result = List<>;
    };

    template <Bit_t B, Bit_t... Bs, Any_t Head, Any_t... Tail>
    struct Drop<BigUnsigned<B, Bs...>, List<Head, Tail...>>
    {
        using result = Drop_v<Dec_v<BigUnsigned<B, Bs...>>, List<Tail...>>;
    };
} // namespace DropImpl
