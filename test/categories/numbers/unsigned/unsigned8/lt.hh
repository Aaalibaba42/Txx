#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/unsigned8/ops/lt.hh"

namespace unsigned8_lt_tests
{
    static_assert(is_same<Unsigned8LT_v<u8_1, u8_2>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_1, u8_1>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_2, u8_1>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_10, u8_20>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_10, u8_10>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_20, u8_10>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_63, u8_64>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_64, u8_63>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_50, u8_60>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_50, u8_50>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_60, u8_50>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_0, u8_1>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_0, u8_0>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_1, u8_0>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_64, u8_64>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_10, u8_30>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_30, u8_10>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_32, u8_33>, True>);
    static_assert(is_same<Unsigned8LT_v<u8_33, u8_33>, False>);
    static_assert(is_same<Unsigned8LT_v<u8_33, u8_32>, False>);
} // namespace unsigned8_lt_tests
