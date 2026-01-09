#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/right_shift.hh"

namespace unsigned8_rshift_tests
{
    using _t0 = AssertEq<RShift_v<u8_1, u8_0>, u8_1>::result;
    using _t1 = AssertEq<RShift_v<u8_2, u8_1>, u8_1>::result;
    using _t2 = AssertEq<RShift_v<u8_8, u8_2>, u8_2>::result;
    using _t3 = AssertEq<RShift_v<u8_24, u8_3>, u8_3>::result;
    using _t4 = AssertEq<RShift_v<u8_8, u8_1>, u8_4>::result;
    using _t5 = AssertEq<RShift_v<u8_20, u8_2>, u8_5>::result;
    using _t6 = AssertEq<RShift_v<u8_12, u8_1>, u8_6>::result;
    using _t7 = AssertEq<RShift_v<u8_28, u8_2>, u8_7>::result;
    using _t8 = AssertEq<RShift_v<u8_16, u8_1>, u8_8>::result;
    using _t9 = AssertEq<RShift_v<u8_36, u8_2>, u8_9>::result;
    using _t10 = AssertEq<RShift_v<u8_20, u8_1>, u8_10>::result;
    using _t11 = AssertEq<RShift_v<u8_0, u8_5>, u8_0>::result;
    using _t12 = AssertEq<RShift_v<u8_8, u8_3>, u8_1>::result;
    using _t13 = AssertEq<RShift_v<u8_4, u8_1>, u8_2>::result;
    using _t14 = AssertEq<RShift_v<u8_12, u8_2>, u8_3>::result;
    using _t15 = AssertEq<RShift_v<u8_32, u8_3>, u8_4>::result;
    using _t16 = AssertEq<RShift_v<u8_10, u8_1>, u8_5>::result;
    using _t17 = AssertEq<RShift_v<u8_24, u8_2>, u8_6>::result;
    using _t18 = AssertEq<RShift_v<u8_14, u8_1>, u8_7>::result;
    using _t19 = AssertEq<RShift_v<u8_32, u8_2>, u8_8>::result;
    using _t20 = AssertEq<RShift_v<u8_16, u8_4>, u8_1>::result;
} // namespace unsigned8_rshift_tests
