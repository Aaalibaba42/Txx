#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/sub.hh"

namespace unsigned8_sub_tests
{
    using S0_1 = Unsigned8Sub_v<u8_1, u8_1>;
    using S1 = Unsigned8Sub_v<u8_3, u8_2>;
    using S0 = Unsigned8Sub_v<u8_8, u8_8>;
    using S6 = Unsigned8Sub_v<u8_7, u8_1>;
    using S7 = Unsigned8Sub_v<u8_8, u8_1>;
    using S15 = Unsigned8Sub_v<u8_15, u8_0>;
    using S14 = Unsigned8Sub_v<u8_15, u8_1>;
    using S5 = Unsigned8Sub_v<u8_6, u8_1>;
    using S8 = Unsigned8Sub_v<u8_10, u8_2>;
    using S9 = Unsigned8Sub_v<u8_11, u8_2>;
    using S10 = Unsigned8Sub_v<u8_12, u8_2>;
    using S11 = Unsigned8Sub_v<u8_13, u8_2>;
    using S12 = Unsigned8Sub_v<u8_14, u8_2>;
    using S13 = Unsigned8Sub_v<u8_15, u8_2>;
    using S14_1 = Unsigned8Sub_v<u8_16, u8_2>;
    using S15_1 = Unsigned8Sub_v<u8_17, u8_2>;
    using S16 = Unsigned8Sub_v<u8_18, u8_2>;
    using S17 = Unsigned8Sub_v<u8_19, u8_2>;
    using S18 = Unsigned8Sub_v<u8_20, u8_2>;
    using S19 = Unsigned8Sub_v<u8_21, u8_2>;
    using S20 = Unsigned8Sub_v<u8_22, u8_2>;
    using S21 = Unsigned8Sub_v<u8_23, u8_2>;
    using S22 = Unsigned8Sub_v<u8_24, u8_2>;
    using S23 = Unsigned8Sub_v<u8_25, u8_2>;
    using S24 = Unsigned8Sub_v<u8_26, u8_2>;
    using S12 = Unsigned8Sub_v<u8_27, u8_15>;
    using S26 = Unsigned8Sub_v<u8_28, u8_2>;
    using S27 = Unsigned8Sub_v<u8_29, u8_2>;
    using S28 = Unsigned8Sub_v<u8_30, u8_2>;
    using S29 = Unsigned8Sub_v<u8_31, u8_2>;
    using S30 = Unsigned8Sub_v<u8_32, u8_2>;
    using S31 = Unsigned8Sub_v<u8_33, u8_2>;
    using S32 = Unsigned8Sub_v<u8_34, u8_2>;
    using S33 = Unsigned8Sub_v<u8_35, u8_2>;
    using S34 = Unsigned8Sub_v<u8_36, u8_2>;
    using S35 = Unsigned8Sub_v<u8_37, u8_2>;
    using S36 = Unsigned8Sub_v<u8_38, u8_2>;
    using S37 = Unsigned8Sub_v<u8_39, u8_2>;
    using S38 = Unsigned8Sub_v<u8_40, u8_2>;
    using S39 = Unsigned8Sub_v<u8_41, u8_2>;
    using S40 = Unsigned8Sub_v<u8_42, u8_2>;

    static_assert(is_same<S1, u8_1>);
    static_assert(is_same<S0, u8_0>);
    static_assert(is_same<S0_1, u8_0>);
    static_assert(is_same<S6, u8_6>);
    static_assert(is_same<S7, u8_7>);
    static_assert(is_same<S15, u8_15>);
    static_assert(is_same<S14, u8_14>);
    static_assert(is_same<S5, u8_5>);
    static_assert(is_same<S8, u8_8>);
    static_assert(is_same<S9, u8_9>);
    static_assert(is_same<S10, u8_10>);
    static_assert(is_same<S11, u8_11>);
    static_assert(is_same<S12, u8_12>);
    static_assert(is_same<S13, u8_13>);
    static_assert(is_same<S14_1, u8_14>);
    static_assert(is_same<S15_1, u8_15>);
    static_assert(is_same<S16, u8_16>);
    static_assert(is_same<S17, u8_17>);
    static_assert(is_same<S18, u8_18>);
    static_assert(is_same<S19, u8_19>);
    static_assert(is_same<S20, u8_20>);
    static_assert(is_same<S21, u8_21>);
    static_assert(is_same<S22, u8_22>);
    static_assert(is_same<S23, u8_23>);
    static_assert(is_same<S24, u8_24>);
    static_assert(is_same<S12, u8_12>);
    static_assert(is_same<S26, u8_26>);
    static_assert(is_same<S27, u8_27>);
    static_assert(is_same<S28, u8_28>);
    static_assert(is_same<S29, u8_29>);
    static_assert(is_same<S30, u8_30>);
    static_assert(is_same<S31, u8_31>);
    static_assert(is_same<S32, u8_32>);
    static_assert(is_same<S33, u8_33>);
    static_assert(is_same<S34, u8_34>);
    static_assert(is_same<S35, u8_35>);
    static_assert(is_same<S36, u8_36>);
    static_assert(is_same<S37, u8_37>);
    static_assert(is_same<S38, u8_38>);
    static_assert(is_same<S39, u8_39>);
    static_assert(is_same<S40, u8_40>);
} // namespace unsigned8_sub_tests
