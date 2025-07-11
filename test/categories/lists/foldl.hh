#pragma once

#include "../../utils/is_same.hh"
#include "bools/ops/xor.hh"
#include "list/list.hh"
#include "list/ops/foldl.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace list_foldl_tests
{
    // BigUnsignedAdd
    static_assert(
        is_same<ListFoldL_v<BigUnsignedAddFunc, bu0, List<bu1>>, bu1>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedAddFunc, bu0, List<bu1, bu2, bu3>>,
                bu6>);
    static_assert(is_same<ListFoldL_v<BigUnsignedAddFunc, bu0, List<>>, bu0>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedAddFunc, bu0, List<bu10, bu20, bu30>>,
                bu60>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedAddFunc, bu0, List<bu5, bu5, bu5>>,
                bu15>);

    // BigUnsignedMul
    static_assert(
        is_same<ListFoldL_v<BigUnsignedMulFunc, bu1, List<bu2>>, bu2>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedMulFunc, bu1, List<bu1, bu2, bu3>>,
                bu6>);
    static_assert(is_same<ListFoldL_v<BigUnsignedMulFunc, bu1, List<>>, bu1>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedMulFunc, bu1, List<bu2, bu3, bu4>>,
                bu24>);
    static_assert(
        is_same<ListFoldL_v<BigUnsignedMulFunc, bu1, List<bu2, bu2, bu2>>,
                bu8>);

    // BoolXor
    static_assert(is_same<ListFoldL_v<BoolXorFunc, False, List<True>>, True>);
    static_assert(is_same<ListFoldL_v<BoolXorFunc, False, List<False>>, False>);
    static_assert(
        is_same<ListFoldL_v<BoolXorFunc, False, List<True, False>>, True>);
    static_assert(
        is_same<ListFoldL_v<BoolXorFunc, False, List<True, False, True, False>>,
                False>);
    static_assert(is_same<ListFoldL_v<BoolXorFunc, False, List<>>, False>);
    static_assert(
        is_same<ListFoldL_v<BoolXorFunc, False, List<True, True, True>>, True>);
    static_assert(
        is_same<ListFoldL_v<BoolXorFunc, False, List<False, False, False>>,
                False>);
    static_assert(
        is_same<ListFoldL_v<BoolXorFunc, False,
                            List<True, True, False, True, False, False>>,
                True>);
} // namespace list_foldl_tests
