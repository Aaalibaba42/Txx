#pragma once

#include "types/functions/function.hh"
#include "types/numbers/unsigned/bigunsigned/concept.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/bits/concept.hh"
#include "types/list/list.hh"

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
