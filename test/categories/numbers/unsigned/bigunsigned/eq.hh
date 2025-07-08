#pragma once

#include "numbers/unsigned/bigunsigned/ops/eq.hh"

#include "../../../../utils/is_same.hh"
#include "literals.hh"

namespace bigunsigned_eq_tests
{
    static_assert(is_same<BigUnsignedEQ_v<bu1, bu1>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu1, bu2>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu5, bu5>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu5, bu6>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu10, bu10>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu10, bu11>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu0, bu0>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu1, bu0>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu64, bu64>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu64, bu63>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu32, bu32>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu32, bu33>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu1, bu1>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu1, bu2>, False>);
    static_assert(is_same<BigUnsignedEQ_v<bu10, bu10>, True>);
    static_assert(is_same<BigUnsignedEQ_v<bu10, bu20>, False>);
} // namespace bigunsigned_eq_tests
