#pragma once

#include "types/bits/concept.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/numbers/unsigned/unsigned.hh"

namespace ToUnsignedImpl
{
    template <List_t List>
    struct ToUnsigned;

    template <List_t List>
    using ToUnsigned_v = ToUnsigned<List>::result;

    template <Bit_t... Bits>
    struct ToUnsigned<List<Bits...>>
    {
        using result = Unsigned<Bits...>;
    };
} // namespace ToUnsignedImpl

using ToUnsignedImpl::ToUnsigned_v;
