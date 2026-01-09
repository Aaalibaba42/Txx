#pragma once

#include "list/list.hh"
#include "list/ops/concat.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_concat_tests
{
    using _t0 = AssertEq<Concat_v<List<>, List<>>, List<>>::result;
    using _t1 = AssertEq<Concat_v<List<bu1>, List<>>, List<bu1>>::result;
    using _t2 = AssertEq<Concat_v<List<>, List<bu1>>, List<bu1>>::result;
    using _t3 =
        AssertEq<Concat_v<List<bu1>, List<bu2>>, List<bu1, bu2>>::result;
    using _t4 = AssertEq<Concat_v<List<bu1, bu2>, List<bu3>>,
                         List<bu1, bu2, bu3>>::result;
    using _t5 = AssertEq<Concat_v<List<bu1>, List<bu2, bu3>>,
                         List<bu1, bu2, bu3>>::result;
    using _t6 = AssertEq<Concat_v<List<bu1, bu2>, List<bu3, bu4>>,
                         List<bu1, bu2, bu3, bu4>>::result;
    using _t7 = AssertEq<Concat_v<List<bu1, bu2, bu3>, List<bu4, bu5, bu6>>,
                         List<bu1, bu2, bu3, bu4, bu5, bu6>>::result;
} // namespace list_concat_tests
