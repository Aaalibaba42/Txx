#pragma once

#include "list/list.hh"
#include "list/ops/reverse.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_reverse_tests
{
    using _t0 = AssertEq<Reverse_v<List<>>, List<>>::result;
    using _t1 = AssertEq<Reverse_v<List<bu1>>, List<bu1>>::result;
    using _t2 = AssertEq<Reverse_v<List<bu1, bu2>>, List<bu2, bu1>>::result;
    using _t3 = AssertEq<Reverse_v<List<bu1, bu2, bu3, bu4>>, List<bu4, bu3, bu2, bu1>>::result;
    using _t4 = AssertEq<Reverse_v<List<bu2, bu3, bu2>>, List<bu2, bu3, bu2>>::result;
    using _t5 = AssertEq<Reverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>,
                         List<bu6, bu5, bu4, bu3, bu2, bu1>>::result;
    using _t6 = AssertEq<Reverse_v<List<bu5>>, List<bu5>>::result;
    using _t7 = AssertEq<List<bu5>, List<bu5>>::result;
    using _t8 = AssertEq<Reverse_v<List<bu1, bu2>>, List<bu2, bu1>>::result;
    using _t9 = AssertEq<List<bu1, bu2>, List<bu1, bu2>>::result;
    using _t10 = AssertEq<Reverse_v<List<bu3, bu4, bu5>>, List<bu5, bu4, bu3>>::result;
    using _t11 = AssertEq<List<bu3, bu4, bu5>, List<bu3, bu4, bu5>>::result;
    using _t12 = AssertEq<Reverse_v<List<bu2, bu3, bu4, bu5>>, List<bu5, bu4, bu3, bu2>>::result;
    using _t13 = AssertEq<List<bu2, bu3, bu4, bu5>, List<bu2, bu3, bu4, bu5>>::result;
    using _t14 = AssertEq<Reverse_v<List<bu1, bu2, bu3, bu4, bu5>>,
                          List<bu5, bu4, bu3, bu2, bu1>>::result;
    using _t15 = AssertEq<List<bu1, bu2, bu3, bu4, bu5>, List<bu1, bu2, bu3, bu4, bu5>>::result;
    using _t16 = AssertEq<Reverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>,
                          List<bu6, bu5, bu4, bu3, bu2, bu1>>::result;
    using _t17 = AssertEq<List<bu1, bu2, bu3, bu4, bu5, bu6>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6>>::result;
    using _t18 = AssertEq<Reverse_v<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>,
                          List<bu7, bu6, bu1, bu2, bu3, bu4, bu5>>::result;
    using _t19 = AssertEq<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>,
                          List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>::result;
    using _t20 = AssertEq<Reverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>,
                          List<bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>::result;
    using _t21 = AssertEq<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>::result;
    using _t22 = AssertEq<Reverse_v<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8, bu9>>::result;
    using _t23 = AssertEq<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>,
                          List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>::result;
} // namespace list_reverse_tests
