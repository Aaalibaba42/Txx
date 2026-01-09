#pragma once

#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/left_shift.hh"

namespace unsigned8_lshift_tests
{
    using _t0 = AssertEq<LShift_v<u8_1, u8_0>, u8_1>::result;
    using _t1 = AssertEq<LShift_v<u8_1, u8_1>, u8_2>::result;
    using _t2 = AssertEq<LShift_v<u8_2, u8_2>, u8_8>::result;
    using _t3 = AssertEq<LShift_v<u8_3, u8_3>, u8_24>::result;
    using _t4 = AssertEq<LShift_v<u8_4, u8_1>, u8_8>::result;
    using _t5 = AssertEq<LShift_v<u8_5, u8_2>, u8_20>::result;
    using _t6 = AssertEq<LShift_v<u8_6, u8_1>, u8_12>::result;
    using _t7 = AssertEq<LShift_v<u8_7, u8_2>, u8_28>::result;
    using _t8 = AssertEq<LShift_v<u8_8, u8_1>, u8_16>::result;
    using _t9 = AssertEq<LShift_v<u8_9, u8_2>, u8_36>::result;
    using _t10 = AssertEq<LShift_v<u8_10, u8_1>, u8_20>::result;
    using _t11 = AssertEq<LShift_v<u8_0, u8_5>, u8_0>::result;
    using _t12 = AssertEq<LShift_v<u8_1, u8_3>, u8_8>::result;
    using _t13 = AssertEq<LShift_v<u8_2, u8_1>, u8_4>::result;
    using _t14 = AssertEq<LShift_v<u8_3, u8_2>, u8_12>::result;
    using _t15 = AssertEq<LShift_v<u8_4, u8_3>, u8_32>::result;
    using _t16 = AssertEq<LShift_v<u8_5, u8_1>, u8_10>::result;
    using _t17 = AssertEq<LShift_v<u8_6, u8_2>, u8_24>::result;
    using _t18 = AssertEq<LShift_v<u8_7, u8_1>, u8_14>::result;
    using _t19 = AssertEq<LShift_v<u8_8, u8_2>, u8_32>::result;
    using _t20 = AssertEq<LShift_v<u8_1, u8_4>, u8_16>::result;
} // namespace unsigned8_lshift_tests
