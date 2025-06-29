#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/add.hh"

#include "../../../../utils/is_same.hh"
#include "../../../../utils/numbers.hh"

namespace bigunsigned_add_tests
{
    using A5 = BigUnsignedAdd_v<n3, n2>;
    using A16 = BigUnsignedAdd_v<n8, n8>;
    using A8 = BigUnsignedAdd_v<n7, n1>;
    using A1 = BigUnsignedAdd_v<n0, n1>;
    using A0 = BigUnsignedAdd_v<n0, n0>;
    using A15_1 = BigUnsignedAdd_v<n15, n0>;
    using A15_2 = BigUnsignedAdd_v<n0, n15>;
    using A16_1 = BigUnsignedAdd_v<n15, n1>;
    using A16_2 = BigUnsignedAdd_v<n1, n15>;
    using A6 = BigUnsignedAdd_v<n2, n4>;
    using A9 = BigUnsignedAdd_v<n5, n4>;
    using A11 = BigUnsignedAdd_v<n3, n8>;
    using A14 = BigUnsignedAdd_v<n6, n8>;
    using A15 = BigUnsignedAdd_v<n7, n8>;
    using A10 = BigUnsignedAdd_v<n4, n6>;
    using A13 = BigUnsignedAdd_v<n5, n8>;
    using A17 = BigUnsignedAdd_v<n9, n8>;
    using A19 = BigUnsignedAdd_v<n11, n8>;
    using A22 = BigUnsignedAdd_v<n14, n8>;
    using A25 = BigUnsignedAdd_v<n16, n9>;
    using A28 = BigUnsignedAdd_v<n19, n9>;
    using A30 = BigUnsignedAdd_v<n20, n10>;
    using A33 = BigUnsignedAdd_v<n22, n11>;
    using A35 = BigUnsignedAdd_v<n24, n11>;
    using A38 = BigUnsignedAdd_v<n27, n11>;
    using A40 = BigUnsignedAdd_v<n30, n10>;
    using A42 = BigUnsignedAdd_v<n33, n9>;
    using A45 = BigUnsignedAdd_v<n36, n9>;
    using A48 = BigUnsignedAdd_v<n39, n9>;
    using A50 = BigUnsignedAdd_v<n41, n9>;

    static_assert(is_same<A6, n6>);
    static_assert(is_same<A9, n9>);
    static_assert(is_same<A11, n11>);
    static_assert(is_same<A14, n14>);
    static_assert(is_same<A15, n15>);
    static_assert(is_same<A10, n10>);
    static_assert(is_same<A13, n13>);
    static_assert(is_same<A17, n17>);
    static_assert(is_same<A19, n19>);
    static_assert(is_same<A22, n22>);
    static_assert(is_same<A25, n25>);
    static_assert(is_same<A28, n28>);
    static_assert(is_same<A30, n30>);
    static_assert(is_same<A33, n33>);
    static_assert(is_same<A35, n35>);
    static_assert(is_same<A38, n38>);
    static_assert(is_same<A40, n40>);
    static_assert(is_same<A42, n42>);
    static_assert(is_same<A45, n45>);
    static_assert(is_same<A48, n48>);
    static_assert(is_same<A50, n50>);
    static_assert(is_same<A5, n5>);
    static_assert(is_same<A16, n16>);
    static_assert(is_same<A8, n8>);
    static_assert(is_same<A1, n1>);
    static_assert(is_same<A0, n0>);
    static_assert(is_same<A15_1, n15>);
    static_assert(is_same<A15_2, n15>);
    static_assert(is_same<A16_1, n16>);
    static_assert(is_same<A16_2, n16>);
} // namespace bigunsigned_add_tests
