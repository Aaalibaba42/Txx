#pragma once

#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/mod.hh"

namespace bigunsigned_mod_tests
{
    // Fails (as expected)
    // using _err0 = AssertEq<Mod_v<bu10, bu0>, bu0>::result;
    // using _err1 = AssertEq<Mod_v<bu0, bu0>, bu0>::result;

    using _t0 = AssertEq<Mod_v<bu1, bu2>, bu1>::result;
    using _t1 = AssertEq<Mod_v<bu5, bu5>, bu0>::result;
    using _t2 = AssertEq<Mod_v<bu10, bu2>, bu0>::result;
    using _t3 = AssertEq<Mod_v<bu10, bu1>, bu0>::result;
    using _t4 = AssertEq<Mod_v<bu0, bu5>, bu0>::result;
    using _t5 = AssertEq<Mod_v<bu20, bu4>, bu0>::result;
    using _t6 = AssertEq<Mod_v<bu50, bu10>, bu0>::result;
    using _t7 = AssertEq<Mod_v<bu64, bu2>, bu0>::result;
    using _t8 = AssertEq<Mod_v<bu25, bu3>, bu1>::result;
    using _t9 = AssertEq<Mod_v<bu64, bu1>, bu0>::result;
    using _t10 = AssertEq<Mod_v<bu50, bu25>, bu0>::result;
    using _t11 = AssertEq<Mod_v<bu64, bu63>, bu1>::result;
    using _t12 = AssertEq<Mod_v<bu64, bu16>, bu0>::result;
    using _t13 = AssertEq<Mod_v<bu15, bu16>, bu15>::result;
    using _t14 = AssertEq<Mod_v<bu10, bu3>, bu1>::result;
    using _t15 = AssertEq<Mod_v<bu64, bu64>, bu0>::result;
    using _t16 = AssertEq<Mod_v<bu30, bu7>, bu2>::result;
    using _t17 = AssertEq<Mod_v<bu17, bu5>, bu2>::result;
    using _t18 = AssertEq<Mod_v<bu50, bu26>, bu24>::result;
    using _t19 = AssertEq<Mod_v<bu50, bu24>, bu2>::result;
    using _t20 = AssertEq<Mod_v<bu1, bu64>, bu1>::result;
    using _t21 = AssertEq<Mod_v<bu33, bu32>, bu1>::result;
    using _t22 = AssertEq<Mod_v<bu10, bu9>, bu1>::result;
    using _t23 = AssertEq<Mod_v<bu64, bu1>, bu0>::result;
} // namespace bigunsigned_mod_tests
