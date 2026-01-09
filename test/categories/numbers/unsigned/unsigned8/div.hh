#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/div.hh"

namespace unsigned8_div_tests
{
    // These don't fail!! division by 0 yields max u8 (for now)
    // using _err0 = AssertEq<Div_v<u8_10, u8_0>, u8_0>::result;
    // using _err1 = AssertEq<Div_v<u8_0, u8_0>, u8_0>::result;

    using _t0 = AssertEq<Div_v<u8_1, u8_2>, u8_0>::result;
    using _t1 = AssertEq<Div_v<u8_5, u8_5>, u8_1>::result;
    using _t2 = AssertEq<Div_v<u8_10, u8_2>, u8_5>::result;
    using _t3 = AssertEq<Div_v<u8_10, u8_1>, u8_10>::result;
    using _t4 = AssertEq<Div_v<u8_0, u8_5>, u8_0>::result;
    using _t5 = AssertEq<Div_v<u8_20, u8_4>, u8_5>::result;
    using _t6 = AssertEq<Div_v<u8_50, u8_10>, u8_5>::result;
    using _t7 = AssertEq<Div_v<u8_64, u8_2>, u8_32>::result;
    using _t8 = AssertEq<Div_v<u8_25, u8_3>, u8_8>::result;
    using _t9 = AssertEq<Div_v<u8_64, u8_1>, u8_64>::result;
    using _t10 = AssertEq<Div_v<u8_50, u8_25>, u8_2>::result;
    using _t11 = AssertEq<Div_v<u8_64, u8_63>, u8_1>::result;
    using _t12 = AssertEq<Div_v<u8_64, u8_16>, u8_4>::result;
    using _t13 = AssertEq<Div_v<u8_15, u8_1>, u8_15>::result;
    using _t14 = AssertEq<Div_v<u8_10, u8_3>, u8_3>::result;
    using _t15 = AssertEq<Div_v<u8_64, u8_64>, u8_1>::result;
    using _t16 = AssertEq<Div_v<u8_30, u8_7>, u8_4>::result;
    using _t17 = AssertEq<Div_v<u8_17, u8_5>, u8_3>::result;
    using _t18 = AssertEq<Div_v<u8_50, u8_26>, u8_1>::result;
    using _t19 = AssertEq<Div_v<u8_50, u8_24>, u8_2>::result;
    using _t20 = AssertEq<Div_v<u8_1, u8_64>, u8_0>::result;
    using _t21 = AssertEq<Div_v<u8_64, u8_1>, u8_64>::result;
    using _t22 = AssertEq<Div_v<u8_10, u8_20>, u8_0>::result;
    using _t23 = AssertEq<Div_v<u8_64, u8_1>, u8_64>::result;
} // namespace unsigned8_div_tests
