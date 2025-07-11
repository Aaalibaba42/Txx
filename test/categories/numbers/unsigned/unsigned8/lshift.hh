#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/left_shift.hh"

namespace unsigned8_lshift_tests
{
    static_assert(is_same<Unsigned8LShift_v<u8_1, u8_0>, u8_1>);
    static_assert(is_same<Unsigned8LShift_v<u8_1, u8_1>, u8_2>);
    static_assert(is_same<Unsigned8LShift_v<u8_2, u8_2>, u8_8>);
    static_assert(is_same<Unsigned8LShift_v<u8_3, u8_3>, u8_24>);
    static_assert(is_same<Unsigned8LShift_v<u8_4, u8_1>, u8_8>);
    static_assert(is_same<Unsigned8LShift_v<u8_5, u8_2>, u8_20>);
    static_assert(is_same<Unsigned8LShift_v<u8_6, u8_1>, u8_12>);
    static_assert(is_same<Unsigned8LShift_v<u8_7, u8_2>, u8_28>);
    static_assert(is_same<Unsigned8LShift_v<u8_8, u8_1>, u8_16>);
    static_assert(is_same<Unsigned8LShift_v<u8_9, u8_2>, u8_36>);
    static_assert(is_same<Unsigned8LShift_v<u8_10, u8_1>, u8_20>);
    static_assert(is_same<Unsigned8LShift_v<u8_0, u8_5>, u8_0>);
    static_assert(is_same<Unsigned8LShift_v<u8_1, u8_3>, u8_8>);
    static_assert(is_same<Unsigned8LShift_v<u8_2, u8_1>, u8_4>);
    static_assert(is_same<Unsigned8LShift_v<u8_3, u8_2>, u8_12>);
    static_assert(is_same<Unsigned8LShift_v<u8_4, u8_3>, u8_32>);
    static_assert(is_same<Unsigned8LShift_v<u8_5, u8_1>, u8_10>);
    static_assert(is_same<Unsigned8LShift_v<u8_6, u8_2>, u8_24>);
    static_assert(is_same<Unsigned8LShift_v<u8_7, u8_1>, u8_14>);
    static_assert(is_same<Unsigned8LShift_v<u8_8, u8_2>, u8_32>);
    static_assert(is_same<Unsigned8LShift_v<u8_1, u8_4>, u8_16>);
} // namespace unsigned8_lshift_tests
