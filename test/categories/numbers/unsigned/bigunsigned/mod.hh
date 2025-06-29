#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/mod.hh"

#include "../../../../utils/is_same.hh"
#include "literals.hh"

namespace bigunsigned_mod_tests
{
    // Fails (as expected)
    // static_assert(is_same<UnsignedMod_v<bu10, bu0>, bu0>);
    // static_assert(is_same<UnsignedMod_v<bu0, bu0>, bu0>);

    static_assert(is_same<BigUnsignedMod_v<bu1, bu2>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu5, bu5>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu10, bu2>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu10, bu1>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu0, bu5>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu20, bu4>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu50, bu10>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu2>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu25, bu3>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu1>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu50, bu25>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu63>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu16>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu15, bu16>, bu15>);
    static_assert(is_same<BigUnsignedMod_v<bu10, bu3>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu64>, bu0>);
    static_assert(is_same<BigUnsignedMod_v<bu30, bu7>, bu2>);
    static_assert(is_same<BigUnsignedMod_v<bu17, bu5>, bu2>);
    static_assert(is_same<BigUnsignedMod_v<bu50, bu26>, bu24>);
    static_assert(is_same<BigUnsignedMod_v<bu50, bu24>, bu2>);
    static_assert(is_same<BigUnsignedMod_v<bu1, bu64>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu33, bu32>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu10, bu9>, bu1>);
    static_assert(is_same<BigUnsignedMod_v<bu64, bu1>, bu0>);
} // namespace bigunsigned_mod_tests
