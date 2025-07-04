#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/list/ops/prepend.hh"
#include "types/list/utils/fromUnsigned.hh"
#include "types/numbers/unsigned/bigunsigned/concept.hh"
#include "types/numbers/unsigned/bigunsigned/ops/sub.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/numbers/unsigned/bigunsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/bigunsigned/utils/fromList.hh"

namespace BigUnsignedLShiftImpl
{
    template <BigUnsigned_t Value, BigUnsigned_t Amount>
    struct BigUnsignedLShift;

    template <BigUnsigned_t Value, BigUnsigned_t Amount>
    using BigUnsignedLShift_v = BigUnsignedLShift<Value, Amount>::result;

    template <BigUnsigned_t Value>
    struct BigUnsignedLShift<Value, BigUnsigned<>>
    {
        using result = Value;
    };

    template <BigUnsigned_t Value, Bit_t... AmountBits>
    struct BigUnsignedLShift<Value, BigUnsigned<AmountBits...>>
    {
        using NewBits = ListPrepend_v<Zero, ToList_v<Value>>;
        using ShiftedOnce = ToBigUnsigned_v<NewBits>;
        // TODO Do an optimized decrement operator you lazy fuck, you already
        // have the full subtractor
        using Decrement =
            BigUnsignedSub_v<BigUnsigned<AmountBits...>, BigUnsigned<One>>;
        using result = BigUnsignedCanonicalize_v<
            BigUnsignedLShift_v<ShiftedOnce, Decrement>>;
    };
} // namespace BigUnsignedLShiftImpl

using BigUnsignedLShiftImpl::BigUnsignedLShift_v;
