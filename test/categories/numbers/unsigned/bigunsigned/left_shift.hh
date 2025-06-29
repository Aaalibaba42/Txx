#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/left_shift.hh"

#include "../../../../utils/is_same.hh"
#include "../../../../utils/numbers.hh"

namespace bigunsigned_lshift_tests
{
    static_assert(is_same<BigUnsignedLShift_v<n1, n0>, n1>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n1>, n2>);
    static_assert(is_same<BigUnsignedLShift_v<n2, n2>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n3, n3>, n24>);
    static_assert(is_same<BigUnsignedLShift_v<n4, n1>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n5, n2>, n20>);
    static_assert(is_same<BigUnsignedLShift_v<n6, n1>, n12>);
    static_assert(is_same<BigUnsignedLShift_v<n7, n2>, n28>);
    static_assert(is_same<BigUnsignedLShift_v<n8, n1>, n16>);
    static_assert(is_same<BigUnsignedLShift_v<n9, n2>, n36>);
    static_assert(is_same<BigUnsignedLShift_v<n10, n1>, n20>);
    static_assert(is_same<BigUnsignedLShift_v<n0, n5>, n0>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n3>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n2, n1>, n4>);
    static_assert(is_same<BigUnsignedLShift_v<n3, n2>, n12>);
    static_assert(is_same<BigUnsignedLShift_v<n4, n3>, n32>);
    static_assert(is_same<BigUnsignedLShift_v<n5, n1>, n10>);
    static_assert(is_same<BigUnsignedLShift_v<n6, n2>, n24>);
    static_assert(is_same<BigUnsignedLShift_v<n7, n1>, n14>);
    static_assert(is_same<BigUnsignedLShift_v<n8, n2>, n32>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n4>, n16>);
} // namespace bigunsigned_lshift_tests
