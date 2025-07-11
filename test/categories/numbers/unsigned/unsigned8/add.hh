#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/add.hh"

namespace unsigned8_add_tests
{
    using A5 = Unsigned8Add_v<u8_3, u8_2>;
    using A16 = Unsigned8Add_v<u8_8, u8_8>;
    using A8 = Unsigned8Add_v<u8_7, u8_1>;
    using A1 = Unsigned8Add_v<u8_0, u8_1>;
    using A0 = Unsigned8Add_v<u8_0, u8_0>;
    using A15_1 = Unsigned8Add_v<u8_15, u8_0>;
    using A15_2 = Unsigned8Add_v<u8_0, u8_15>;
    using A16_1 = Unsigned8Add_v<u8_15, u8_1>;
    using A16_2 = Unsigned8Add_v<u8_1, u8_15>;
    using A6 = Unsigned8Add_v<u8_2, u8_4>;
    using A9 = Unsigned8Add_v<u8_5, u8_4>;
    using A11 = Unsigned8Add_v<u8_3, u8_8>;
    using A14 = Unsigned8Add_v<u8_6, u8_8>;
    using A15 = Unsigned8Add_v<u8_7, u8_8>;
    using A10 = Unsigned8Add_v<u8_4, u8_6>;
    using A13 = Unsigned8Add_v<u8_5, u8_8>;
    using A17 = Unsigned8Add_v<u8_9, u8_8>;
    using A19 = Unsigned8Add_v<u8_11, u8_8>;
    using A22 = Unsigned8Add_v<u8_14, u8_8>;
    using A25 = Unsigned8Add_v<u8_16, u8_9>;
    using A28 = Unsigned8Add_v<u8_19, u8_9>;
    using A30 = Unsigned8Add_v<u8_20, u8_10>;
    using A33 = Unsigned8Add_v<u8_22, u8_11>;
    using A35 = Unsigned8Add_v<u8_24, u8_11>;
    using A38 = Unsigned8Add_v<u8_27, u8_11>;
    using A40 = Unsigned8Add_v<u8_30, u8_10>;
    using A42 = Unsigned8Add_v<u8_33, u8_9>;
    using A45 = Unsigned8Add_v<u8_36, u8_9>;
    using A48 = Unsigned8Add_v<u8_39, u8_9>;
    using A50 = Unsigned8Add_v<u8_41, u8_9>;

    static_assert(is_same<A6, u8_6>);
    static_assert(is_same<A9, u8_9>);
    static_assert(is_same<A11, u8_11>);
    static_assert(is_same<A14, u8_14>);
    static_assert(is_same<A15, u8_15>);
    static_assert(is_same<A10, u8_10>);
    static_assert(is_same<A13, u8_13>);
    static_assert(is_same<A17, u8_17>);
    static_assert(is_same<A19, u8_19>);
    static_assert(is_same<A22, u8_22>);
    static_assert(is_same<A25, u8_25>);
    static_assert(is_same<A28, u8_28>);
    static_assert(is_same<A30, u8_30>);
    static_assert(is_same<A33, u8_33>);
    static_assert(is_same<A35, u8_35>);
    static_assert(is_same<A38, u8_38>);
    static_assert(is_same<A40, u8_40>);
    static_assert(is_same<A42, u8_42>);
    static_assert(is_same<A45, u8_45>);
    static_assert(is_same<A48, u8_48>);
    static_assert(is_same<A50, u8_50>);
    static_assert(is_same<A5, u8_5>);
    static_assert(is_same<A16, u8_16>);
    static_assert(is_same<A8, u8_8>);
    static_assert(is_same<A1, u8_1>);
    static_assert(is_same<A0, u8_0>);
    static_assert(is_same<A15_1, u8_15>);
    static_assert(is_same<A15_2, u8_15>);
    static_assert(is_same<A16_1, u8_16>);
    static_assert(is_same<A16_2, u8_16>);
} // namespace unsigned8_add_tests
