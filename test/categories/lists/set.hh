#pragma once

#include "list/list.hh"
#include "list/ops/set.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_set_tests
{
    // Fails (as expected)
    // using _err0 = AssertEq<Set_v<List<>, bu1, bu1>, List<>>::result;
    // using _err1 = AssertEq<Set_v<List<>, bu1, bu0>, List<>>::result;
    // using _err2 = AssertEq<Set_v<List<bu1>, bu2, bu1>, List<>>::result;
    // using _err3 = AssertEq<Set_v<List<bu1, bu2>, bu3, bu2>, List<>>::result;

    using _t0 = AssertEq<Set_v<List<bu1, bu2, bu3>, bu4, bu0>,
                         List<bu4, bu2, bu3>>::result;
    using _t1 = AssertEq<Set_v<List<bu1, bu2, bu3>, bu4, bu1>,
                         List<bu1, bu4, bu3>>::result;
    using _t2 = AssertEq<Set_v<List<bu1, bu2, bu3>, bu4, bu2>,
                         List<bu1, bu2, bu4>>::result;
    using _t3 = AssertEq<Set_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                         List<bu1, bu2, bu6, bu4, bu5>>::result;
    using _t4 = AssertEq<Set_v<List<bu2, bu3, bu2>, bu4, bu0>,
                         List<bu4, bu3, bu2>>::result;
    using _t5 = AssertEq<Set_v<List<bu2, bu3, bu2>, bu4, bu1>,
                         List<bu2, bu4, bu2>>::result;
    using _t6 = AssertEq<Set_v<List<bu2, bu3, bu2>, bu4, bu2>,
                         List<bu2, bu3, bu4>>::result;
    using _t7 = AssertEq<Set_v<List<bu1, bu2, bu3>, bu4, bu1>,
                         List<bu1, bu4, bu3>>::result;
    using _t8 = AssertEq<List<bu1, bu2, bu3>, List<bu1, bu2, bu3>>::result;
    using _t9 = AssertEq<Set_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                         List<bu1, bu2, bu6, bu4, bu5>>::result;
    using _t10 = AssertEq<List<bu1, bu2, bu3, bu4, bu5>,
                          List<bu1, bu2, bu3, bu4, bu5>>::result;
    using _t11 = AssertEq<Set_v<List<bu2, bu3, bu4, bu5>, bu6, bu0>,
                          List<bu6, bu3, bu4, bu5>>::result;
    using _t12 = AssertEq<Set_v<List<bu1, bu2, bu3, bu4>, bu5, bu3>,
                          List<bu1, bu2, bu3, bu5>>::result;
    using _t13 =
        AssertEq<List<bu1, bu2, bu3, bu4>, List<bu1, bu2, bu3, bu4>>::result;
    using _t14 = AssertEq<Set_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                          List<bu1, bu2, bu6, bu4, bu5>>::result;
    using _t15 = AssertEq<List<bu1, bu2, bu3, bu4, bu5>,
                          List<bu1, bu2, bu3, bu4, bu5>>::result;
} // namespace list_set_tests
