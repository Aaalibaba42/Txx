#pragma once

#include "types/bits/concept.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"

namespace ToBigUnsignedImpl
{
    template <List_t List>
    struct ToBigUnsigned;

    template <List_t List>
    using ToBigUnsigned_v = ToBigUnsigned<List>::result;

    template <Bit_t... Bits>
    struct ToBigUnsigned<List<Bits...>>
    {
        using result = BigUnsigned<Bits...>;
    };
} // namespace ToBigUnsignedImpl

using ToBigUnsignedImpl::ToBigUnsigned_v;
