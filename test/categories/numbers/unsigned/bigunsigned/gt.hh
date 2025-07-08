#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/bigunsigned/ops/gt.hh"

namespace bigunsigned_gt_tests
{
    static_assert(is_same<BigUnsignedGT_v<bu1, bu2>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu1, bu1>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu2, bu1>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu10, bu20>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu10, bu10>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu20, bu10>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu63, bu64>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu64, bu63>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu50, bu60>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu50, bu50>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu60, bu50>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu0, bu1>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu0, bu0>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu1, bu0>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu64, bu64>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu10, bu30>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu30, bu10>, True>);
    static_assert(is_same<BigUnsignedGT_v<bu32, bu33>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu33, bu33>, False>);
    static_assert(is_same<BigUnsignedGT_v<bu33, bu32>, True>);
} // namespace bigunsigned_gt_tests
