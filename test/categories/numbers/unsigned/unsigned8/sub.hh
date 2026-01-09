#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/sub.hh"

namespace unsigned8_sub_tests
{
    using S0_1 = Sub_v<u8_1, u8_1>;
    using S1 = Sub_v<u8_3, u8_2>;
    using S0 = Sub_v<u8_8, u8_8>;
    using S6 = Sub_v<u8_7, u8_1>;
    using S7 = Sub_v<u8_8, u8_1>;
    using S15 = Sub_v<u8_15, u8_0>;
    using S14 = Sub_v<u8_15, u8_1>;
    using S5 = Sub_v<u8_6, u8_1>;
    using S8 = Sub_v<u8_10, u8_2>;
    using S9 = Sub_v<u8_11, u8_2>;
    using S10 = Sub_v<u8_12, u8_2>;
    using S11 = Sub_v<u8_13, u8_2>;
    using S12 = Sub_v<u8_14, u8_2>;
    using S13 = Sub_v<u8_15, u8_2>;
    using S14_1 = Sub_v<u8_16, u8_2>;
    using S15_1 = Sub_v<u8_17, u8_2>;
    using S16 = Sub_v<u8_18, u8_2>;
    using S17 = Sub_v<u8_19, u8_2>;
    using S18 = Sub_v<u8_20, u8_2>;
    using S19 = Sub_v<u8_21, u8_2>;
    using S20 = Sub_v<u8_22, u8_2>;
    using S21 = Sub_v<u8_23, u8_2>;
    using S22 = Sub_v<u8_24, u8_2>;
    using S23 = Sub_v<u8_25, u8_2>;
    using S24 = Sub_v<u8_26, u8_2>;
    using S12b = Sub_v<u8_27, u8_15>;
    using S26 = Sub_v<u8_28, u8_2>;
    using S27 = Sub_v<u8_29, u8_2>;
    using S28 = Sub_v<u8_30, u8_2>;
    using S29 = Sub_v<u8_31, u8_2>;
    using S30 = Sub_v<u8_32, u8_2>;
    using S31 = Sub_v<u8_33, u8_2>;
    using S32 = Sub_v<u8_34, u8_2>;
    using S33 = Sub_v<u8_35, u8_2>;
    using S34 = Sub_v<u8_36, u8_2>;
    using S35 = Sub_v<u8_37, u8_2>;
    using S36 = Sub_v<u8_38, u8_2>;
    using S37 = Sub_v<u8_39, u8_2>;
    using S38 = Sub_v<u8_40, u8_2>;
    using S39 = Sub_v<u8_41, u8_2>;
    using S40 = Sub_v<u8_42, u8_2>;

    using _t0 = AssertEq<S1, u8_1>::result;
    using _t1 = AssertEq<S0, u8_0>::result;
    using _t2 = AssertEq<S0_1, u8_0>::result;
    using _t3 = AssertEq<S6, u8_6>::result;
    using _t4 = AssertEq<S7, u8_7>::result;
    using _t5 = AssertEq<S15, u8_15>::result;
    using _t6 = AssertEq<S14, u8_14>::result;
    using _t7 = AssertEq<S5, u8_5>::result;
    using _t8 = AssertEq<S8, u8_8>::result;
    using _t9 = AssertEq<S9, u8_9>::result;
    using _t10 = AssertEq<S10, u8_10>::result;
    using _t11 = AssertEq<S11, u8_11>::result;
    using _t12 = AssertEq<S12, u8_12>::result;
    using _t13 = AssertEq<S13, u8_13>::result;
    using _t14 = AssertEq<S14_1, u8_14>::result;
    using _t15 = AssertEq<S15_1, u8_15>::result;
    using _t16 = AssertEq<S16, u8_16>::result;
    using _t17 = AssertEq<S17, u8_17>::result;
    using _t18 = AssertEq<S18, u8_18>::result;
    using _t19 = AssertEq<S19, u8_19>::result;
    using _t20 = AssertEq<S20, u8_20>::result;
    using _t21 = AssertEq<S21, u8_21>::result;
    using _t22 = AssertEq<S22, u8_22>::result;
    using _t23 = AssertEq<S23, u8_23>::result;
    using _t24 = AssertEq<S24, u8_24>::result;
    using _t25 = AssertEq<S12b, u8_12>::result;
    using _t26 = AssertEq<S26, u8_26>::result;
    using _t27 = AssertEq<S27, u8_27>::result;
    using _t28 = AssertEq<S28, u8_28>::result;
    using _t29 = AssertEq<S29, u8_29>::result;
    using _t30 = AssertEq<S30, u8_30>::result;
    using _t31 = AssertEq<S31, u8_31>::result;
    using _t32 = AssertEq<S32, u8_32>::result;
    using _t33 = AssertEq<S33, u8_33>::result;
    using _t34 = AssertEq<S34, u8_34>::result;
    using _t35 = AssertEq<S35, u8_35>::result;
    using _t36 = AssertEq<S36, u8_36>::result;
    using _t37 = AssertEq<S37, u8_37>::result;
    using _t38 = AssertEq<S38, u8_38>::result;
    using _t39 = AssertEq<S39, u8_39>::result;
    using _t40 = AssertEq<S40, u8_40>::result;
} // namespace unsigned8_sub_tests
