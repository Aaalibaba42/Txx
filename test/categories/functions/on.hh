#pragma once

#include "functions/base/add.hh"
#include "functions/base/apply.hh"
#include "functions/base/length.hh"
#include "functions/base/on.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"

namespace on_combinator_tests
{
    // (Add `on` Length) takes two lists and adds their lengths
    using AddOnLength = On_v<AddFunc, LengthFunc>;

    using _t0 =
        AssertEq<Apply_v<AddOnLength, List<bu1, bu2, bu3>, List<bu4, bu5>>,
                 bu5>::result;
    using _t1 = AssertEq<Apply_v<AddOnLength, List<>, List<bu1>>, bu1>::result;
    using _t2 = AssertEq<Apply_v<AddOnLength, List<bu1, bu2>, List<bu3, bu4>>,
                         bu4>::result;

    // Can also use via OnCombinator for full currying
    using AddOnLength2 = Apply_v<OnCombinator, AddFunc, LengthFunc>;
    using _t3 =
        AssertEq<Apply_v<AddOnLength2, List<bu1>, List<bu2, bu3>>, bu3>::result;
} // namespace on_combinator_tests
