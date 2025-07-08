#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

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

    struct ToUnsigned8Func
    {
        using is_function = IsFunction;

        template <List_t List>
        struct apply
        {
            using result = ToUnsigned8_v<List>;
        };
    };
} // namespace ToUnsigned8Impl

using ToUnsigned8Impl::ToUnsigned8_v;
