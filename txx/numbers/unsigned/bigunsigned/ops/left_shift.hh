#pragma once

#include "bits/concept.hh"
#include "casts/big_unsigned.hh"
#include "functions/base.hh"
#include "functions/function.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace LShiftImpl
{
    template <Any_t Value, Any_t Amount>
        requires BigUnsigned_t<Value> && BigUnsigned_t<Amount>
    struct LShift<Value, Amount>;

    template <BigUnsigned_t Value>
    struct LShift<Value, BigUnsigned<>>
    {
        using result = Value;
    };

    template <BigUnsigned_t Value, Bit_t... AmountBits>
    struct LShift<Value, BigUnsigned<AmountBits...>>
    {
        using NewBits = Prepend_v<Zero, ToList_v<Value>>;
        using ShiftedOnce = ToBigUnsigned_v<NewBits>;
        // TODO Do an optimized decrement operator you lazy fuck, you already
        // have the full subtractor
        using Decrement = Sub_v<BigUnsigned<AmountBits...>, BigUnsigned<One>>;
        using result = Canonicalize_v<LShift_v<ShiftedOnce, Decrement>>;
    };
} // namespace LShiftImpl
