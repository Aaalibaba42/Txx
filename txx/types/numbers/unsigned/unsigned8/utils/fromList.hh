#pragma once

#include "types/bits/concept.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/numbers/unsigned/unsigned8/unsigned8.hh"

namespace ToUnsigned8Impl
{
    template <List_t List>
    struct ToUnsigned8;

    template <List_t List>
    using ToUnsigned8_v = ToUnsigned8<List>::result;

    template <Bit_t Bit0, Bit_t Bit1, Bit_t Bit2, Bit_t Bit3, Bit_t Bit4,
              Bit_t Bit5, Bit_t Bit6, Bit_t Bit7>
    struct ToUnsigned8<List<Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7>>
    {
        using result =
            Unsigned8<Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7>;
    };
} // namespace ToUnsigned8Impl

using ToUnsigned8Impl::ToUnsigned8_v;
