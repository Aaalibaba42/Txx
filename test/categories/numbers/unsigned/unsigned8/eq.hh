#pragma once

#include "literals/bools.hh"
#include "literals/unsigned8.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/unsigned8/ops/eq.hh"

namespace unsigned8_eq_tests
{
    using _t0 = AssertEq<Eq_v<u8_1, u8_1>, True>::result;
    using _t1 = AssertEq<Eq_v<u8_1, u8_2>, False>::result;
    using _t2 = AssertEq<Eq_v<u8_5, u8_5>, True>::result;
    using _t3 = AssertEq<Eq_v<u8_5, u8_6>, False>::result;
    using _t4 = AssertEq<Eq_v<u8_10, u8_10>, True>::result;
    using _t5 = AssertEq<Eq_v<u8_10, u8_11>, False>::result;
    using _t6 = AssertEq<Eq_v<u8_0, u8_0>, True>::result;
    using _t7 = AssertEq<Eq_v<u8_1, u8_0>, False>::result;
    using _t8 = AssertEq<Eq_v<u8_64, u8_64>, True>::result;
    using _t9 = AssertEq<Eq_v<u8_64, u8_63>, False>::result;
    using _t10 = AssertEq<Eq_v<u8_32, u8_32>, True>::result;
    using _t11 = AssertEq<Eq_v<u8_32, u8_33>, False>::result;
    using _t12 = AssertEq<Eq_v<u8_1, u8_1>, True>::result;
    using _t13 = AssertEq<Eq_v<u8_1, u8_2>, False>::result;
    using _t14 = AssertEq<Eq_v<u8_10, u8_10>, True>::result;
    using _t15 = AssertEq<Eq_v<u8_10, u8_20>, False>::result;
} // namespace unsigned8_eq_tests
