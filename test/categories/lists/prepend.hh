#pragma once

#include "types/list/ops/prepend.hh"
#include "types/list/list.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

namespace list_prepend_tests
{
    static_assert(is_same<Prepend_v<n1, List<>>, List<n1>>);
    static_assert(is_same<Prepend_v<n1, List<n2>>, List<n1, n2>>);
    static_assert(
        is_same<Prepend_v<n1, List<n2, n3, n4>>, List<n1, n2, n3, n4>>);
    static_assert(is_same<Prepend_v<n5, List<n2, n4>>, List<n5, n2, n4>>);
    static_assert(is_same<Prepend_v<n3, List<n1>>, List<n3, n1>>);
    static_assert(is_same<List<n1>, List<n1>>);
    using L6 = Prepend_v<n2, List<n3, n4>>;
    static_assert(is_same<L6, List<n2, n3, n4>>);
    static_assert(is_same<Prepend_v<n1, L6>, List<n1, n2, n3, n4>>);
    static_assert(is_same<Prepend_v<n1, List<n2, n3, n4, n5, n6>>,
                          List<n1, n2, n3, n4, n5, n6>>);
    static_assert(
        is_same<Prepend_v<n2, List<n2, n3, n2>>, List<n2, n2, n3, n2>>);
    static_assert(is_same<Prepend_v<n4, List<n5>>, List<n4, n5>>);
    static_assert(is_same<List<n5>, List<n5>>);
    static_assert(is_same<Prepend_v<n6, List<n1, n2>>, List<n6, n1, n2>>);
    static_assert(is_same<List<n1, n2>, List<n1, n2>>);
    static_assert(
        is_same<Prepend_v<n3, List<n4, n5, n6>>, List<n3, n4, n5, n6>>);
    static_assert(is_same<List<n4, n5, n6>, List<n4, n5, n6>>);
    static_assert(
        is_same<Prepend_v<n1, List<n2, n3, n4, n5>>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(is_same<Prepend_v<n6, List<n1, n2, n3, n4, n5>>,
                          List<n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<Prepend_v<n2, List<n3, n4, n5, n6, n1, n2>>,
                          List<n2, n3, n4, n5, n6, n1, n2>>);
    static_assert(
        is_same<List<n3, n4, n5, n6, n1, n2>, List<n3, n4, n5, n6, n1, n2>>);
    static_assert(is_same<Prepend_v<n4, List<n5, n6, n1, n2, n3, n4, n5>>,
                          List<n4, n5, n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n5, n6, n1, n2, n3, n4, n5>,
                          List<n5, n6, n1, n2, n3, n4, n5>>);
} // namespace list_prepend_tests
