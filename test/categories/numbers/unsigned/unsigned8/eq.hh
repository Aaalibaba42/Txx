#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bools.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/eq.hh"

namespace unsigned8_eq_tests
{
    static_assert(is_same<Eq_v<u8_1, u8_1>, True>);
    static_assert(is_same<Eq_v<u8_1, u8_2>, False>);
    static_assert(is_same<Eq_v<u8_5, u8_5>, True>);
    static_assert(is_same<Eq_v<u8_5, u8_6>, False>);
    static_assert(is_same<Eq_v<u8_10, u8_10>, True>);
    static_assert(is_same<Eq_v<u8_10, u8_11>, False>);
    static_assert(is_same<Eq_v<u8_0, u8_0>, True>);
    static_assert(is_same<Eq_v<u8_1, u8_0>, False>);
    static_assert(is_same<Eq_v<u8_64, u8_64>, True>);
    static_assert(is_same<Eq_v<u8_64, u8_63>, False>);
    static_assert(is_same<Eq_v<u8_32, u8_32>, True>);
    static_assert(is_same<Eq_v<u8_32, u8_33>, False>);
    static_assert(is_same<Eq_v<u8_1, u8_1>, True>);
    static_assert(is_same<Eq_v<u8_1, u8_2>, False>);
    static_assert(is_same<Eq_v<u8_10, u8_10>, True>);
    static_assert(is_same<Eq_v<u8_10, u8_20>, False>);
} // namespace unsigned8_eq_tests
