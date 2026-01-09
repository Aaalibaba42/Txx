#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/add.hh"

namespace unsigned8_add_tests
{
    using A5 = Add_v<u8_3, u8_2>;
    using A16 = Add_v<u8_8, u8_8>;
    using A8 = Add_v<u8_7, u8_1>;
    using A1 = Add_v<u8_0, u8_1>;
    using A0 = Add_v<u8_0, u8_0>;
    using A15_1 = Add_v<u8_15, u8_0>;
    using A15_2 = Add_v<u8_0, u8_15>;
    using A16_1 = Add_v<u8_15, u8_1>;
    using A16_2 = Add_v<u8_1, u8_15>;
    using A6 = Add_v<u8_2, u8_4>;
    using A9 = Add_v<u8_5, u8_4>;
    using A11 = Add_v<u8_3, u8_8>;
    using A14 = Add_v<u8_6, u8_8>;
    using A15 = Add_v<u8_7, u8_8>;
    using A10 = Add_v<u8_4, u8_6>;
    using A13 = Add_v<u8_5, u8_8>;
    using A17 = Add_v<u8_9, u8_8>;
    using A19 = Add_v<u8_11, u8_8>;
    using A22 = Add_v<u8_14, u8_8>;
    using A25 = Add_v<u8_16, u8_9>;
    using A28 = Add_v<u8_19, u8_9>;
    using A30 = Add_v<u8_20, u8_10>;
    using A33 = Add_v<u8_22, u8_11>;
    using A35 = Add_v<u8_24, u8_11>;
    using A38 = Add_v<u8_27, u8_11>;
    using A40 = Add_v<u8_30, u8_10>;
    using A42 = Add_v<u8_33, u8_9>;
    using A45 = Add_v<u8_36, u8_9>;
    using A48 = Add_v<u8_39, u8_9>;
    using A50 = Add_v<u8_41, u8_9>;

    using _t0 = AssertEq<A6, u8_6>::result;
    using _t1 = AssertEq<A9, u8_9>::result;
    using _t2 = AssertEq<A11, u8_11>::result;
    using _t3 = AssertEq<A14, u8_14>::result;
    using _t4 = AssertEq<A15, u8_15>::result;
    using _t5 = AssertEq<A10, u8_10>::result;
    using _t6 = AssertEq<A13, u8_13>::result;
    using _t7 = AssertEq<A17, u8_17>::result;
    using _t8 = AssertEq<A19, u8_19>::result;
    using _t9 = AssertEq<A22, u8_22>::result;
    using _t10 = AssertEq<A25, u8_25>::result;
    using _t11 = AssertEq<A28, u8_28>::result;
    using _t12 = AssertEq<A30, u8_30>::result;
    using _t13 = AssertEq<A33, u8_33>::result;
    using _t14 = AssertEq<A35, u8_35>::result;
    using _t15 = AssertEq<A38, u8_38>::result;
    using _t16 = AssertEq<A40, u8_40>::result;
    using _t17 = AssertEq<A42, u8_42>::result;
    using _t18 = AssertEq<A45, u8_45>::result;
    using _t19 = AssertEq<A48, u8_48>::result;
    using _t20 = AssertEq<A50, u8_50>::result;
    using _t21 = AssertEq<A5, u8_5>::result;
    using _t22 = AssertEq<A16, u8_16>::result;
    using _t23 = AssertEq<A8, u8_8>::result;
    using _t24 = AssertEq<A1, u8_1>::result;
    using _t25 = AssertEq<A0, u8_0>::result;
    using _t26 = AssertEq<A15_1, u8_15>::result;
    using _t27 = AssertEq<A15_2, u8_15>::result;
    using _t28 = AssertEq<A16_1, u8_16>::result;
    using _t29 = AssertEq<A16_2, u8_16>::result;
} // namespace unsigned8_add_tests
