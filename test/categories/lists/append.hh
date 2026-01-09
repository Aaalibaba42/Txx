#pragma once

#include "list/list.hh"
#include "list/ops/append.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_append_tests
{
    using _t0 = AssertEq<Append_v<bu1, List<>>, List<bu1>>::result;
    using _t1 = AssertEq<Append_v<bu2, List<bu1>>, List<bu1, bu2>>::result;
    using _t2 = AssertEq<Append_v<bu4, List<bu1, bu2, bu3>>,
                         List<bu1, bu2, bu3, bu4>>::result;
    using _t3 =
        AssertEq<Append_v<bu5, List<bu2, bu4>>, List<bu2, bu4, bu5>>::result;
    using _t4 = AssertEq<Append_v<bu3, List<bu1>>, List<bu1, bu3>>::result;
    using _t5 = AssertEq<List<bu1>, List<bu1>>::result;
    using L6 = Append_v<bu3, List<bu1, bu2>>;
    using _t6 = AssertEq<L6, List<bu1, bu2, bu3>>::result;
    using _t7 = AssertEq<Append_v<bu4, L6>, List<bu1, bu2, bu3, bu4>>::result;
    using _t8 = AssertEq<Append_v<bu6, List<bu1, bu2, bu3, bu4, bu5>>,
                         List<bu1, bu2, bu3, bu4, bu5, bu6>>::result;
    using _t9 = AssertEq<Append_v<bu2, List<bu2, bu3, bu2>>,
                         List<bu2, bu3, bu2, bu2>>::result;
    using _t10 = AssertEq<Append_v<bu4, List<bu5>>, List<bu5, bu4>>::result;
    using _t11 = AssertEq<List<bu5>, List<bu5>>::result;
    using _t12 =
        AssertEq<Append_v<bu6, List<bu1, bu2>>, List<bu1, bu2, bu6>>::result;
    using _t13 = AssertEq<List<bu1, bu2>, List<bu1, bu2>>::result;
    using _t14 = AssertEq<Append_v<bu3, List<bu4, bu5, bu6>>,
                          List<bu4, bu5, bu6, bu3>>::result;
    using _t15 = AssertEq<List<bu4, bu5, bu6>, List<bu4, bu5, bu6>>::result;
    using _t16 = AssertEq<Append_v<bu1, List<bu2, bu3, bu4, bu5>>,
                          List<bu2, bu3, bu4, bu5, bu1>>::result;
    using _t17 =
        AssertEq<List<bu2, bu3, bu4, bu5>, List<bu2, bu3, bu4, bu5>>::result;
    using _t18 = AssertEq<Append_v<bu6, List<bu1, bu2, bu3, bu4, bu5>>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6>>::result;
    using _t19 = AssertEq<List<bu1, bu2, bu3, bu4, bu5>,
                          List<bu1, bu2, bu3, bu4, bu5>>::result;
    using _t20 = AssertEq<Append_v<bu2, List<bu3, bu4, bu5, bu6, bu1, bu2>>,
                          List<bu3, bu4, bu5, bu6, bu1, bu2, bu2>>::result;
    using _t21 = AssertEq<List<bu3, bu4, bu5, bu6, bu1, bu2>,
                          List<bu3, bu4, bu5, bu6, bu1, bu2>>::result;
    using _t22 =
        AssertEq<Append_v<bu4, List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>>,
                 List<bu5, bu6, bu1, bu2, bu3, bu4, bu5, bu4>>::result;
    using _t23 = AssertEq<List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>,
                          List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>>::result;
} // namespace list_append_tests
