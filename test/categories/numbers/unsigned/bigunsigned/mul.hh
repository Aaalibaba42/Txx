#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace bigunsigned_mul_tests
{
    using M0 = BigUnsignedMul_v<bu0, bu1>;
    using M1 = BigUnsignedMul_v<bu1, bu1>;
    using M0_1 = BigUnsignedMul_v<bu0, bu0>;
    using M4 = BigUnsignedMul_v<bu2, bu2>;
    using M6 = BigUnsignedMul_v<bu2, bu3>;
    using M8 = BigUnsignedMul_v<bu2, bu4>;
    using M10 = BigUnsignedMul_v<bu2, bu5>;
    using M12 = BigUnsignedMul_v<bu3, bu4>;
    using M14 = BigUnsignedMul_v<bu2, bu7>;
    using M15 = BigUnsignedMul_v<bu3, bu5>;
    using M16 = BigUnsignedMul_v<bu4, bu4>;
    using M18 = BigUnsignedMul_v<bu3, bu6>;
    using M20 = BigUnsignedMul_v<bu4, bu5>;
    using M21 = BigUnsignedMul_v<bu3, bu7>;
    using M24 = BigUnsignedMul_v<bu3, bu8>;
    using M25 = BigUnsignedMul_v<bu5, bu5>;
    using M27 = BigUnsignedMul_v<bu3, bu9>;
    using M28 = BigUnsignedMul_v<bu4, bu7>;
    using M30 = BigUnsignedMul_v<bu5, bu6>;
    using M32 = BigUnsignedMul_v<bu4, bu8>;
    using M35 = BigUnsignedMul_v<bu5, bu7>;
    using M36 = BigUnsignedMul_v<bu4, bu9>;
    using M40 = BigUnsignedMul_v<bu5, bu8>;
    using M42 = BigUnsignedMul_v<bu6, bu7>;
    using M45 = BigUnsignedMul_v<bu5, bu9>;
    using M48 = BigUnsignedMul_v<bu6, bu8>;
    using M49 = BigUnsignedMul_v<bu7, bu7>;
    using M54 = BigUnsignedMul_v<bu6, bu9>;
    using M56 = BigUnsignedMul_v<bu7, bu8>;
    using M63 = BigUnsignedMul_v<bu7, bu9>;
    using M64 = BigUnsignedMul_v<bu8, bu8>;

    static_assert(is_same<M0, bu0>);
    static_assert(is_same<M1, bu1>);
    static_assert(is_same<M0_1, bu0>);
    static_assert(is_same<M4, bu4>);
    static_assert(is_same<M6, bu6>);
    static_assert(is_same<M8, bu8>);
    static_assert(is_same<M10, bu10>);
    static_assert(is_same<M12, bu12>);
    static_assert(is_same<M14, bu14>);
    static_assert(is_same<M15, bu15>);
    static_assert(is_same<M16, bu16>);
    static_assert(is_same<M18, bu18>);
    static_assert(is_same<M20, bu20>);
    static_assert(is_same<M21, bu21>);
    static_assert(is_same<M24, bu24>);
    static_assert(is_same<M25, bu25>);
    static_assert(is_same<M27, bu27>);
    static_assert(is_same<M28, bu28>);
    static_assert(is_same<M30, bu30>);
    static_assert(is_same<M32, bu32>);
    static_assert(is_same<M35, bu35>);
    static_assert(is_same<M36, bu36>);
    static_assert(is_same<M40, bu40>);
    static_assert(is_same<M42, bu42>);
    static_assert(is_same<M45, bu45>);
    static_assert(is_same<M48, bu48>);
    static_assert(is_same<M49, bu49>);
    static_assert(is_same<M54, bu54>);
    static_assert(is_same<M56, bu56>);
    static_assert(is_same<M63, bu63>);
    static_assert(is_same<M64, bu64>);
} // namespace bigunsigned_mul_tests
