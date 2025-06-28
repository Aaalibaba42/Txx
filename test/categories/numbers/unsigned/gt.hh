#pragma once

#include "types/numbers/unsigned/ops/gt.hh"

#include "../../../utils/is_same.hh"
#include "../../../utils/numbers.hh"

namespace unsigned_gt_tests
{
    static_assert(is_same<UnsignedGT_v<n1, n2>, False>);
    static_assert(is_same<UnsignedGT_v<n1, n1>, False>);
    static_assert(is_same<UnsignedGT_v<n2, n1>, True>);
    static_assert(is_same<UnsignedGT_v<n10, n20>, False>);
    static_assert(is_same<UnsignedGT_v<n10, n10>, False>);
    static_assert(is_same<UnsignedGT_v<n20, n10>, True>);
    static_assert(is_same<UnsignedGT_v<n63, n64>, False>);
    static_assert(is_same<UnsignedGT_v<n64, n63>, True>);
    static_assert(is_same<UnsignedGT_v<n50, n60>, False>);
    static_assert(is_same<UnsignedGT_v<n50, n50>, False>);
    static_assert(is_same<UnsignedGT_v<n60, n50>, True>);
    static_assert(is_same<UnsignedGT_v<n0, n1>, False>);
    static_assert(is_same<UnsignedGT_v<n0, n0>, False>);
    static_assert(is_same<UnsignedGT_v<n1, n0>, True>);
    static_assert(is_same<UnsignedGT_v<n64, n64>, False>);
    static_assert(is_same<UnsignedGT_v<n10, n30>, False>);
    static_assert(is_same<UnsignedGT_v<n30, n10>, True>);
    static_assert(is_same<UnsignedGT_v<n32, n33>, False>);
    static_assert(is_same<UnsignedGT_v<n33, n33>, False>);
    static_assert(is_same<UnsignedGT_v<n33, n32>, True>);
} // namespace unsigned_gt_tests
