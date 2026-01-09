#pragma once

#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/ge.hh"

namespace bigunsigned_ge_tests
{
    using _t0 = AssertEq<Ge_v<bu1, bu2>, False>::result;
    using _t1 = AssertEq<Ge_v<bu1, bu1>, True>::result;
    using _t2 = AssertEq<Ge_v<bu2, bu1>, True>::result;
    using _t3 = AssertEq<Ge_v<bu10, bu20>, False>::result;
    using _t4 = AssertEq<Ge_v<bu10, bu10>, True>::result;
    using _t5 = AssertEq<Ge_v<bu20, bu10>, True>::result;
    using _t6 = AssertEq<Ge_v<bu63, bu64>, False>::result;
    using _t7 = AssertEq<Ge_v<bu64, bu63>, True>::result;
    using _t8 = AssertEq<Ge_v<bu50, bu60>, False>::result;
    using _t9 = AssertEq<Ge_v<bu50, bu50>, True>::result;
    using _t10 = AssertEq<Ge_v<bu60, bu50>, True>::result;
    using _t11 = AssertEq<Ge_v<bu0, bu1>, False>::result;
    using _t12 = AssertEq<Ge_v<bu0, bu0>, True>::result;
    using _t13 = AssertEq<Ge_v<bu1, bu0>, True>::result;
    using _t14 = AssertEq<Ge_v<bu64, bu64>, True>::result;
    using _t15 = AssertEq<Ge_v<bu10, bu30>, False>::result;
    using _t16 = AssertEq<Ge_v<bu30, bu10>, True>::result;
    using _t17 = AssertEq<Ge_v<bu32, bu33>, False>::result;
    using _t18 = AssertEq<Ge_v<bu33, bu33>, True>::result;
    using _t19 = AssertEq<Ge_v<bu33, bu32>, True>::result;
} // namespace bigunsigned_ge_tests
