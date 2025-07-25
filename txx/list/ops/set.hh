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

namespace SetImpl
{
    template <Any_t L, Any_t Elem, Any_t Position>
        requires List_t<L> && BigUnsigned_t<Position>
    struct Set<L, Elem, Position>;

    // List is empty
    template <Any_t Elem, Any_t Position>
    struct Set<List<>, Elem, Position>
    {
        static_assert(false, "Set: index out of bounds");
    };

    // We found the correct position
    template <Any_t Head, Any_t... Tail, Any_t Elem>
    struct Set<List<Head, Tail...>, Elem, BigUnsigned<>>
    {
        using result = List<Elem, Tail...>;
    };

    // List is not empty, and position is not 0
    template <Any_t Head, Any_t... Tail, Any_t Elem, BigUnsigned_t Position>
    struct Set<List<Head, Tail...>, Elem, Position>
    {
        using result = Prepend_v<
            Head,
            Set_v<List<Tail...>, Elem, Sub_v<Position, BigUnsigned<One>>>>;
    };
} // namespace SetImpl
