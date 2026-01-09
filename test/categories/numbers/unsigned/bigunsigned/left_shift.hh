#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/left_shift.hh"

namespace bigunsigned_lshift_tests
{
    using _t0 = AssertEq<LShift_v<bu1, bu0>, bu1>::result;
    using _t1 = AssertEq<LShift_v<bu1, bu1>, bu2>::result;
    using _t2 = AssertEq<LShift_v<bu2, bu2>, bu8>::result;
    using _t3 = AssertEq<LShift_v<bu3, bu3>, bu24>::result;
    using _t4 = AssertEq<LShift_v<bu4, bu1>, bu8>::result;
    using _t5 = AssertEq<LShift_v<bu5, bu2>, bu20>::result;
    using _t6 = AssertEq<LShift_v<bu6, bu1>, bu12>::result;
    using _t7 = AssertEq<LShift_v<bu7, bu2>, bu28>::result;
    using _t8 = AssertEq<LShift_v<bu8, bu1>, bu16>::result;
    using _t9 = AssertEq<LShift_v<bu9, bu2>, bu36>::result;
    using _t10 = AssertEq<LShift_v<bu10, bu1>, bu20>::result;
    using _t11 = AssertEq<LShift_v<bu0, bu5>, bu0>::result;
    using _t12 = AssertEq<LShift_v<bu1, bu3>, bu8>::result;
    using _t13 = AssertEq<LShift_v<bu2, bu1>, bu4>::result;
    using _t14 = AssertEq<LShift_v<bu3, bu2>, bu12>::result;
    using _t15 = AssertEq<LShift_v<bu4, bu3>, bu32>::result;
    using _t16 = AssertEq<LShift_v<bu5, bu1>, bu10>::result;
    using _t17 = AssertEq<LShift_v<bu6, bu2>, bu24>::result;
    using _t18 = AssertEq<LShift_v<bu7, bu1>, bu14>::result;
    using _t19 = AssertEq<LShift_v<bu8, bu2>, bu32>::result;
    using _t20 = AssertEq<LShift_v<bu1, bu4>, bu16>::result;
} // namespace bigunsigned_lshift_tests
