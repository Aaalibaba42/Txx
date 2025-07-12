#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/mul.hh"

namespace bigunsigned_mul_tests
{
    using M0 = Unsigned8Mul_v<u8_0, u8_1>;
    using M1 = Unsigned8Mul_v<u8_1, u8_1>;
    using M0_1 = Unsigned8Mul_v<u8_0, u8_0>;
    using M4 = Unsigned8Mul_v<u8_2, u8_2>;
    using M6 = Unsigned8Mul_v<u8_2, u8_3>;
    using M8 = Unsigned8Mul_v<u8_2, u8_4>;
    using M10 = Unsigned8Mul_v<u8_2, u8_5>;
    using M12 = Unsigned8Mul_v<u8_3, u8_4>;
    using M14 = Unsigned8Mul_v<u8_2, u8_7>;
    using M15 = Unsigned8Mul_v<u8_3, u8_5>;
    using M16 = Unsigned8Mul_v<u8_4, u8_4>;
    using M18 = Unsigned8Mul_v<u8_3, u8_6>;
    using M20 = Unsigned8Mul_v<u8_4, u8_5>;
    using M21 = Unsigned8Mul_v<u8_3, u8_7>;
    using M24 = Unsigned8Mul_v<u8_3, u8_8>;
    using M25 = Unsigned8Mul_v<u8_5, u8_5>;
    using M27 = Unsigned8Mul_v<u8_3, u8_9>;
    using M28 = Unsigned8Mul_v<u8_4, u8_7>;
    using M30 = Unsigned8Mul_v<u8_5, u8_6>;
    using M32 = Unsigned8Mul_v<u8_4, u8_8>;
    using M35 = Unsigned8Mul_v<u8_5, u8_7>;
    using M36 = Unsigned8Mul_v<u8_4, u8_9>;
    using M40 = Unsigned8Mul_v<u8_5, u8_8>;
    using M42 = Unsigned8Mul_v<u8_6, u8_7>;
    using M45 = Unsigned8Mul_v<u8_5, u8_9>;
    using M48 = Unsigned8Mul_v<u8_6, u8_8>;
    using M49 = Unsigned8Mul_v<u8_7, u8_7>;
    using M54 = Unsigned8Mul_v<u8_6, u8_9>;
    using M56 = Unsigned8Mul_v<u8_7, u8_8>;
    using M63 = Unsigned8Mul_v<u8_7, u8_9>;
    using M64 = Unsigned8Mul_v<u8_8, u8_8>;

    static_assert(is_same<M0, u8_0>);
    static_assert(is_same<M1, u8_1>);
    static_assert(is_same<M0_1, u8_0>);
    static_assert(is_same<M4, u8_4>);
    static_assert(is_same<M6, u8_6>);
    static_assert(is_same<M8, u8_8>);
    static_assert(is_same<M10, u8_10>);
    static_assert(is_same<M12, u8_12>);
    static_assert(is_same<M14, u8_14>);
    static_assert(is_same<M15, u8_15>);
    static_assert(is_same<M16, u8_16>);
    static_assert(is_same<M18, u8_18>);
    static_assert(is_same<M20, u8_20>);
    static_assert(is_same<M21, u8_21>);
    static_assert(is_same<M24, u8_24>);
    static_assert(is_same<M25, u8_25>);
    static_assert(is_same<M27, u8_27>);
    static_assert(is_same<M28, u8_28>);
    static_assert(is_same<M30, u8_30>);
    static_assert(is_same<M32, u8_32>);
    static_assert(is_same<M35, u8_35>);
    static_assert(is_same<M36, u8_36>);
    static_assert(is_same<M40, u8_40>);
    static_assert(is_same<M42, u8_42>);
    static_assert(is_same<M45, u8_45>);
    static_assert(is_same<M48, u8_48>);
    static_assert(is_same<M49, u8_49>);
    static_assert(is_same<M54, u8_54>);
    static_assert(is_same<M56, u8_56>);
    static_assert(is_same<M63, u8_63>);
    static_assert(is_same<M64, u8_64>);
} // namespace bigunsigned_mul_tests
