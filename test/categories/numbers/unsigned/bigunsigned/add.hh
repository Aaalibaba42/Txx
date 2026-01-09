#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"

namespace bigunsigned_add_tests
{
    using A5 = Add_v<bu3, bu2>;
    using A16 = Add_v<bu8, bu8>;
    using A8 = Add_v<bu7, bu1>;
    using A1 = Add_v<bu0, bu1>;
    using A0 = Add_v<bu0, bu0>;
    using A15_1 = Add_v<bu15, bu0>;
    using A15_2 = Add_v<bu0, bu15>;
    using A16_1 = Add_v<bu15, bu1>;
    using A16_2 = Add_v<bu1, bu15>;
    using A6 = Add_v<bu2, bu4>;
    using A9 = Add_v<bu5, bu4>;
    using A11 = Add_v<bu3, bu8>;
    using A14 = Add_v<bu6, bu8>;
    using A15 = Add_v<bu7, bu8>;
    using A10 = Add_v<bu4, bu6>;
    using A13 = Add_v<bu5, bu8>;
    using A17 = Add_v<bu9, bu8>;
    using A19 = Add_v<bu11, bu8>;
    using A22 = Add_v<bu14, bu8>;
    using A25 = Add_v<bu16, bu9>;
    using A28 = Add_v<bu19, bu9>;
    using A30 = Add_v<bu20, bu10>;
    using A33 = Add_v<bu22, bu11>;
    using A35 = Add_v<bu24, bu11>;
    using A38 = Add_v<bu27, bu11>;
    using A40 = Add_v<bu30, bu10>;
    using A42 = Add_v<bu33, bu9>;
    using A45 = Add_v<bu36, bu9>;
    using A48 = Add_v<bu39, bu9>;
    using A50 = Add_v<bu41, bu9>;

    using _t0 = AssertEq<A6, bu6>::result;
    using _t1 = AssertEq<A9, bu9>::result;
    using _t2 = AssertEq<A11, bu11>::result;
    using _t3 = AssertEq<A14, bu14>::result;
    using _t4 = AssertEq<A15, bu15>::result;
    using _t5 = AssertEq<A10, bu10>::result;
    using _t6 = AssertEq<A13, bu13>::result;
    using _t7 = AssertEq<A17, bu17>::result;
    using _t8 = AssertEq<A19, bu19>::result;
    using _t9 = AssertEq<A22, bu22>::result;
    using _t10 = AssertEq<A25, bu25>::result;
    using _t11 = AssertEq<A28, bu28>::result;
    using _t12 = AssertEq<A30, bu30>::result;
    using _t13 = AssertEq<A33, bu33>::result;
    using _t14 = AssertEq<A35, bu35>::result;
    using _t15 = AssertEq<A38, bu38>::result;
    using _t16 = AssertEq<A40, bu40>::result;
    using _t17 = AssertEq<A42, bu42>::result;
    using _t18 = AssertEq<A45, bu45>::result;
    using _t19 = AssertEq<A48, bu48>::result;
    using _t20 = AssertEq<A50, bu50>::result;
    using _t21 = AssertEq<A5, bu5>::result;
    using _t22 = AssertEq<A16, bu16>::result;
    using _t23 = AssertEq<A8, bu8>::result;
    using _t24 = AssertEq<A1, bu1>::result;
    using _t25 = AssertEq<A0, bu0>::result;
    using _t26 = AssertEq<A15_1, bu15>::result;
    using _t27 = AssertEq<A15_2, bu15>::result;
    using _t28 = AssertEq<A16_1, bu16>::result;
    using _t29 = AssertEq<A16_2, bu16>::result;
} // namespace bigunsigned_add_tests
