#pragma once

#include "types/numbers/unsigned/bigunsigned/concept.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/bits/concept.hh"
#include "types/list/list.hh"

namespace ToListImpl
{
    template <BigUnsigned_t T>
    struct ToList;

    template <BigUnsigned_t T>
    using ToList_v = ToList<T>::result;

    template <Bit_t... Bits>
    struct ToList<BigUnsigned<Bits...>>
    {
        using result = List<Bits...>;
    };
} // namespace ToListImpl

using ToListImpl::ToList_v;
