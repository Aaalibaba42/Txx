#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"

namespace bigunsigned_sub_tests
{
    using S0_1 = Sub_v<bu1, bu1>;
    using S1 = Sub_v<bu3, bu2>;
    using S0 = Sub_v<bu8, bu8>;
    using S6 = Sub_v<bu7, bu1>;
    using S7 = Sub_v<bu8, bu1>;
    using S15 = Sub_v<bu15, bu0>;
    using S14 = Sub_v<bu15, bu1>;
    using S5 = Sub_v<bu6, bu1>;
    using S8 = Sub_v<bu10, bu2>;
    using S9 = Sub_v<bu11, bu2>;
    using S10 = Sub_v<bu12, bu2>;
    using S11 = Sub_v<bu13, bu2>;
    using S12 = Sub_v<bu14, bu2>;
    using S13 = Sub_v<bu15, bu2>;
    using S14_1 = Sub_v<bu16, bu2>;
    using S15_1 = Sub_v<bu17, bu2>;
    using S16 = Sub_v<bu18, bu2>;
    using S17 = Sub_v<bu19, bu2>;
    using S18 = Sub_v<bu20, bu2>;
    using S19 = Sub_v<bu21, bu2>;
    using S20 = Sub_v<bu22, bu2>;
    using S21 = Sub_v<bu23, bu2>;
    using S22 = Sub_v<bu24, bu2>;
    using S23 = Sub_v<bu25, bu2>;
    using S24 = Sub_v<bu26, bu2>;
    using S12b = Sub_v<bu27, bu15>;
    using S26 = Sub_v<bu28, bu2>;
    using S27 = Sub_v<bu29, bu2>;
    using S28 = Sub_v<bu30, bu2>;
    using S29 = Sub_v<bu31, bu2>;
    using S30 = Sub_v<bu32, bu2>;
    using S31 = Sub_v<bu33, bu2>;
    using S32 = Sub_v<bu34, bu2>;
    using S33 = Sub_v<bu35, bu2>;
    using S34 = Sub_v<bu36, bu2>;
    using S35 = Sub_v<bu37, bu2>;
    using S36 = Sub_v<bu38, bu2>;
    using S37 = Sub_v<bu39, bu2>;
    using S38 = Sub_v<bu40, bu2>;
    using S39 = Sub_v<bu41, bu2>;
    using S40 = Sub_v<bu42, bu2>;

    using _t0 = AssertEq<S1, bu1>::result;
    using _t1 = AssertEq<S0, bu0>::result;
    using _t2 = AssertEq<S0_1, bu0>::result;
    using _t3 = AssertEq<S6, bu6>::result;
    using _t4 = AssertEq<S7, bu7>::result;
    using _t5 = AssertEq<S15, bu15>::result;
    using _t6 = AssertEq<S14, bu14>::result;
    using _t7 = AssertEq<S5, bu5>::result;
    using _t8 = AssertEq<S8, bu8>::result;
    using _t9 = AssertEq<S9, bu9>::result;
    using _t10 = AssertEq<S10, bu10>::result;
    using _t11 = AssertEq<S11, bu11>::result;
    using _t12 = AssertEq<S12, bu12>::result;
    using _t13 = AssertEq<S13, bu13>::result;
    using _t14 = AssertEq<S14_1, bu14>::result;
    using _t15 = AssertEq<S15_1, bu15>::result;
    using _t16 = AssertEq<S16, bu16>::result;
    using _t17 = AssertEq<S17, bu17>::result;
    using _t18 = AssertEq<S18, bu18>::result;
    using _t19 = AssertEq<S19, bu19>::result;
    using _t20 = AssertEq<S20, bu20>::result;
    using _t21 = AssertEq<S21, bu21>::result;
    using _t22 = AssertEq<S22, bu22>::result;
    using _t23 = AssertEq<S23, bu23>::result;
    using _t24 = AssertEq<S24, bu24>::result;
    using _t25 = AssertEq<S12b, bu12>::result;
    using _t26 = AssertEq<S26, bu26>::result;
    using _t27 = AssertEq<S27, bu27>::result;
    using _t28 = AssertEq<S28, bu28>::result;
    using _t29 = AssertEq<S29, bu29>::result;
    using _t30 = AssertEq<S30, bu30>::result;
    using _t31 = AssertEq<S31, bu31>::result;
    using _t32 = AssertEq<S32, bu32>::result;
    using _t33 = AssertEq<S33, bu33>::result;
    using _t34 = AssertEq<S34, bu34>::result;
    using _t35 = AssertEq<S35, bu35>::result;
    using _t36 = AssertEq<S36, bu36>::result;
    using _t37 = AssertEq<S37, bu37>::result;
    using _t38 = AssertEq<S38, bu38>::result;
    using _t39 = AssertEq<S39, bu39>::result;
    using _t40 = AssertEq<S40, bu40>::result;
} // namespace bigunsigned_sub_tests
