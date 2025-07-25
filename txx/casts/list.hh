#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace ToBigUnsignedImpl
{
    template <Any_t V>
        requires List_t<V>
    struct ToBigUnsigned<V>;

    template <Bit_t... Bits>
    struct ToBigUnsigned<List<Bits...>>
    {
        using result = BigUnsigned<Bits...>;
    };
} // namespace ToBigUnsignedImpl

namespace ToUnsigned8Impl
{
    template <Any_t List>
        requires List_t<List>
    struct ToUnsigned8<List>;

    template <Bit_t Bit0, Bit_t Bit1, Bit_t Bit2, Bit_t Bit3, Bit_t Bit4,
              Bit_t Bit5, Bit_t Bit6, Bit_t Bit7>
    struct ToUnsigned8<List<Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7>>
    {
        using result =
            Unsigned8<Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7>;
    };
} // namespace ToUnsigned8Impl
