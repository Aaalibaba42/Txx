#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/ge.hh"

#include "../../../../utils/is_same.hh"
#include "../../../../utils/numbers.hh"

namespace bigunsigned_ge_tests
{
    static_assert(is_same<BigUnsignedGE_v<n1, n2>, False>);
    static_assert(is_same<BigUnsignedGE_v<n1, n1>, True>);
    static_assert(is_same<BigUnsignedGE_v<n2, n1>, True>);
    static_assert(is_same<BigUnsignedGE_v<n10, n20>, False>);
    static_assert(is_same<BigUnsignedGE_v<n10, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n20, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n63, n64>, False>);
    static_assert(is_same<BigUnsignedGE_v<n64, n63>, True>);
    static_assert(is_same<BigUnsignedGE_v<n50, n60>, False>);
    static_assert(is_same<BigUnsignedGE_v<n50, n50>, True>);
    static_assert(is_same<BigUnsignedGE_v<n60, n50>, True>);
    static_assert(is_same<BigUnsignedGE_v<n0, n1>, False>);
    static_assert(is_same<BigUnsignedGE_v<n0, n0>, True>);
    static_assert(is_same<BigUnsignedGE_v<n1, n0>, True>);
    static_assert(is_same<BigUnsignedGE_v<n64, n64>, True>);
    static_assert(is_same<BigUnsignedGE_v<n10, n30>, False>);
    static_assert(is_same<BigUnsignedGE_v<n30, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n32, n33>, False>);
    static_assert(is_same<BigUnsignedGE_v<n33, n33>, True>);
    static_assert(is_same<BigUnsignedGE_v<n33, n32>, True>);
} // namespace bigunsigned_ge_tests
