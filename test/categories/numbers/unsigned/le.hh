#pragma once

#include "types/numbers/unsigned/ops/le.hh"

#include "../../../utils/is_same.hh"
#include "../../../utils/numbers.hh"

namespace unsigned_le_tests
{
    static_assert(is_same<UnsignedLE_v<n1, n2>, True>);
    static_assert(is_same<UnsignedLE_v<n1, n1>, True>);
    static_assert(is_same<UnsignedLE_v<n2, n1>, False>);
    static_assert(is_same<UnsignedLE_v<n10, n20>, True>);
    static_assert(is_same<UnsignedLE_v<n10, n10>, True>);
    static_assert(is_same<UnsignedLE_v<n20, n10>, False>);
    static_assert(is_same<UnsignedLE_v<n63, n64>, True>);
    static_assert(is_same<UnsignedLE_v<n64, n63>, False>);
    static_assert(is_same<UnsignedLE_v<n50, n60>, True>);
    static_assert(is_same<UnsignedLE_v<n50, n50>, True>);
    static_assert(is_same<UnsignedLE_v<n60, n50>, False>);
    static_assert(is_same<UnsignedLE_v<n0, n1>, True>);
    static_assert(is_same<UnsignedLE_v<n0, n0>, True>);
    static_assert(is_same<UnsignedLE_v<n1, n0>, False>);
    static_assert(is_same<UnsignedLE_v<n64, n64>, True>);
    static_assert(is_same<UnsignedLE_v<n10, n30>, True>);
    static_assert(is_same<UnsignedLE_v<n30, n10>, False>);
    static_assert(is_same<UnsignedLE_v<n32, n33>, True>);
    static_assert(is_same<UnsignedLE_v<n33, n33>, True>);
    static_assert(is_same<UnsignedLE_v<n33, n32>, False>);
} // namespace unsigned_le_tests
