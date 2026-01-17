#pragma once

#include "literals/chars.hh"
#include "literals/ordering.hh"
#include "meta/assert.hh"
#include "strings/ops/compare.hh"
#include "strings/strings.hh"

namespace string_compare_tests
{
    // Empty strings
    using _t0 = AssertEq<Compare_v<String<>, String<>>, Equal>::result;

    // Empty vs non-empty
    using _t1 = AssertEq<Compare_v<String<>, String<c_a>>, Lower>::result;
    using _t2 = AssertEq<Compare_v<String<c_a>, String<>>, Greater>::result;

    // Single char comparisons
    using _t3 = AssertEq<Compare_v<String<c_a>, String<c_a>>, Equal>::result;
    using _t4 = AssertEq<Compare_v<String<c_a>, String<c_b>>, Lower>::result;
    using _t5 = AssertEq<Compare_v<String<c_b>, String<c_a>>, Greater>::result;

    // Multi-char same length
    using abc = String<c_a, c_b, c_c>;
    using abd = String<c_a, c_b, c_d>;
    using aac = String<c_a, c_a, c_c>;

    using _t6 = AssertEq<Compare_v<abc, abc>, Equal>::result;
    using _t7 = AssertEq<Compare_v<abc, abd>, Lower>::result;
    using _t8 = AssertEq<Compare_v<abd, abc>, Greater>::result;
    using _t9 = AssertEq<Compare_v<aac, abc>, Lower>::result;
    using _t10 = AssertEq<Compare_v<abc, aac>, Greater>::result;

    // Different lengths (prefix)
    using ab = String<c_a, c_b>;
    using _t11 = AssertEq<Compare_v<ab, abc>, Lower>::result;
    using _t12 = AssertEq<Compare_v<abc, ab>, Greater>::result;

    // Case sensitivity (uppercase < lowercase in ASCII)
    using upper_A = String<c_A>;
    using lower_a = String<c_a>;
    using _t13 = AssertEq<Compare_v<upper_A, lower_a>, Lower>::result;
    using _t14 = AssertEq<Compare_v<lower_a, upper_A>, Greater>::result;

    // Digits
    using zero = String<c_0>;
    using nine = String<c_9>;
    using _t15 = AssertEq<Compare_v<zero, nine>, Lower>::result;
    using _t16 = AssertEq<Compare_v<nine, zero>, Greater>::result;

    // "hello" vs "world"
    using hello = String<c_h, c_e, c_l, c_l, c_o>;
    using world = String<c_w, c_o, c_r, c_l, c_d>;
    using _t17 = AssertEq<Compare_v<hello, world>, Lower>::result;
    using _t18 = AssertEq<Compare_v<world, hello>, Greater>::result;
    using _t19 = AssertEq<Compare_v<hello, hello>, Equal>::result;

} // namespace string_compare_tests

