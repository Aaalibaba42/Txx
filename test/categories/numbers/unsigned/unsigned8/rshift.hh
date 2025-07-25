#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/right_shift.hh"

namespace unsigned8_rshift_tests
{
    static_assert(is_same<RShift_v<u8_1, u8_0>, u8_1>);
    static_assert(is_same<RShift_v<u8_2, u8_1>, u8_1>);
    static_assert(is_same<RShift_v<u8_8, u8_2>, u8_2>);
    static_assert(is_same<RShift_v<u8_24, u8_3>, u8_3>);
    static_assert(is_same<RShift_v<u8_8, u8_1>, u8_4>);
    static_assert(is_same<RShift_v<u8_20, u8_2>, u8_5>);
    static_assert(is_same<RShift_v<u8_12, u8_1>, u8_6>);
    static_assert(is_same<RShift_v<u8_28, u8_2>, u8_7>);
    static_assert(is_same<RShift_v<u8_16, u8_1>, u8_8>);
    static_assert(is_same<RShift_v<u8_36, u8_2>, u8_9>);
    static_assert(is_same<RShift_v<u8_20, u8_1>, u8_10>);
    static_assert(is_same<RShift_v<u8_0, u8_5>, u8_0>);
    static_assert(is_same<RShift_v<u8_8, u8_3>, u8_1>);
    static_assert(is_same<RShift_v<u8_4, u8_1>, u8_2>);
    static_assert(is_same<RShift_v<u8_12, u8_2>, u8_3>);
    static_assert(is_same<RShift_v<u8_32, u8_3>, u8_4>);
    static_assert(is_same<RShift_v<u8_10, u8_1>, u8_5>);
    static_assert(is_same<RShift_v<u8_24, u8_2>, u8_6>);
    static_assert(is_same<RShift_v<u8_14, u8_1>, u8_7>);
    static_assert(is_same<RShift_v<u8_32, u8_2>, u8_8>);
    static_assert(is_same<RShift_v<u8_16, u8_4>, u8_1>);
} // namespace unsigned8_rshift_tests
