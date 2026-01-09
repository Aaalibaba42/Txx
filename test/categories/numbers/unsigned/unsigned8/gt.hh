#pragma once

#include "literals/bools.hh"
#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/gt.hh"

namespace unsigned8_gt_tests
{
    using _t0 = AssertEq<Gt_v<u8_1, u8_2>, False>::result;
    using _t1 = AssertEq<Gt_v<u8_1, u8_1>, False>::result;
    using _t2 = AssertEq<Gt_v<u8_2, u8_1>, True>::result;
    using _t3 = AssertEq<Gt_v<u8_10, u8_20>, False>::result;
    using _t4 = AssertEq<Gt_v<u8_10, u8_10>, False>::result;
    using _t5 = AssertEq<Gt_v<u8_20, u8_10>, True>::result;
    using _t6 = AssertEq<Gt_v<u8_63, u8_64>, False>::result;
    using _t7 = AssertEq<Gt_v<u8_64, u8_63>, True>::result;
    using _t8 = AssertEq<Gt_v<u8_50, u8_60>, False>::result;
    using _t9 = AssertEq<Gt_v<u8_50, u8_50>, False>::result;
    using _t10 = AssertEq<Gt_v<u8_60, u8_50>, True>::result;
    using _t11 = AssertEq<Gt_v<u8_0, u8_1>, False>::result;
    using _t12 = AssertEq<Gt_v<u8_0, u8_0>, False>::result;
    using _t13 = AssertEq<Gt_v<u8_1, u8_0>, True>::result;
    using _t14 = AssertEq<Gt_v<u8_64, u8_64>, False>::result;
    using _t15 = AssertEq<Gt_v<u8_10, u8_30>, False>::result;
    using _t16 = AssertEq<Gt_v<u8_30, u8_10>, True>::result;
    using _t17 = AssertEq<Gt_v<u8_32, u8_33>, False>::result;
    using _t18 = AssertEq<Gt_v<u8_33, u8_33>, False>::result;
    using _t19 = AssertEq<Gt_v<u8_33, u8_32>, True>::result;
} // namespace unsigned8_gt_tests
