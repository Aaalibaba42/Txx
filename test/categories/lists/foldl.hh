#pragma once

#include "bools/ops/xor.hh"
#include "list/list.hh"
#include "list/ops/foldl.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace list_foldl_tests
{
    // Add
    using _t0 = AssertEq<FoldL_v<AddFunc, bu0, List<bu1>>, bu1>::result;
    using _t1 = AssertEq<FoldL_v<AddFunc, bu0, List<bu1, bu2, bu3>>, bu6>::result;
    using _t2 = AssertEq<FoldL_v<AddFunc, bu0, List<>>, bu0>::result;
    using _t3 = AssertEq<FoldL_v<AddFunc, bu0, List<bu10, bu20, bu30>>, bu60>::result;
    using _t4 = AssertEq<FoldL_v<AddFunc, bu0, List<bu5, bu5, bu5>>, bu15>::result;

    // Mul
    using _t5 = AssertEq<FoldL_v<MulFunc, bu1, List<bu2>>, bu2>::result;
    using _t6 = AssertEq<FoldL_v<MulFunc, bu1, List<bu1, bu2, bu3>>, bu6>::result;
    using _t7 = AssertEq<FoldL_v<MulFunc, bu1, List<>>, bu1>::result;
    using _t8 = AssertEq<FoldL_v<MulFunc, bu1, List<bu2, bu3, bu4>>, bu24>::result;
    using _t9 = AssertEq<FoldL_v<MulFunc, bu1, List<bu2, bu2, bu2>>, bu8>::result;

    // XorFunc
    using _t10 = AssertEq<FoldL_v<XorFunc, False, List<True>>, True>::result;
    using _t11 = AssertEq<FoldL_v<XorFunc, False, List<False>>, False>::result;
    using _t12 = AssertEq<FoldL_v<XorFunc, False, List<True, False>>, True>::result;
    using _t13 = AssertEq<FoldL_v<XorFunc, False, List<True, False, True, False>>,
                          False>::result;
    using _t14 = AssertEq<FoldL_v<XorFunc, False, List<>>, False>::result;
    using _t15 = AssertEq<FoldL_v<XorFunc, False, List<True, True, True>>, True>::result;
    using _t16 = AssertEq<FoldL_v<XorFunc, False, List<False, False, False>>, False>::result;
    using _t17 = AssertEq<FoldL_v<XorFunc, False,
                                  List<True, True, False, True, False, False>>,
                          True>::result;
} // namespace list_foldl_tests
