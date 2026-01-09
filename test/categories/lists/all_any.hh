#pragma once

#include "list/list.hh"
#include "list/ops/all.hh"
#include "list/ops/any.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/lt.hh"

namespace list_all_any_tests
{
    struct IdentityPred
    {
        using is_function = IsFunction;
        template <Any_t X>
        struct apply
        {
            using result = X;
        };
    };

    struct LessThan5
    {
        using is_function = IsFunction;
        template <Any_t X>
        struct apply
        {
            using result = Lt_v<X, bu5>;
        };
    };

    // All tests
    using _t0 = AssertEq<All_v<IdentityPred, List<>>, True>::result;
    using _t1 = AssertEq<All_v<IdentityPred, List<True>>, True>::result;
    using _t2 = AssertEq<All_v<IdentityPred, List<False>>, False>::result;
    using _t3 = AssertEq<All_v<IdentityPred, List<True, True>>, True>::result;
    using _t4 = AssertEq<All_v<IdentityPred, List<True, False>>, False>::result;
    using _t5 = AssertEq<All_v<IdentityPred, List<False, True>>, False>::result;
    using _t6 =
        AssertEq<All_v<IdentityPred, List<True, True, True>>, True>::result;

    using _t7 = AssertEq<All_v<LessThan5, List<bu1, bu2, bu3>>, True>::result;
    using _t8 = AssertEq<All_v<LessThan5, List<bu1, bu5, bu3>>, False>::result;
    using _t9 = AssertEq<All_v<LessThan5, List<bu6, bu7, bu8>>, False>::result;

    // Any tests
    using _t10 = AssertEq<Any_v<IdentityPred, List<>>, False>::result;
    using _t11 = AssertEq<Any_v<IdentityPred, List<True>>, True>::result;
    using _t12 = AssertEq<Any_v<IdentityPred, List<False>>, False>::result;
    using _t13 = AssertEq<Any_v<IdentityPred, List<True, False>>, True>::result;
    using _t14 = AssertEq<Any_v<IdentityPred, List<False, True>>, True>::result;
    using _t15 =
        AssertEq<Any_v<IdentityPred, List<False, False>>, False>::result;
    using _t16 =
        AssertEq<Any_v<IdentityPred, List<False, False, True>>, True>::result;

    using _t17 = AssertEq<Any_v<LessThan5, List<bu1, bu2, bu3>>, True>::result;
    using _t18 = AssertEq<Any_v<LessThan5, List<bu6, bu2, bu8>>, True>::result;
    using _t19 = AssertEq<Any_v<LessThan5, List<bu6, bu7, bu8>>, False>::result;
} // namespace list_all_any_tests
