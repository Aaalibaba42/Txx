#pragma once

#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

namespace ListLengthImpl
{
    template <List_t L>
    struct ListLength;

    template <List_t L>
    using ListLength_v = typename ListLength<L>::result;

    template <>
    struct ListLength<List<>>
    {
        using result = BigUnsigned<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct ListLength<List<Head, Tail...>>
    {
        using result = BigUnsignedInc_v<ListLength_v<List<Tail...>>>;
    };

    struct ListLengthFunc
    {
        using is_function = IsFunction;

        template <List_t L>
        struct apply
        {
            using result = ListLength_v<L>;
        };
    };
} // namespace ListLengthImpl

using ListLengthImpl::ListLengthFunc;
using ListLengthImpl::ListLength_v;
