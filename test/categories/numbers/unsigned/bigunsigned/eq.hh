#pragma once

#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/eq.hh"

namespace bigunsigned_eq_tests
{
    using _t0 = AssertEq<Eq_v<bu1, bu1>, True>::result;
    using _t1 = AssertEq<Eq_v<bu1, bu2>, False>::result;
    using _t2 = AssertEq<Eq_v<bu5, bu5>, True>::result;
    using _t3 = AssertEq<Eq_v<bu5, bu6>, False>::result;
    using _t4 = AssertEq<Eq_v<bu10, bu10>, True>::result;
    using _t5 = AssertEq<Eq_v<bu10, bu11>, False>::result;
    using _t6 = AssertEq<Eq_v<bu0, bu0>, True>::result;
    using _t7 = AssertEq<Eq_v<bu1, bu0>, False>::result;
    using _t8 = AssertEq<Eq_v<bu64, bu64>, True>::result;
    using _t9 = AssertEq<Eq_v<bu64, bu63>, False>::result;
    using _t10 = AssertEq<Eq_v<bu32, bu32>, True>::result;
    using _t11 = AssertEq<Eq_v<bu32, bu33>, False>::result;
    using _t12 = AssertEq<Eq_v<bu1, bu1>, True>::result;
    using _t13 = AssertEq<Eq_v<bu1, bu2>, False>::result;
    using _t14 = AssertEq<Eq_v<bu10, bu10>, True>::result;
    using _t15 = AssertEq<Eq_v<bu10, bu20>, False>::result;
} // namespace bigunsigned_eq_tests
