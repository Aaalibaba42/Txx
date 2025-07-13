#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/unsigned8/ops/gt.hh"

namespace unsigned8_gt_tests
{
    static_assert(is_same<Unsigned8GT_v<u8_1, u8_2>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_1, u8_1>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_2, u8_1>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_10, u8_20>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_10, u8_10>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_20, u8_10>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_63, u8_64>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_64, u8_63>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_50, u8_60>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_50, u8_50>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_60, u8_50>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_0, u8_1>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_0, u8_0>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_1, u8_0>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_64, u8_64>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_10, u8_30>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_30, u8_10>, True>);
    static_assert(is_same<Unsigned8GT_v<u8_32, u8_33>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_33, u8_33>, False>);
    static_assert(is_same<Unsigned8GT_v<u8_33, u8_32>, True>);
} // namespace unsigned8_gt_tests
