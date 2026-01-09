#pragma once

#include "list/list.hh"
#include "list/ops/head.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"

namespace list_head_tests
{
    using _t0 = AssertEq<Head_v<List<bu1>>, bu1>::result;
    using _t1 = AssertEq<Head_v<List<bu1, bu2>>, bu1>::result;
    using _t2 = AssertEq<Head_v<List<bu1, bu2, bu3>>, bu1>::result;
    using _t3 = AssertEq<Head_v<List<bu5, bu2, bu4>>, bu5>::result;
    using _t4 = AssertEq<Head_v<List<True>>, True>::result;
    using _t5 = AssertEq<Head_v<List<False, True>>, False>::result;
    using _t6 = AssertEq<Head_v<List<List<bu1, bu2>>>, List<bu1, bu2>>::result;
    using _t7 = AssertEq<Head_v<List<List<>, bu1>>, List<>>::result;
} // namespace list_head_tests
