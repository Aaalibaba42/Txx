#pragma once

#include "list/list.hh"
#include "list/ops/is_empty.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"

namespace list_is_empty_tests
{
    using _t0 = AssertEq<IsEmpty_v<List<>>, True>::result;
    using _t1 = AssertEq<IsEmpty_v<List<bu1>>, False>::result;
    using _t2 = AssertEq<IsEmpty_v<List<bu1, bu2>>, False>::result;
    using _t3 = AssertEq<IsEmpty_v<List<True>>, False>::result;
    using _t4 = AssertEq<IsEmpty_v<List<List<>>>, False>::result;
} // namespace list_is_empty_tests
