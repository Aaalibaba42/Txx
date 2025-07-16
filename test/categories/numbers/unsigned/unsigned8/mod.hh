#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/mod.hh"

namespace unsigned8_mod_tests
{
    // Fails (as expected)
    // static_assert(is_same<Unsigned8Mod_v<u8_10, u8_0>, u8_0>);
    // static_assert(is_same<Unsigned8Mod_v<u8_0, u8_0>, u8_0>);

    static_assert(is_same<Unsigned8Mod_v<u8_1, u8_2>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_5, u8_5>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_10, u8_2>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_10, u8_1>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_0, u8_5>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_20, u8_4>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_50, u8_10>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_2>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_25, u8_3>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_1>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_50, u8_25>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_63>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_16>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_15, u8_16>, u8_15>);
    static_assert(is_same<Unsigned8Mod_v<u8_10, u8_3>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_64>, u8_0>);
    static_assert(is_same<Unsigned8Mod_v<u8_30, u8_7>, u8_2>);
    static_assert(is_same<Unsigned8Mod_v<u8_17, u8_5>, u8_2>);
    static_assert(is_same<Unsigned8Mod_v<u8_50, u8_26>, u8_24>);
    static_assert(is_same<Unsigned8Mod_v<u8_50, u8_24>, u8_2>);
    static_assert(is_same<Unsigned8Mod_v<u8_1, u8_64>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_33, u8_32>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_10, u8_9>, u8_1>);
    static_assert(is_same<Unsigned8Mod_v<u8_64, u8_1>, u8_0>);
} // namespace unsigned8_mod_tests
