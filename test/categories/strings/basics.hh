#pragma once

#include "casts/string.hh"
#include "functions/base/eq.hh"
#include "list/list.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "literals/chars.hh"
#include "meta/assert.hh"
#include "strings/concept.hh"
#include "strings/ops/concat.hh"
#include "strings/ops/head.hh"
#include "strings/ops/is_empty.hh"
#include "strings/ops/length.hh"
#include "strings/ops/reverse.hh"
#include "strings/ops/tail.hh"
#include "strings/strings.hh"

namespace string_basics_tests
{
    using empty = String<>;
    using a = String<c_a>;
    using ab = String<c_a, c_b>;
    using abc = String<c_a, c_b, c_c>;
    using hello = String<c_H, c_e, c_l, c_l, c_o>;

    // ToList / ToString roundtrip
    using _t0 = AssertEq<ToString_v<ToList_v<abc>>, abc>::result;
    using _t1 = AssertEq<ToList_v<abc>, List<c_a, c_b, c_c>>::result;

    // IsEmpty
    using _t2 = AssertEq<IsEmpty_v<empty>, True>::result;
    using _t3 = AssertEq<IsEmpty_v<a>, False>::result;
    using _t4 = AssertEq<IsEmpty_v<hello>, False>::result;

    // Length
    using _t5 = AssertEq<Length_v<empty>, bu0>::result;
    using _t6 = AssertEq<Length_v<a>, bu1>::result;
    using _t7 = AssertEq<Length_v<abc>, bu3>::result;
    using _t8 = AssertEq<Length_v<hello>, bu5>::result;

    // Head
    using _t9 = AssertEq<Head_v<a>, c_a>::result;
    using _t10 = AssertEq<Head_v<abc>, c_a>::result;
    using _t11 = AssertEq<Head_v<hello>, c_H>::result;

    // Tail
    using _t12 = AssertEq<Tail_v<a>, empty>::result;
    using _t13 = AssertEq<Tail_v<abc>, String<c_b, c_c>>::result;
    using _t14 = AssertEq<Tail_v<hello>, String<c_e, c_l, c_l, c_o>>::result;

    // Reverse
    using _t15 = AssertEq<Reverse_v<empty>, empty>::result;
    using _t16 = AssertEq<Reverse_v<a>, a>::result;
    using _t17 = AssertEq<Reverse_v<abc>, String<c_c, c_b, c_a>>::result;

    // Concat
    using _t18 = AssertEq<Concat_v<empty, empty>, empty>::result;
    using _t19 = AssertEq<Concat_v<a, empty>, a>::result;
    using _t20 = AssertEq<Concat_v<empty, a>, a>::result;
    using _t21 = AssertEq<Concat_v<ab, abc>, String<c_a, c_b, c_a, c_b, c_c>>::result;

    // Eq (deep equality via IsSame)
    using _t22 = AssertEq<Eq_v<abc, abc>, True>::result;
    using _t23 = AssertEq<Eq_v<abc, ab>, False>::result;
    using _t24 = AssertEq<Eq_v<empty, empty>, True>::result;

} // namespace string_basics_tests

