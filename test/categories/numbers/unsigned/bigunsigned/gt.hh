#pragma once

#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/gt.hh"

namespace bigunsigned_gt_tests
{
    using _t0 = AssertEq<Gt_v<bu1, bu2>, False>::result;
    using _t1 = AssertEq<Gt_v<bu1, bu1>, False>::result;
    using _t2 = AssertEq<Gt_v<bu2, bu1>, True>::result;
    using _t3 = AssertEq<Gt_v<bu10, bu20>, False>::result;
    using _t4 = AssertEq<Gt_v<bu10, bu10>, False>::result;
    using _t5 = AssertEq<Gt_v<bu20, bu10>, True>::result;
    using _t6 = AssertEq<Gt_v<bu63, bu64>, False>::result;
    using _t7 = AssertEq<Gt_v<bu64, bu63>, True>::result;
    using _t8 = AssertEq<Gt_v<bu50, bu60>, False>::result;
    using _t9 = AssertEq<Gt_v<bu50, bu50>, False>::result;
    using _t10 = AssertEq<Gt_v<bu60, bu50>, True>::result;
    using _t11 = AssertEq<Gt_v<bu0, bu1>, False>::result;
    using _t12 = AssertEq<Gt_v<bu0, bu0>, False>::result;
    using _t13 = AssertEq<Gt_v<bu1, bu0>, True>::result;
    using _t14 = AssertEq<Gt_v<bu64, bu64>, False>::result;
    using _t15 = AssertEq<Gt_v<bu10, bu30>, False>::result;
    using _t16 = AssertEq<Gt_v<bu30, bu10>, True>::result;
    using _t17 = AssertEq<Gt_v<bu32, bu33>, False>::result;
    using _t18 = AssertEq<Gt_v<bu33, bu33>, False>::result;
    using _t19 = AssertEq<Gt_v<bu33, bu32>, True>::result;
} // namespace bigunsigned_gt_tests
