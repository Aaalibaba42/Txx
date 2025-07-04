#pragma once

#include "types/bits/concept.hh"
#include "types/functions/function.hh"
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

    struct ToBigUnsignedFunc
    {
        using is_function = IsFunction;

        template <List_t List>
        struct apply
        {
            using result = ToBigUnsigned_v<List>;
        };
    };
} // namespace ToBigUnsignedImpl

using ToBigUnsignedImpl::ToBigUnsigned_v;
using ToBigUnsignedImpl::ToBigUnsignedFunc;
