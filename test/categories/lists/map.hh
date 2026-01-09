#pragma once

#include "bools/ops/not.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "list/ops/map.hh"
#include "list/ops/reverse.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

namespace list_map_tests
{
    // Incrementation
    using _t0 = AssertEq<Map_v<IncFunc, List<bu1, bu2>>, List<bu2, bu3>>::result;

    // Boolean Not
    using _t1 = AssertEq<Map_v<NotFunc, List<True>>, List<False>>::result;
    using _t2 = AssertEq<Map_v<NotFunc, List<False>>, List<True>>::result;
    using _t3 = AssertEq<Map_v<NotFunc, List<True, False, True, True>>,
                         List<False, True, False, False>>::result;
    using _t4 = AssertEq<Map_v<NotFunc, List<>>, List<>>::result;
    using _t5 = AssertEq<Map_v<NotFunc, List<True, False, True, False>>,
                         List<False, True, False, True>>::result;

    // List Length
    using _t6 = AssertEq<Map_v<LengthFunc, List<List<>>>, List<bu0>>::result;
    using _t7 = AssertEq<Map_v<LengthFunc, List<List<bu1>, List<bu2>>>,
                         List<bu1, bu1>>::result;
    using _t8 = AssertEq<Map_v<LengthFunc, List<List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                         List<bu2, bu3>>::result;
    using _t9 = AssertEq<Map_v<LengthFunc,
                               List<List<>, List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                         List<bu0, bu2, bu3>>::result;
    using _t10 = AssertEq<
        Map_v<LengthFunc,
              List<List<bu1>, List<bu2, bu3>, List<bu4, bu5, bu6, bu7>>>,
        List<bu1, bu2, bu4>>::result;

    // List Reverse
    using _t11 = AssertEq<Map_v<ReverseFunc, List<List<>>>, List<List<>>>::result;
    using _t12 = AssertEq<Map_v<ReverseFunc, List<List<bu1>, List<bu2>>>,
                          List<List<bu1>, List<bu2>>>::result;
    using _t13 = AssertEq<Map_v<ReverseFunc, List<List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                          List<List<bu2, bu1>, List<bu8, bu5, bu3>>>::result;
    using _t14 = AssertEq<Map_v<ReverseFunc,
                                List<List<>, List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                          List<List<>, List<bu2, bu1>, List<bu8, bu5, bu3>>>::result;
    using _t15 = AssertEq<
        Map_v<ReverseFunc,
              List<List<bu1>, List<bu2, bu3>, List<bu4, bu5, bu6, bu7>>>,
        List<List<bu1>, List<bu3, bu2>, List<bu7, bu6, bu5, bu4>>>::result;
} // namespace list_map_tests
