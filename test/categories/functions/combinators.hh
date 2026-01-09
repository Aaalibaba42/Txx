#pragma once

#include "functions/base/apply.hh"
#include "functions/base/const.hh"
#include "functions/base/curry.hh"
#include "functions/base/flip.hh"
#include "functions/base/id.hh"
#include "functions/base/prepend.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "meta/assert.hh"

namespace combinators_tests
{
    // Id tests
    using _t0 = AssertEq<Apply_v<IdFunc, bu1>, bu1>::result;
    using _t1 = AssertEq<Apply_v<IdFunc, bu42>, bu42>::result;
    using _t2 = AssertEq<Apply_v<IdFunc, True>, True>::result;
    using _t3 = AssertEq<Apply_v<IdFunc, False>, False>::result;

    // Const tests
    using Always42 = Const_v<bu42>;
    using _t4 = AssertEq<Apply_v<Always42, bu1>, bu42>::result;
    using _t5 = AssertEq<Apply_v<Always42, bu99>, bu42>::result;
    using _t6 = AssertEq<Apply_v<Always42, True>, bu42>::result;

    using AlwaysTrue = Const_v<True>;
    using _t7 = AssertEq<Apply_v<AlwaysTrue, bu1>, True>::result;
    using _t8 = AssertEq<Apply_v<AlwaysTrue, False>, True>::result;

    // Flip tests - flip argument order of Prepend
    using _t9 = AssertEq<Prepend_v<bu1, List<bu2>>, List<bu1, bu2>>::result;
    using _t10 = AssertEq<Apply_v<Flip_v<PrependFunc>, List<bu2>, bu1>,
                          List<bu1, bu2>>::result;
    using _t11 = AssertEq<Apply_v<Flip_v<PrependFunc>, List<bu2, bu3>, bu1>,
                          List<bu1, bu2, bu3>>::result;
} // namespace combinators_tests
