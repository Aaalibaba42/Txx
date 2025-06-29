#pragma once

#include "types/list/ops/set.hh"
#include "types/list/list.hh"

#include "../../utils/is_same.hh"
#include "../numbers/unsigned/bigunsigned/literals.hh"

namespace list_set_tests
{
    // Fails (as expected)
    // static_assert(is_same<Set_v<List<>, bu1, bu1>, List<>>);
    // static_assert(is_same<Set_v<List<>, bu1, bu0>, List<>>);
    // static_assert(is_same<Set_v<List<bu1>, bu2, bu1>, List<>>);
    // static_assert(is_same<Set_v<List<bu1, bu2>, bu3, bu2>, List<>>);
    static_assert(
        is_same<ListSet_v<List<bu1, bu2, bu3>, bu4, bu0>, List<bu4, bu2, bu3>>);
    static_assert(
        is_same<ListSet_v<List<bu1, bu2, bu3>, bu4, bu1>, List<bu1, bu4, bu3>>);
    static_assert(
        is_same<ListSet_v<List<bu1, bu2, bu3>, bu4, bu2>, List<bu1, bu2, bu4>>);
    static_assert(is_same<ListSet_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                          List<bu1, bu2, bu6, bu4, bu5>>);
    static_assert(
        is_same<ListSet_v<List<bu2, bu3, bu2>, bu4, bu0>, List<bu4, bu3, bu2>>);
    static_assert(
        is_same<ListSet_v<List<bu2, bu3, bu2>, bu4, bu1>, List<bu2, bu4, bu2>>);
    static_assert(
        is_same<ListSet_v<List<bu2, bu3, bu2>, bu4, bu2>, List<bu2, bu3, bu4>>);
    static_assert(
        is_same<ListSet_v<List<bu1, bu2, bu3>, bu4, bu1>, List<bu1, bu4, bu3>>);
    static_assert(is_same<List<bu1, bu2, bu3>, List<bu1, bu2, bu3>>);
    static_assert(is_same<ListSet_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                          List<bu1, bu2, bu6, bu4, bu5>>);
    static_assert(
        is_same<List<bu1, bu2, bu3, bu4, bu5>, List<bu1, bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListSet_v<List<bu2, bu3, bu4, bu5>, bu6, bu0>,
                          List<bu6, bu3, bu4, bu5>>);
    static_assert(is_same<List<bu2, bu3, bu4, bu5>, List<bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListSet_v<List<bu1, bu2, bu3, bu4>, bu5, bu3>,
                          List<bu1, bu2, bu3, bu5>>);
    static_assert(is_same<List<bu1, bu2, bu3, bu4>, List<bu1, bu2, bu3, bu4>>);
    static_assert(is_same<ListSet_v<List<bu1, bu2, bu3, bu4, bu5>, bu6, bu2>,
                          List<bu1, bu2, bu6, bu4, bu5>>);
    static_assert(
        is_same<List<bu1, bu2, bu3, bu4, bu5>, List<bu1, bu2, bu3, bu4, bu5>>);
} // namespace list_set_tests
