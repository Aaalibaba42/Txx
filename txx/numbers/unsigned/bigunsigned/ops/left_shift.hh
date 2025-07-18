#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "list/ops/prepend.hh"
#include "list/utils/fromUnsigned.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"
#include "numbers/unsigned/bigunsigned/utils/fromList.hh"

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

    struct BigUnsignedLShiftFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t Value, BigUnsigned_t Amount>
        struct apply
        {
            using result = BigUnsignedLShift_v<Value, Amount>;
        };
    };
} // namespace BigUnsignedLShiftImpl

using BigUnsignedLShiftImpl::BigUnsignedLShiftFunc;
using BigUnsignedLShiftImpl::BigUnsignedLShift_v;
