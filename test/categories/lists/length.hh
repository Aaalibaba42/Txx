#pragma once

#include "list/list.hh"
#include "list/ops/length.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_legth_tests
{
    using _t0 = AssertEq<Length_v<List<>>, bu0>::result;
    using _t1 = AssertEq<Length_v<List<bu1>>, bu1>::result;
    using _t2 = AssertEq<Length_v<List<bu1, bu2>>, bu2>::result;
    using _t3 = AssertEq<Length_v<List<bu1, bu2, bu3, bu4>>, bu4>::result;
    using _t4 = AssertEq<Length_v<List<bu2, bu3, bu2>>, bu3>::result;
    using _t5 =
        AssertEq<Length_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>, bu6>::result;
    using _t6 = AssertEq<Length_v<List<bu5>>, bu1>::result;
    using _t7 = AssertEq<Length_v<List<bu1, bu2>>, bu2>::result;
    using _t8 = AssertEq<Length_v<List<bu3, bu4, bu5>>, bu3>::result;
    using _t9 = AssertEq<Length_v<List<bu2, bu3, bu4, bu5>>, bu4>::result;
    using _t10 = AssertEq<Length_v<List<bu1, bu2, bu3, bu4, bu5>>, bu5>::result;
    using _t11 =
        AssertEq<Length_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>, bu6>::result;
    using _t12 = AssertEq<Length_v<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>,
                          bu7>::result;
    using _t13 =
        AssertEq<Length_v<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>,
                 bu8>::result;
    using _t14 =
        AssertEq<Length_v<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>,
                 bu9>::result;
} // namespace list_legth_tests
