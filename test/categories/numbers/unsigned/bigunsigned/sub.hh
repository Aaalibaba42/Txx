#pragma once

#include "numbers/unsigned/bigunsigned/ops/sub.hh"
#include "../../../../utils/is_same.hh"
#include "literals.hh"

namespace bigunsigned_sub_tests
{
    using S0_1 = BigUnsignedSub_v<bu1, bu1>;
    using S1 = BigUnsignedSub_v<bu3, bu2>;
    using S0 = BigUnsignedSub_v<bu8, bu8>;
    using S6 = BigUnsignedSub_v<bu7, bu1>;
    using S7 = BigUnsignedSub_v<bu8, bu1>;
    using S15 = BigUnsignedSub_v<bu15, bu0>;
    using S14 = BigUnsignedSub_v<bu15, bu1>;
    using S5 = BigUnsignedSub_v<bu6, bu1>;
    using S8 = BigUnsignedSub_v<bu10, bu2>;
    using S9 = BigUnsignedSub_v<bu11, bu2>;
    using S10 = BigUnsignedSub_v<bu12, bu2>;
    using S11 = BigUnsignedSub_v<bu13, bu2>;
    using S12 = BigUnsignedSub_v<bu14, bu2>;
    using S13 = BigUnsignedSub_v<bu15, bu2>;
    using S14_1 = BigUnsignedSub_v<bu16, bu2>;
    using S15_1 = BigUnsignedSub_v<bu17, bu2>;
    using S16 = BigUnsignedSub_v<bu18, bu2>;
    using S17 = BigUnsignedSub_v<bu19, bu2>;
    using S18 = BigUnsignedSub_v<bu20, bu2>;
    using S19 = BigUnsignedSub_v<bu21, bu2>;
    using S20 = BigUnsignedSub_v<bu22, bu2>;
    using S21 = BigUnsignedSub_v<bu23, bu2>;
    using S22 = BigUnsignedSub_v<bu24, bu2>;
    using S23 = BigUnsignedSub_v<bu25, bu2>;
    using S24 = BigUnsignedSub_v<bu26, bu2>;
    using S12 = BigUnsignedSub_v<bu27, bu15>;
    using S26 = BigUnsignedSub_v<bu28, bu2>;
    using S27 = BigUnsignedSub_v<bu29, bu2>;
    using S28 = BigUnsignedSub_v<bu30, bu2>;
    using S29 = BigUnsignedSub_v<bu31, bu2>;
    using S30 = BigUnsignedSub_v<bu32, bu2>;
    using S31 = BigUnsignedSub_v<bu33, bu2>;
    using S32 = BigUnsignedSub_v<bu34, bu2>;
    using S33 = BigUnsignedSub_v<bu35, bu2>;
    using S34 = BigUnsignedSub_v<bu36, bu2>;
    using S35 = BigUnsignedSub_v<bu37, bu2>;
    using S36 = BigUnsignedSub_v<bu38, bu2>;
    using S37 = BigUnsignedSub_v<bu39, bu2>;
    using S38 = BigUnsignedSub_v<bu40, bu2>;
    using S39 = BigUnsignedSub_v<bu41, bu2>;
    using S40 = BigUnsignedSub_v<bu42, bu2>;

    static_assert(is_same<S1, bu1>);
    static_assert(is_same<S0, bu0>);
    static_assert(is_same<S0_1, bu0>);
    static_assert(is_same<S6, bu6>);
    static_assert(is_same<S7, bu7>);
    static_assert(is_same<S15, bu15>);
    static_assert(is_same<S14, bu14>);
    static_assert(is_same<S5, bu5>);
    static_assert(is_same<S8, bu8>);
    static_assert(is_same<S9, bu9>);
    static_assert(is_same<S10, bu10>);
    static_assert(is_same<S11, bu11>);
    static_assert(is_same<S12, bu12>);
    static_assert(is_same<S13, bu13>);
    static_assert(is_same<S14_1, bu14>);
    static_assert(is_same<S15_1, bu15>);
    static_assert(is_same<S16, bu16>);
    static_assert(is_same<S17, bu17>);
    static_assert(is_same<S18, bu18>);
    static_assert(is_same<S19, bu19>);
    static_assert(is_same<S20, bu20>);
    static_assert(is_same<S21, bu21>);
    static_assert(is_same<S22, bu22>);
    static_assert(is_same<S23, bu23>);
    static_assert(is_same<S24, bu24>);
    static_assert(is_same<S12, bu12>);
    static_assert(is_same<S26, bu26>);
    static_assert(is_same<S27, bu27>);
    static_assert(is_same<S28, bu28>);
    static_assert(is_same<S29, bu29>);
    static_assert(is_same<S30, bu30>);
    static_assert(is_same<S31, bu31>);
    static_assert(is_same<S32, bu32>);
    static_assert(is_same<S33, bu33>);
    static_assert(is_same<S34, bu34>);
    static_assert(is_same<S35, bu35>);
    static_assert(is_same<S36, bu36>);
    static_assert(is_same<S37, bu37>);
    static_assert(is_same<S38, bu38>);
    static_assert(is_same<S39, bu39>);
    static_assert(is_same<S40, bu40>);
} // namespace bigunsigned_sub_tests
