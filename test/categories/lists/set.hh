#pragma once

#include "types/list/ops/set.hh"
#include "types/list/list.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

namespace list_set_tests
{
    // Fails (as expected)
    // static_assert(is_same<Set_v<List<>, n1, n1>, List<>>);
    // static_assert(is_same<Set_v<List<>, n1, n0>, List<>>);
    // static_assert(is_same<Set_v<List<n1>, n2, n1>, List<>>);
    // static_assert(is_same<Set_v<List<n1, n2>, n3, n2>, List<>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n0>, List<n4, n2, n3>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n1>, List<n1, n4, n3>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n2>, List<n1, n2, n4>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n0>, List<n4, n3, n2>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n1>, List<n2, n4, n2>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n2>, List<n2, n3, n4>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n1>, List<n1, n4, n3>>);
    static_assert(is_same<List<n1, n2, n3>, List<n1, n2, n3>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n4, n5>, n6, n0>, List<n6, n3, n4, n5>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3, n4>, n5, n3>, List<n1, n2, n3, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
} // namespace list_set_tests
