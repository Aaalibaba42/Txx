#pragma once

#include "../../utils/is_same.hh"
#include "bools/ops/xor.hh"
#include "list/list.hh"
#include "list/ops/foldr.hh"
#include "literals/bigunsigned.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/mul.hh"

namespace list_foldr_tests
{
    // BigUnsignedAdd
    static_assert(
        is_same<ListFoldR_v<BigUnsignedAddFunc, List<bu1>, bu0>, bu1>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedAddFunc, List<bu1, bu2, bu3>, bu0>,
                bu6>);
    static_assert(is_same<ListFoldR_v<BigUnsignedAddFunc, List<>, bu0>, bu0>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedAddFunc, List<bu10, bu20, bu30>, bu0>,
                bu60>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedAddFunc, List<bu5, bu5, bu5>, bu0>,
                bu15>);

    // BigUnsignedMul
    static_assert(
        is_same<ListFoldR_v<BigUnsignedMulFunc, List<bu2>, bu1>, bu2>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedMulFunc, List<bu1, bu2, bu3>, bu1>,
                bu6>);
    static_assert(is_same<ListFoldR_v<BigUnsignedMulFunc, List<>, bu1>, bu1>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedMulFunc, List<bu2, bu3, bu4>, bu1>,
                bu24>);
    static_assert(
        is_same<ListFoldR_v<BigUnsignedMulFunc, List<bu2, bu2, bu2>, bu1>,
                bu8>);

    // BoolXorFunc
    static_assert(is_same<ListFoldR_v<BoolXorFunc, List<True>, False>, True>);
    static_assert(is_same<ListFoldR_v<BoolXorFunc, List<False>, False>, False>);
    static_assert(
        is_same<ListFoldR_v<BoolXorFunc, List<True, False>, False>, True>);
    static_assert(
        is_same<ListFoldR_v<BoolXorFunc, List<True, False, True, False>, False>,
                False>);
    static_assert(is_same<ListFoldR_v<BoolXorFunc, List<>, False>, False>);
    static_assert(
        is_same<ListFoldR_v<BoolXorFunc, List<True, True, True>, False>, True>);
    static_assert(
        is_same<ListFoldR_v<BoolXorFunc, List<False, False, False>, False>,
                False>);
    static_assert(
        is_same<ListFoldR_v<BoolXorFunc,
                            List<True, True, False, True, False, False>, False>,
                True>);
} // namespace list_foldr_tests
