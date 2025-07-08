#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/div.hh"

namespace bigunsigned_div_tests
{
    // Fails (as expected)
    // static_assert(is_same<BigUnsignedDiv_v<bu10, bu0>, bu0>);
    // static_assert(is_same<BigUnsignedDiv_v<bu0, bu0>, bu0>);

    static_assert(is_same<BigUnsignedDiv_v<bu1, bu2>, bu0>);
    static_assert(is_same<BigUnsignedDiv_v<bu5, bu5>, bu1>);
    static_assert(is_same<BigUnsignedDiv_v<bu10, bu2>, bu5>);
    static_assert(is_same<BigUnsignedDiv_v<bu10, bu1>, bu10>);
    static_assert(is_same<BigUnsignedDiv_v<bu0, bu5>, bu0>);
    static_assert(is_same<BigUnsignedDiv_v<bu20, bu4>, bu5>);
    static_assert(is_same<BigUnsignedDiv_v<bu50, bu10>, bu5>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu2>, bu32>);
    static_assert(is_same<BigUnsignedDiv_v<bu25, bu3>, bu8>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu1>, bu64>);
    static_assert(is_same<BigUnsignedDiv_v<bu50, bu25>, bu2>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu63>, bu1>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu16>, bu4>);
    static_assert(is_same<BigUnsignedDiv_v<bu15, bu1>, bu15>);
    static_assert(is_same<BigUnsignedDiv_v<bu10, bu3>, bu3>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu64>, bu1>);
    static_assert(is_same<BigUnsignedDiv_v<bu30, bu7>, bu4>);
    static_assert(is_same<BigUnsignedDiv_v<bu17, bu5>, bu3>);
    static_assert(is_same<BigUnsignedDiv_v<bu50, bu26>, bu1>);
    static_assert(is_same<BigUnsignedDiv_v<bu50, bu24>, bu2>);
    static_assert(is_same<BigUnsignedDiv_v<bu1, bu64>, bu0>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu1>, bu64>);
    static_assert(is_same<BigUnsignedDiv_v<bu10, bu20>, bu0>);
    static_assert(is_same<BigUnsignedDiv_v<bu64, bu1>, bu64>);
} // namespace bigunsigned_div_tests
