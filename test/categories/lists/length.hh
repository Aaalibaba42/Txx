#pragma once

#include "types/list/ops/length.hh"
#include "types/list/list.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

namespace list_legth_tests
{
    static_assert(is_same<ListLength_v<List<>>, n0>);
    static_assert(is_same<ListLength_v<List<n1>>, n1>);
    static_assert(is_same<ListLength_v<List<n1, n2>>, n2>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4>>, n4>);
    static_assert(is_same<ListLength_v<List<n2, n3, n2>>, n3>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6>>, n6>);
    static_assert(is_same<ListLength_v<List<n5>>, n1>);
    static_assert(is_same<ListLength_v<List<n1, n2>>, n2>);
    static_assert(is_same<ListLength_v<List<n3, n4, n5>>, n3>);
    static_assert(is_same<ListLength_v<List<n2, n3, n4, n5>>, n4>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5>>, n5>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6>>, n6>);
    static_assert(is_same<ListLength_v<List<n5, n4, n3, n2, n1, n6, n7>>, n7>);
    static_assert(
        is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6, n7, n8>>, n8>);
    static_assert(
        is_same<ListLength_v<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>, n9>);
} // namespace list_legth_tests
