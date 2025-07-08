#pragma once

#include "functions/function.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "bits/concept.hh"
#include "list/list.hh"

namespace ToListImpl
{
    template <BigUnsigned_t Num>
    struct ToList;

    template <BigUnsigned_t Num>
    using ToList_v = ToList<Num>::result;

    template <Bit_t... Bits>
    struct ToList<BigUnsigned<Bits...>>
    {
        using result = List<Bits...>;
    };

    struct ToListFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t Num>
        struct apply
        {
            using result = ToList_v<Num>;
        };
    };
} // namespace ToListImpl

using ToListImpl::ToListFunc;
using ToListImpl::ToList_v;
