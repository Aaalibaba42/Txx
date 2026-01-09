#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/mul.hh"

namespace unsigned8_mul_tests
{
    using M0 = Mul_v<u8_0, u8_1>;
    using M1 = Mul_v<u8_1, u8_1>;
    using M0_1 = Mul_v<u8_0, u8_0>;
    using M4 = Mul_v<u8_2, u8_2>;
    using M6 = Mul_v<u8_2, u8_3>;
    using M8 = Mul_v<u8_2, u8_4>;
    using M10 = Mul_v<u8_2, u8_5>;
    using M12 = Mul_v<u8_3, u8_4>;
    using M14 = Mul_v<u8_2, u8_7>;
    using M15 = Mul_v<u8_3, u8_5>;
    using M16 = Mul_v<u8_4, u8_4>;
    using M18 = Mul_v<u8_3, u8_6>;
    using M20 = Mul_v<u8_4, u8_5>;
    using M21 = Mul_v<u8_3, u8_7>;
    using M24 = Mul_v<u8_3, u8_8>;
    using M25 = Mul_v<u8_5, u8_5>;
    using M27 = Mul_v<u8_3, u8_9>;
    using M28 = Mul_v<u8_4, u8_7>;
    using M30 = Mul_v<u8_5, u8_6>;
    using M32 = Mul_v<u8_4, u8_8>;
    using M35 = Mul_v<u8_5, u8_7>;
    using M36 = Mul_v<u8_4, u8_9>;
    using M40 = Mul_v<u8_5, u8_8>;
    using M42 = Mul_v<u8_6, u8_7>;
    using M45 = Mul_v<u8_5, u8_9>;
    using M48 = Mul_v<u8_6, u8_8>;
    using M49 = Mul_v<u8_7, u8_7>;
    using M54 = Mul_v<u8_6, u8_9>;
    using M56 = Mul_v<u8_7, u8_8>;
    using M63 = Mul_v<u8_7, u8_9>;
    using M64 = Mul_v<u8_8, u8_8>;

    using _t0 = AssertEq<M0, u8_0>::result;
    using _t1 = AssertEq<M1, u8_1>::result;
    using _t2 = AssertEq<M0_1, u8_0>::result;
    using _t3 = AssertEq<M4, u8_4>::result;
    using _t4 = AssertEq<M6, u8_6>::result;
    using _t5 = AssertEq<M8, u8_8>::result;
    using _t6 = AssertEq<M10, u8_10>::result;
    using _t7 = AssertEq<M12, u8_12>::result;
    using _t8 = AssertEq<M14, u8_14>::result;
    using _t9 = AssertEq<M15, u8_15>::result;
    using _t10 = AssertEq<M16, u8_16>::result;
    using _t11 = AssertEq<M18, u8_18>::result;
    using _t12 = AssertEq<M20, u8_20>::result;
    using _t13 = AssertEq<M21, u8_21>::result;
    using _t14 = AssertEq<M24, u8_24>::result;
    using _t15 = AssertEq<M25, u8_25>::result;
    using _t16 = AssertEq<M27, u8_27>::result;
    using _t17 = AssertEq<M28, u8_28>::result;
    using _t18 = AssertEq<M30, u8_30>::result;
    using _t19 = AssertEq<M32, u8_32>::result;
    using _t20 = AssertEq<M35, u8_35>::result;
    using _t21 = AssertEq<M36, u8_36>::result;
    using _t22 = AssertEq<M40, u8_40>::result;
    using _t23 = AssertEq<M42, u8_42>::result;
    using _t24 = AssertEq<M45, u8_45>::result;
    using _t25 = AssertEq<M48, u8_48>::result;
    using _t26 = AssertEq<M49, u8_49>::result;
    using _t27 = AssertEq<M54, u8_54>::result;
    using _t28 = AssertEq<M56, u8_56>::result;
    using _t29 = AssertEq<M63, u8_63>::result;
    using _t30 = AssertEq<M64, u8_64>::result;
} // namespace unsigned8_mul_tests
