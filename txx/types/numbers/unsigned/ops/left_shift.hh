#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/list/ops/prepend.hh"
#include "types/list/utils/fromUnsigned.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/ops/sub.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/numbers/unsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/utils/fromList.hh"

template <Unsigned_t Value, Unsigned_t Amount>
struct UnsignedLShift;

template <Unsigned_t Value, Unsigned_t Amount>
using UnsignedLShift_v = UnsignedLShift<Value, Amount>::result;

template <Unsigned_t Value>
struct UnsignedLShift<Value, Unsigned<>>
{
    using result = Value;
};

template <Unsigned_t Value, Bit_t... AmountBits>
struct UnsignedLShift<Value, Unsigned<AmountBits...>>
{
    using NewBits = Prepend_v<Zero, ToList_v<Value>>;
    using ShiftedOnce = ToUnsigned_v<NewBits>;
    // TODO Do an optimized decrement operator you lazy fuck, you already have
    // the full subtractor
    using Decrement = UnsignedSub_v<Unsigned<AmountBits...>, Unsigned<One>>;
    using result = Canonicalize_v<UnsignedLShift_v<ShiftedOnce, Decrement>>;
};
