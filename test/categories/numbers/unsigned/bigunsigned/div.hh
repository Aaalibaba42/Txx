#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/div.hh"

namespace bigunsigned_div_tests
{
    // Fails (as expected)
    // using _err0 = AssertEq<Div_v<bu10, bu0>, bu0>::result;
    // using _err1 = AssertEq<Div_v<bu0, bu0>, bu0>::result;

    using _t0 = AssertEq<Div_v<bu1, bu2>, bu0>::result;
    using _t1 = AssertEq<Div_v<bu5, bu5>, bu1>::result;
    using _t2 = AssertEq<Div_v<bu10, bu2>, bu5>::result;
    using _t3 = AssertEq<Div_v<bu10, bu1>, bu10>::result;
    using _t4 = AssertEq<Div_v<bu0, bu5>, bu0>::result;
    using _t5 = AssertEq<Div_v<bu20, bu4>, bu5>::result;
    using _t6 = AssertEq<Div_v<bu50, bu10>, bu5>::result;
    using _t7 = AssertEq<Div_v<bu64, bu2>, bu32>::result;
    using _t8 = AssertEq<Div_v<bu25, bu3>, bu8>::result;
    using _t9 = AssertEq<Div_v<bu64, bu1>, bu64>::result;
    using _t10 = AssertEq<Div_v<bu50, bu25>, bu2>::result;
    using _t11 = AssertEq<Div_v<bu64, bu63>, bu1>::result;
    using _t12 = AssertEq<Div_v<bu64, bu16>, bu4>::result;
    using _t13 = AssertEq<Div_v<bu15, bu1>, bu15>::result;
    using _t14 = AssertEq<Div_v<bu10, bu3>, bu3>::result;
    using _t15 = AssertEq<Div_v<bu64, bu64>, bu1>::result;
    using _t16 = AssertEq<Div_v<bu30, bu7>, bu4>::result;
    using _t17 = AssertEq<Div_v<bu17, bu5>, bu3>::result;
    using _t18 = AssertEq<Div_v<bu50, bu26>, bu1>::result;
    using _t19 = AssertEq<Div_v<bu50, bu24>, bu2>::result;
    using _t20 = AssertEq<Div_v<bu1, bu64>, bu0>::result;
    using _t21 = AssertEq<Div_v<bu64, bu1>, bu64>::result;
    using _t22 = AssertEq<Div_v<bu10, bu20>, bu0>::result;
    using _t23 = AssertEq<Div_v<bu64, bu1>, bu64>::result;
} // namespace bigunsigned_div_tests
