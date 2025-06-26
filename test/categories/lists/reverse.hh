#pragma once

#include "types/list/ops/reverse.hh"
#include "types/list/list.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

namespace list_reverse_tests
{
    static_assert(is_same<Reverse_v<List<>>, List<>>);
    static_assert(is_same<Reverse_v<List<n1>>, List<n1>>);
    static_assert(is_same<Reverse_v<List<n1, n2>>, List<n2, n1>>);
    static_assert(
        is_same<Reverse_v<List<n1, n2, n3, n4>>, List<n4, n3, n2, n1>>);
    static_assert(is_same<Reverse_v<List<n2, n3, n2>>, List<n2, n3, n2>>);
    static_assert(is_same<Reverse_v<List<n1, n2, n3, n4, n5, n6>>,
                          List<n6, n5, n4, n3, n2, n1>>);
    static_assert(is_same<Reverse_v<List<n5>>, List<n5>>);
    static_assert(is_same<List<n5>, List<n5>>);
    static_assert(is_same<Reverse_v<List<n1, n2>>, List<n2, n1>>);
    static_assert(is_same<List<n1, n2>, List<n1, n2>>);
    static_assert(is_same<Reverse_v<List<n3, n4, n5>>, List<n5, n4, n3>>);
    static_assert(is_same<List<n3, n4, n5>, List<n3, n4, n5>>);
    static_assert(
        is_same<Reverse_v<List<n2, n3, n4, n5>>, List<n5, n4, n3, n2>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(
        is_same<Reverse_v<List<n1, n2, n3, n4, n5>>, List<n5, n4, n3, n2, n1>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<Reverse_v<List<n1, n2, n3, n4, n5, n6>>,
                          List<n6, n5, n4, n3, n2, n1>>);
    static_assert(
        is_same<List<n1, n2, n3, n4, n5, n6>, List<n1, n2, n3, n4, n5, n6>>);
    static_assert(is_same<Reverse_v<List<n5, n4, n3, n2, n1, n6, n7>>,
                          List<n7, n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n5, n4, n3, n2, n1, n6, n7>,
                          List<n5, n4, n3, n2, n1, n6, n7>>);
    static_assert(is_same<Reverse_v<List<n1, n2, n3, n4, n5, n6, n7, n8>>,
                          List<n8, n7, n6, n5, n4, n3, n2, n1>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5, n6, n7, n8>,
                          List<n1, n2, n3, n4, n5, n6, n7, n8>>);
    static_assert(is_same<Reverse_v<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>,
                          List<n1, n2, n3, n4, n5, n6, n7, n8, n9>>);
    static_assert(is_same<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>,
                          List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>);
} // namespace list_reverse_tests
