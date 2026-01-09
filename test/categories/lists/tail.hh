#pragma once

#include "list/list.hh"
#include "list/ops/tail.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"

namespace list_tail_tests
{
    using _t0 = AssertEq<Tail_v<List<bu1>>, List<>>::result;
    using _t1 = AssertEq<Tail_v<List<bu1, bu2>>, List<bu2>>::result;
    using _t2 = AssertEq<Tail_v<List<bu1, bu2, bu3>>, List<bu2, bu3>>::result;
    using _t3 = AssertEq<Tail_v<List<bu5, bu2, bu4>>, List<bu2, bu4>>::result;
    using _t4 = AssertEq<Tail_v<List<True, False>>, List<False>>::result;
    using _t5 = AssertEq<Tail_v<List<List<bu1>, bu2>>, List<bu2>>::result;
} // namespace list_tail_tests
