#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace bigunsigned_mul_tests
{
    using M0 = Mul_v<bu0, bu1>;
    using M1 = Mul_v<bu1, bu1>;
    using M0_1 = Mul_v<bu0, bu0>;
    using M4 = Mul_v<bu2, bu2>;
    using M6 = Mul_v<bu2, bu3>;
    using M8 = Mul_v<bu2, bu4>;
    using M10 = Mul_v<bu2, bu5>;
    using M12 = Mul_v<bu3, bu4>;
    using M14 = Mul_v<bu2, bu7>;
    using M15 = Mul_v<bu3, bu5>;
    using M16 = Mul_v<bu4, bu4>;
    using M18 = Mul_v<bu3, bu6>;
    using M20 = Mul_v<bu4, bu5>;
    using M21 = Mul_v<bu3, bu7>;
    using M24 = Mul_v<bu3, bu8>;
    using M25 = Mul_v<bu5, bu5>;
    using M27 = Mul_v<bu3, bu9>;
    using M28 = Mul_v<bu4, bu7>;
    using M30 = Mul_v<bu5, bu6>;
    using M32 = Mul_v<bu4, bu8>;
    using M35 = Mul_v<bu5, bu7>;
    using M36 = Mul_v<bu4, bu9>;
    using M40 = Mul_v<bu5, bu8>;
    using M42 = Mul_v<bu6, bu7>;
    using M45 = Mul_v<bu5, bu9>;
    using M48 = Mul_v<bu6, bu8>;
    using M49 = Mul_v<bu7, bu7>;
    using M54 = Mul_v<bu6, bu9>;
    using M56 = Mul_v<bu7, bu8>;
    using M63 = Mul_v<bu7, bu9>;
    using M64 = Mul_v<bu8, bu8>;

    using _t0 = AssertEq<M0, bu0>::result;
    using _t1 = AssertEq<M1, bu1>::result;
    using _t2 = AssertEq<M0_1, bu0>::result;
    using _t3 = AssertEq<M4, bu4>::result;
    using _t4 = AssertEq<M6, bu6>::result;
    using _t5 = AssertEq<M8, bu8>::result;
    using _t6 = AssertEq<M10, bu10>::result;
    using _t7 = AssertEq<M12, bu12>::result;
    using _t8 = AssertEq<M14, bu14>::result;
    using _t9 = AssertEq<M15, bu15>::result;
    using _t10 = AssertEq<M16, bu16>::result;
    using _t11 = AssertEq<M18, bu18>::result;
    using _t12 = AssertEq<M20, bu20>::result;
    using _t13 = AssertEq<M21, bu21>::result;
    using _t14 = AssertEq<M24, bu24>::result;
    using _t15 = AssertEq<M25, bu25>::result;
    using _t16 = AssertEq<M27, bu27>::result;
    using _t17 = AssertEq<M28, bu28>::result;
    using _t18 = AssertEq<M30, bu30>::result;
    using _t19 = AssertEq<M32, bu32>::result;
    using _t20 = AssertEq<M35, bu35>::result;
    using _t21 = AssertEq<M36, bu36>::result;
    using _t22 = AssertEq<M40, bu40>::result;
    using _t23 = AssertEq<M42, bu42>::result;
    using _t24 = AssertEq<M45, bu45>::result;
    using _t25 = AssertEq<M48, bu48>::result;
    using _t26 = AssertEq<M49, bu49>::result;
    using _t27 = AssertEq<M54, bu54>::result;
    using _t28 = AssertEq<M56, bu56>::result;
    using _t29 = AssertEq<M63, bu63>::result;
    using _t30 = AssertEq<M64, bu64>::result;
} // namespace bigunsigned_mul_tests
