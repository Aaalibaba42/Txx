#pragma once

#include "types/numbers/unsigned/bigunsigned/ops/mod.hh"

#include "../../../../utils/is_same.hh"
#include "../../../../utils/numbers.hh"

namespace bigunsigned_mod_tests
{
    // Fails (as expected)
    // static_assert(is_same<UnsignedMod_v<n10, n0>, n0>);
    // static_assert(is_same<UnsignedMod_v<n0, n0>, n0>);

    static_assert(is_same<BigUnsignedMod_v<n1, n2>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n5, n5>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n10, n2>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n10, n1>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n0, n5>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n20, n4>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n50, n10>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n64, n2>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n25, n3>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n1>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n50, n25>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n64, n63>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n16>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n15, n16>, n15>);
    static_assert(is_same<BigUnsignedMod_v<n10, n3>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n64>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n30, n7>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n17, n5>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n50, n26>, n24>);
    static_assert(is_same<BigUnsignedMod_v<n50, n24>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n1, n64>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n33, n32>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n10, n9>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n1>, n0>);
} // namespace bigunsigned_mod_tests
