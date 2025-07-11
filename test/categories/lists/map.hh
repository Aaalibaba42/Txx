#pragma once

#include "../../utils/is_same.hh"
#include "bools/ops/not.hh"
#include "list/list.hh"
#include "list/ops/length.hh"
#include "list/ops/map.hh"
#include "list/ops/reverse.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

namespace list_map_tests
{

    // BigUnsigned Incrementation
    static_assert(
        is_same<ListMap_v<BigUnsignedIncFunc, List<bu1, bu2>>, List<bu2, bu3>>);

    // Boolean Not
    static_assert(is_same<ListMap_v<BoolNotFunc, List<True>>, List<False>>);
    static_assert(is_same<ListMap_v<BoolNotFunc, List<False>>, List<True>>);
    static_assert(is_same<ListMap_v<BoolNotFunc, List<True, False, True, True>>,
                          List<False, True, False, False>>);
    static_assert(is_same<ListMap_v<BoolNotFunc, List<>>, List<>>);
    static_assert(
        is_same<ListMap_v<BoolNotFunc, List<True, False, True, False>>,
                List<False, True, False, True>>);

    // List Length
    static_assert(is_same<ListMap_v<ListLengthFunc, List<List<>>>, List<bu0>>);
    static_assert(is_same<ListMap_v<ListLengthFunc, List<List<bu1>, List<bu2>>>,
                          List<bu1, bu1>>);
    static_assert(is_same<ListMap_v<ListLengthFunc,
                                    List<List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                          List<bu2, bu3>>);
    static_assert(
        is_same<ListMap_v<ListLengthFunc,
                          List<List<>, List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                List<bu0, bu2, bu3>>);
    static_assert(is_same<ListMap_v<ListLengthFunc,
                                    List<List<bu1>, List<bu2, bu3>,
                                         List<bu4, bu5, bu6, bu7>>>,
                          List<bu1, bu2, bu4>>);
    // List Reverse
    static_assert(
        is_same<ListMap_v<ListReverseFunc, List<List<>>>, List<List<>>>);

    static_assert(
        is_same<ListMap_v<ListReverseFunc, List<List<bu1>, List<bu2>>>,
                List<List<bu1>, List<bu2>>>);

    static_assert(is_same<ListMap_v<ListReverseFunc,
                                    List<List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                          List<List<bu2, bu1>, List<bu8, bu5, bu3>>>);

    static_assert(
        is_same<ListMap_v<ListReverseFunc,
                          List<List<>, List<bu1, bu2>, List<bu3, bu5, bu8>>>,
                List<List<>, List<bu2, bu1>, List<bu8, bu5, bu3>>>);

    static_assert(
        is_same<ListMap_v<
                    ListReverseFunc,
                    List<List<bu1>, List<bu2, bu3>, List<bu4, bu5, bu6, bu7>>>,
                List<List<bu1>, List<bu3, bu2>, List<bu7, bu6, bu5, bu4>>>);

} // namespace list_map_tests
