#pragma once

#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/le.hh"

namespace bigunsigned_le_tests
{
    using _t0 = AssertEq<Le_v<bu1, bu2>, True>::result;
    using _t1 = AssertEq<Le_v<bu1, bu1>, True>::result;
    using _t2 = AssertEq<Le_v<bu2, bu1>, False>::result;
    using _t3 = AssertEq<Le_v<bu10, bu20>, True>::result;
    using _t4 = AssertEq<Le_v<bu10, bu10>, True>::result;
    using _t5 = AssertEq<Le_v<bu20, bu10>, False>::result;
    using _t6 = AssertEq<Le_v<bu63, bu64>, True>::result;
    using _t7 = AssertEq<Le_v<bu64, bu63>, False>::result;
    using _t8 = AssertEq<Le_v<bu50, bu60>, True>::result;
    using _t9 = AssertEq<Le_v<bu50, bu50>, True>::result;
    using _t10 = AssertEq<Le_v<bu60, bu50>, False>::result;
    using _t11 = AssertEq<Le_v<bu0, bu1>, True>::result;
    using _t12 = AssertEq<Le_v<bu0, bu0>, True>::result;
    using _t13 = AssertEq<Le_v<bu1, bu0>, False>::result;
    using _t14 = AssertEq<Le_v<bu64, bu64>, True>::result;
    using _t15 = AssertEq<Le_v<bu10, bu30>, True>::result;
    using _t16 = AssertEq<Le_v<bu30, bu10>, False>::result;
    using _t17 = AssertEq<Le_v<bu32, bu33>, True>::result;
    using _t18 = AssertEq<Le_v<bu33, bu33>, True>::result;
    using _t19 = AssertEq<Le_v<bu33, bu32>, False>::result;
} // namespace bigunsigned_le_tests
