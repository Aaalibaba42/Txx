#pragma once

#include "list/list.hh"
#include "list/ops/filter.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/lt.hh"

namespace list_filter_tests
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

    using _t0 = AssertEq<Filter_v<IdentityPred, List<>>, List<>>::result;
    using _t1 =
        AssertEq<Filter_v<IdentityPred, List<True>>, List<True>>::result;
    using _t2 = AssertEq<Filter_v<IdentityPred, List<False>>, List<>>::result;
    using _t3 = AssertEq<Filter_v<IdentityPred, List<True, False, True>>,
                         List<True, True>>::result;
    using _t4 =
        AssertEq<Filter_v<IdentityPred, List<False, False, True, False, True>>,
                 List<True, True>>::result;

    struct LessThan5
    {
        using is_function = IsFunction;
        template <Any_t X>
        struct apply
        {
            using result = Lt_v<X, bu5>;
        };
    };

    using _t5 = AssertEq<Filter_v<LessThan5, List<>>, List<>>::result;
    using _t6 = AssertEq<Filter_v<LessThan5, List<bu1, bu2, bu3>>,
                         List<bu1, bu2, bu3>>::result;
    using _t7 =
        AssertEq<Filter_v<LessThan5, List<bu5, bu6, bu7>>, List<>>::result;
    using _t8 = AssertEq<Filter_v<LessThan5, List<bu1, bu5, bu2, bu6, bu3>>,
                         List<bu1, bu2, bu3>>::result;
} // namespace list_filter_tests
