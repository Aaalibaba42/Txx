#pragma once

#include "list/list.hh"
#include "list/ops/nth.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"

namespace list_nth_tests
{
    using _t0 = AssertEq<Nth_v<List<bu1>, bu0>, bu1>::result;
    using _t1 = AssertEq<Nth_v<List<bu1, bu2>, bu0>, bu1>::result;
    using _t2 = AssertEq<Nth_v<List<bu1, bu2>, bu1>, bu2>::result;
    using _t3 = AssertEq<Nth_v<List<bu1, bu2, bu3>, bu0>, bu1>::result;
    using _t4 = AssertEq<Nth_v<List<bu1, bu2, bu3>, bu1>, bu2>::result;
    using _t5 = AssertEq<Nth_v<List<bu1, bu2, bu3>, bu2>, bu3>::result;
    using _t6 = AssertEq<Nth_v<List<bu5, bu10, bu15, bu20>, bu3>, bu20>::result;
    using _t7 = AssertEq<Nth_v<List<True, False, True>, bu1>, False>::result;
    using _t8 =
        AssertEq<Nth_v<List<List<bu1>, List<bu2>>, bu1>, List<bu2>>::result;
} // namespace list_nth_tests
