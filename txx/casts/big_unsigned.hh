#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "list/list.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

namespace ToListImpl
{
    template <Any_t Num>
        requires BigUnsigned_t<Num>
    struct ToList<Num>;

    template <Bit_t... Bits>
    struct ToList<BigUnsigned<Bits...>>
    {
        using result = List<Bits...>;
    };
} // namespace ToListImpl
