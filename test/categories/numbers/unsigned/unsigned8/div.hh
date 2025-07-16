#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/div.hh"

namespace unsigned8_div_tests
{
    // These don't fail!! division by 0 yields max u8
    // static_assert(is_same<Unsigned8Div_v<u8_10, u8_0>, u8_0>);
    // static_assert(is_same<Unsigned8Div_v<u8_0, u8_0>, u8_0>);

    static_assert(is_same<Unsigned8Div_v<u8_1, u8_2>, u8_0>);
    static_assert(is_same<Unsigned8Div_v<u8_5, u8_5>, u8_1>);
    static_assert(is_same<Unsigned8Div_v<u8_10, u8_2>, u8_5>);
    static_assert(is_same<Unsigned8Div_v<u8_10, u8_1>, u8_10>);
    static_assert(is_same<Unsigned8Div_v<u8_0, u8_5>, u8_0>);
    static_assert(is_same<Unsigned8Div_v<u8_20, u8_4>, u8_5>);
    static_assert(is_same<Unsigned8Div_v<u8_50, u8_10>, u8_5>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_2>, u8_32>);
    static_assert(is_same<Unsigned8Div_v<u8_25, u8_3>, u8_8>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_1>, u8_64>);
    static_assert(is_same<Unsigned8Div_v<u8_50, u8_25>, u8_2>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_63>, u8_1>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_16>, u8_4>);
    static_assert(is_same<Unsigned8Div_v<u8_15, u8_1>, u8_15>);
    static_assert(is_same<Unsigned8Div_v<u8_10, u8_3>, u8_3>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_64>, u8_1>);
    static_assert(is_same<Unsigned8Div_v<u8_30, u8_7>, u8_4>);
    static_assert(is_same<Unsigned8Div_v<u8_17, u8_5>, u8_3>);
    static_assert(is_same<Unsigned8Div_v<u8_50, u8_26>, u8_1>);
    static_assert(is_same<Unsigned8Div_v<u8_50, u8_24>, u8_2>);
    static_assert(is_same<Unsigned8Div_v<u8_1, u8_64>, u8_0>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_1>, u8_64>);
    static_assert(is_same<Unsigned8Div_v<u8_10, u8_20>, u8_0>);
    static_assert(is_same<Unsigned8Div_v<u8_64, u8_1>, u8_64>);
} // namespace unsigned8_div_tests
