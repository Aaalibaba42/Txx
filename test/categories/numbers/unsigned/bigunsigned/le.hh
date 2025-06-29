#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/le.hh"

#include "../../../../utils/is_same.hh"
#include "literals.hh"

namespace bigunsigned_le_tests
{
    static_assert(is_same<BigUnsignedLE_v<bu1, bu2>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu1, bu1>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu2, bu1>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu10, bu20>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu10, bu10>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu20, bu10>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu63, bu64>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu64, bu63>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu50, bu60>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu50, bu50>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu60, bu50>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu0, bu1>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu0, bu0>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu1, bu0>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu64, bu64>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu10, bu30>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu30, bu10>, False>);
    static_assert(is_same<BigUnsignedLE_v<bu32, bu33>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu33, bu33>, True>);
    static_assert(is_same<BigUnsignedLE_v<bu33, bu32>, False>);
} // namespace bigunsigned_le_tests
