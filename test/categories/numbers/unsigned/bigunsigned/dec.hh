#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/dec.hh"

namespace bigunsigned_decrement_tests
{
    // I'd rather say that's UB but it works that way if you're wondering:
    // using _t0 = AssertEq<Dec_v<bu0>, bu0>::result;

    using _t1 = AssertEq<Dec_v<bu1>, bu0>::result;
    using _t2 = AssertEq<Dec_v<bu2>, bu1>::result;
    using _t3 = AssertEq<Dec_v<bu3>, bu2>::result;
    using _t4 = AssertEq<Dec_v<bu4>, bu3>::result;
    using _t5 = AssertEq<Dec_v<bu5>, bu4>::result;
    using _t6 = AssertEq<Dec_v<bu6>, bu5>::result;
    using _t7 = AssertEq<Dec_v<bu7>, bu6>::result;
    using _t8 = AssertEq<Dec_v<bu8>, bu7>::result;
    using _t9 = AssertEq<Dec_v<bu9>, bu8>::result;
    using _t10 = AssertEq<Dec_v<bu10>, bu9>::result;
    using _t11 = AssertEq<Dec_v<bu11>, bu10>::result;
    using _t12 = AssertEq<Dec_v<bu12>, bu11>::result;
    using _t13 = AssertEq<Dec_v<bu13>, bu12>::result;
    using _t14 = AssertEq<Dec_v<bu14>, bu13>::result;
    using _t15 = AssertEq<Dec_v<bu15>, bu14>::result;
    using _t16 = AssertEq<Dec_v<bu16>, bu15>::result;

    using _t17 = AssertEq<Dec_v<bu32>, bu31>::result;
    using _t18 = AssertEq<Dec_v<bu64>, bu63>::result;
    using _t19 = AssertEq<Dec_v<bu128>, bu127>::result;

    using _t20 = AssertEq<Dec_v<bu100>, bu99>::result;
    using _t21 = AssertEq<Dec_v<bu255>, bu254>::result;
    using _t22 = AssertEq<Dec_v<bu42>, bu41>::result;

    using _t23 = AssertEq<Dec_v<Inc_v<bu0>>, bu0>::result;
    using _t24 = AssertEq<Dec_v<Inc_v<bu10>>, bu10>::result;
    using _t25 = AssertEq<Dec_v<Inc_v<bu31>>, bu31>::result;
    using _t26 = AssertEq<Dec_v<Inc_v<bu63>>, bu63>::result;
    using _t27 = AssertEq<Dec_v<Inc_v<bu127>>, bu127>::result;

    using _t28 = AssertEq<Inc_v<Dec_v<bu1>>, bu1>::result;
    using _t29 = AssertEq<Inc_v<Dec_v<bu10>>, bu10>::result;
    using _t30 = AssertEq<Inc_v<Dec_v<bu32>>, bu32>::result;
    using _t31 = AssertEq<Inc_v<Dec_v<bu64>>, bu64>::result;
    using _t32 = AssertEq<Inc_v<Dec_v<bu128>>, bu128>::result;
} // namespace bigunsigned_decrement_tests

