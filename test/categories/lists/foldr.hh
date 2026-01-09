#pragma once

#include "bools/ops/xor.hh"
#include "list/list.hh"
#include "list/ops/foldr.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace list_foldr_tests
{
    // Add
    using _t0 = AssertEq<FoldR_v<AddFunc, List<bu1>, bu0>, bu1>::result;
    using _t1 = AssertEq<FoldR_v<AddFunc, List<bu1, bu2, bu3>, bu0>, bu6>::result;
    using _t2 = AssertEq<FoldR_v<AddFunc, List<>, bu0>, bu0>::result;
    using _t3 = AssertEq<FoldR_v<AddFunc, List<bu10, bu20, bu30>, bu0>, bu60>::result;
    using _t4 = AssertEq<FoldR_v<AddFunc, List<bu5, bu5, bu5>, bu0>, bu15>::result;

    // Mul
    using _t5 = AssertEq<FoldR_v<MulFunc, List<bu2>, bu1>, bu2>::result;
    using _t6 = AssertEq<FoldR_v<MulFunc, List<bu1, bu2, bu3>, bu1>, bu6>::result;
    using _t7 = AssertEq<FoldR_v<MulFunc, List<>, bu1>, bu1>::result;
    using _t8 = AssertEq<FoldR_v<MulFunc, List<bu2, bu3, bu4>, bu1>, bu24>::result;
    using _t9 = AssertEq<FoldR_v<MulFunc, List<bu2, bu2, bu2>, bu1>, bu8>::result;

    // XorFunc
    using _t10 = AssertEq<FoldR_v<XorFunc, List<True>, False>, True>::result;
    using _t11 = AssertEq<FoldR_v<XorFunc, List<False>, False>, False>::result;
    using _t12 = AssertEq<FoldR_v<XorFunc, List<True, False>, False>, True>::result;
    using _t13 = AssertEq<FoldR_v<XorFunc, List<True, False, True, False>, False>,
                          False>::result;
    using _t14 = AssertEq<FoldR_v<XorFunc, List<>, False>, False>::result;
    using _t15 = AssertEq<FoldR_v<XorFunc, List<True, True, True>, False>, True>::result;
    using _t16 = AssertEq<FoldR_v<XorFunc, List<False, False, False>, False>, False>::result;
    using _t17 = AssertEq<FoldR_v<XorFunc, List<True, True, False, True, False, False>,
                                  False>,
                          True>::result;
} // namespace list_foldr_tests
