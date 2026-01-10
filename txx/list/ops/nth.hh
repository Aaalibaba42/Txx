#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "literals/bits.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/dec.hh"

namespace NthImpl
{
    template <Any_t L, Any_t Idx>
        requires List_t<L> && BigUnsigned_t<Idx>
    struct Nth<L, Idx>;

    // Index 0: return head
    template <Any_t Head, Any_t... Tail>
    struct Nth<List<Head, Tail...>, BigUnsigned<>>
    {
        using result = Head;
    };

    // Index > 0: recurse with decremented index
    template <Any_t Head, Any_t... Tail, BigUnsigned_t Idx>
    struct Nth<List<Head, Tail...>, Idx>
    {
        using result = Nth_v<List<Tail...>, Dec_v<Idx>>;
    };
} // namespace NthImpl
