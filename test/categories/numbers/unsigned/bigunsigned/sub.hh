#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"

namespace bigunsigned_sub_tests
{
    using S0_1 = Sub_v<bu1, bu1>;
    using S1 = Sub_v<bu3, bu2>;
    using S0 = Sub_v<bu8, bu8>;
    using S6 = Sub_v<bu7, bu1>;
    using S7 = Sub_v<bu8, bu1>;
    using S15 = Sub_v<bu15, bu0>;
    using S14 = Sub_v<bu15, bu1>;
    using S5 = Sub_v<bu6, bu1>;
    using S8 = Sub_v<bu10, bu2>;
    using S9 = Sub_v<bu11, bu2>;
    using S10 = Sub_v<bu12, bu2>;
    using S11 = Sub_v<bu13, bu2>;
    using S12 = Sub_v<bu14, bu2>;
    using S13 = Sub_v<bu15, bu2>;
    using S14_1 = Sub_v<bu16, bu2>;
    using S15_1 = Sub_v<bu17, bu2>;
    using S16 = Sub_v<bu18, bu2>;
    using S17 = Sub_v<bu19, bu2>;
    using S18 = Sub_v<bu20, bu2>;
    using S19 = Sub_v<bu21, bu2>;
    using S20 = Sub_v<bu22, bu2>;
    using S21 = Sub_v<bu23, bu2>;
    using S22 = Sub_v<bu24, bu2>;
    using S23 = Sub_v<bu25, bu2>;
    using S24 = Sub_v<bu26, bu2>;
    using S12 = Sub_v<bu27, bu15>;
    using S26 = Sub_v<bu28, bu2>;
    using S27 = Sub_v<bu29, bu2>;
    using S28 = Sub_v<bu30, bu2>;
    using S29 = Sub_v<bu31, bu2>;
    using S30 = Sub_v<bu32, bu2>;
    using S31 = Sub_v<bu33, bu2>;
    using S32 = Sub_v<bu34, bu2>;
    using S33 = Sub_v<bu35, bu2>;
    using S34 = Sub_v<bu36, bu2>;
    using S35 = Sub_v<bu37, bu2>;
    using S36 = Sub_v<bu38, bu2>;
    using S37 = Sub_v<bu39, bu2>;
    using S38 = Sub_v<bu40, bu2>;
    using S39 = Sub_v<bu41, bu2>;
    using S40 = Sub_v<bu42, bu2>;

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
