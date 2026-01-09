#pragma once

#include "literals/bools.hh"
#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/ge.hh"

namespace unsigned8_ge_tests
{
    using _t0 = AssertEq<Ge_v<u8_1, u8_2>, False>::result;
    using _t1 = AssertEq<Ge_v<u8_1, u8_1>, True>::result;
    using _t2 = AssertEq<Ge_v<u8_2, u8_1>, True>::result;
    using _t3 = AssertEq<Ge_v<u8_10, u8_20>, False>::result;
    using _t4 = AssertEq<Ge_v<u8_10, u8_10>, True>::result;
    using _t5 = AssertEq<Ge_v<u8_20, u8_10>, True>::result;
    using _t6 = AssertEq<Ge_v<u8_63, u8_64>, False>::result;
    using _t7 = AssertEq<Ge_v<u8_64, u8_63>, True>::result;
    using _t8 = AssertEq<Ge_v<u8_50, u8_60>, False>::result;
    using _t9 = AssertEq<Ge_v<u8_50, u8_50>, True>::result;
    using _t10 = AssertEq<Ge_v<u8_60, u8_50>, True>::result;
    using _t11 = AssertEq<Ge_v<u8_0, u8_1>, False>::result;
    using _t12 = AssertEq<Ge_v<u8_0, u8_0>, True>::result;
    using _t13 = AssertEq<Ge_v<u8_1, u8_0>, True>::result;
    using _t14 = AssertEq<Ge_v<u8_64, u8_64>, True>::result;
    using _t15 = AssertEq<Ge_v<u8_10, u8_30>, False>::result;
    using _t16 = AssertEq<Ge_v<u8_30, u8_10>, True>::result;
    using _t17 = AssertEq<Ge_v<u8_32, u8_33>, False>::result;
    using _t18 = AssertEq<Ge_v<u8_33, u8_33>, True>::result;
    using _t19 = AssertEq<Ge_v<u8_33, u8_32>, True>::result;
} // namespace unsigned8_ge_tests
