#pragma once

#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"

namespace ListSetImpl
{
    template <List_t L, Any_t Elem, BigUnsigned_t Position>
    struct ListSet;

    template <List_t L, Any_t Elem, BigUnsigned_t Position>
    using ListSet_v = typename ListSet<L, Elem, Position>::result;

    // List is empty
    template <Any_t Elem, BigUnsigned_t Position>
    struct ListSet<List<>, Elem, Position>
    {
        static_assert(false, "ListSet: index out of bounds");
    };

    // We found the correct position
    template <Any_t Head, Any_t... Tail, Any_t Elem>
    struct ListSet<List<Head, Tail...>, Elem, BigUnsigned<>>
    {
        using result = List<Elem, Tail...>;
    };

    // List is not empty, and position is not 0
    template <Any_t Head, Any_t... Tail, Any_t Elem, BigUnsigned_t Position>
    struct ListSet<List<Head, Tail...>, Elem, Position>
    {
        using result = ListPrepend_v<
            Head,
            ListSet_v<List<Tail...>, Elem,
                      BigUnsignedSub_v<Position, BigUnsigned<One>>>>;
    };

    struct ListSetFunc
    {
        using is_function = IsFunction;

        template <List_t L, Any_t Elem, BigUnsigned_t Position>
        struct apply
        {
            using result = ListSet_v<L, Elem, Position>;
        };
    };
} // namespace ListSetImpl

using ListSetImpl::ListSetFunc;
using ListSetImpl::ListSet_v;
