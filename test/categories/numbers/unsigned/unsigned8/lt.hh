#pragma once

#include "literals/bools.hh"
#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/lt.hh"

namespace unsigned8_lt_tests
{
    using _t0 = AssertEq<Lt_v<u8_1, u8_2>, True>::result;
    using _t1 = AssertEq<Lt_v<u8_1, u8_1>, False>::result;
    using _t2 = AssertEq<Lt_v<u8_2, u8_1>, False>::result;
    using _t3 = AssertEq<Lt_v<u8_10, u8_20>, True>::result;
    using _t4 = AssertEq<Lt_v<u8_10, u8_10>, False>::result;
    using _t5 = AssertEq<Lt_v<u8_20, u8_10>, False>::result;
    using _t6 = AssertEq<Lt_v<u8_63, u8_64>, True>::result;
    using _t7 = AssertEq<Lt_v<u8_64, u8_63>, False>::result;
    using _t8 = AssertEq<Lt_v<u8_50, u8_60>, True>::result;
    using _t9 = AssertEq<Lt_v<u8_50, u8_50>, False>::result;
    using _t10 = AssertEq<Lt_v<u8_60, u8_50>, False>::result;
    using _t11 = AssertEq<Lt_v<u8_0, u8_1>, True>::result;
    using _t12 = AssertEq<Lt_v<u8_0, u8_0>, False>::result;
    using _t13 = AssertEq<Lt_v<u8_1, u8_0>, False>::result;
    using _t14 = AssertEq<Lt_v<u8_64, u8_64>, False>::result;
    using _t15 = AssertEq<Lt_v<u8_10, u8_30>, True>::result;
    using _t16 = AssertEq<Lt_v<u8_30, u8_10>, False>::result;
    using _t17 = AssertEq<Lt_v<u8_32, u8_33>, True>::result;
    using _t18 = AssertEq<Lt_v<u8_33, u8_33>, False>::result;
    using _t19 = AssertEq<Lt_v<u8_33, u8_32>, False>::result;
} // namespace unsigned8_lt_tests
