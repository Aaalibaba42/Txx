#pragma once

#include "casts/big_unsigned.hh"
#include "list/list.hh"
#include "list/ops/drop.hh"
#include "list/ops/take.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_take_drop_tests
{
    // Take tests
    using _t0 = AssertEq<Take_v<bu0, List<>>, List<>>::result;
    using _t1 = AssertEq<Take_v<bu0, List<bu1, bu2, bu3>>, List<>>::result;
    using _t2 = AssertEq<Take_v<bu1, List<bu1, bu2, bu3>>, List<bu1>>::result;
    using _t3 =
        AssertEq<Take_v<bu2, List<bu1, bu2, bu3>>, List<bu1, bu2>>::result;
    using _t4 =
        AssertEq<Take_v<bu3, List<bu1, bu2, bu3>>, List<bu1, bu2, bu3>>::result;
    using _t5 =
        AssertEq<Take_v<bu5, List<bu1, bu2, bu3>>, List<bu1, bu2, bu3>>::result;
    using _t6 = AssertEq<Take_v<bu2, List<bu5, bu10, bu15, bu20>>,
                         List<bu5, bu10>>::result;

    // Drop tests
    using _t7 = AssertEq<Drop_v<bu0, List<>>, List<>>::result;
    using _t8 =
        AssertEq<Drop_v<bu0, List<bu1, bu2, bu3>>, List<bu1, bu2, bu3>>::result;
    using _t9 =
        AssertEq<Drop_v<bu1, List<bu1, bu2, bu3>>, List<bu2, bu3>>::result;
    using _t10 = AssertEq<Drop_v<bu2, List<bu1, bu2, bu3>>, List<bu3>>::result;
    using _t11 = AssertEq<Drop_v<bu3, List<bu1, bu2, bu3>>, List<>>::result;
    using _t12 = AssertEq<Drop_v<bu5, List<bu1, bu2, bu3>>, List<>>::result;
    using _t13 = AssertEq<Drop_v<bu2, List<bu5, bu10, bu15, bu20>>,
                          List<bu15, bu20>>::result;
} // namespace list_take_drop_tests
