#pragma once

#include "types/numbers/unsigned/ops/mul.hh"

#include "../../../utils/is_same.hh"
#include "../../../utils/numbers.hh"

namespace unsigned_mul_tests
{
    using M0 = UnsignedMul_v<n0, n1>;
    using M1 = UnsignedMul_v<n1, n1>;
    using M0_1 = UnsignedMul_v<n0, n0>;
    using M4 = UnsignedMul_v<n2, n2>;
    using M6 = UnsignedMul_v<n2, n3>;
    using M8 = UnsignedMul_v<n2, n4>;
    using M10 = UnsignedMul_v<n2, n5>;
    using M12 = UnsignedMul_v<n3, n4>;
    using M14 = UnsignedMul_v<n2, n7>;
    using M15 = UnsignedMul_v<n3, n5>;
    using M16 = UnsignedMul_v<n4, n4>;
    using M18 = UnsignedMul_v<n3, n6>;
    using M20 = UnsignedMul_v<n4, n5>;
    using M21 = UnsignedMul_v<n3, n7>;
    using M24 = UnsignedMul_v<n3, n8>;
    using M25 = UnsignedMul_v<n5, n5>;
    using M27 = UnsignedMul_v<n3, n9>;
    using M28 = UnsignedMul_v<n4, n7>;
    using M30 = UnsignedMul_v<n5, n6>;
    using M32 = UnsignedMul_v<n4, n8>;
    using M35 = UnsignedMul_v<n5, n7>;
    using M36 = UnsignedMul_v<n4, n9>;
    using M40 = UnsignedMul_v<n5, n8>;
    using M42 = UnsignedMul_v<n6, n7>;
    using M45 = UnsignedMul_v<n5, n9>;
    using M48 = UnsignedMul_v<n6, n8>;
    using M49 = UnsignedMul_v<n7, n7>;
    using M54 = UnsignedMul_v<n6, n9>;
    using M56 = UnsignedMul_v<n7, n8>;
    using M63 = UnsignedMul_v<n7, n9>;
    using M64 = UnsignedMul_v<n8, n8>;

    static_assert(is_same<M0, n0>);
    static_assert(is_same<M1, n1>);
    static_assert(is_same<M0_1, n0>);
    static_assert(is_same<M4, n4>);
    static_assert(is_same<M6, n6>);
    static_assert(is_same<M8, n8>);
    static_assert(is_same<M10, n10>);
    static_assert(is_same<M12, n12>);
    static_assert(is_same<M14, n14>);
    static_assert(is_same<M15, n15>);
    static_assert(is_same<M16, n16>);
    static_assert(is_same<M18, n18>);
    static_assert(is_same<M20, n20>);
    static_assert(is_same<M21, n21>);
    static_assert(is_same<M24, n24>);
    static_assert(is_same<M25, n25>);
    static_assert(is_same<M27, n27>);
    static_assert(is_same<M28, n28>);
    static_assert(is_same<M30, n30>);
    static_assert(is_same<M32, n32>);
    static_assert(is_same<M35, n35>);
    static_assert(is_same<M36, n36>);
    static_assert(is_same<M40, n40>);
    static_assert(is_same<M42, n42>);
    static_assert(is_same<M45, n45>);
    static_assert(is_same<M48, n48>);
    static_assert(is_same<M49, n49>);
    static_assert(is_same<M54, n54>);
    static_assert(is_same<M56, n56>);
    static_assert(is_same<M63, n63>);
    static_assert(is_same<M64, n64>);
} // namespace unsigned_mul_tests
