#pragma once

#include "list/ops/length.hh"
#include "list/list.hh"

#include "../../utils/is_same.hh"
#include "literals/bigunsigned.hh"

namespace list_legth_tests
{
    static_assert(is_same<ListLength_v<List<>>, bu0>);
    static_assert(is_same<ListLength_v<List<bu1>>, bu1>);
    static_assert(is_same<ListLength_v<List<bu1, bu2>>, bu2>);
    static_assert(is_same<ListLength_v<List<bu1, bu2, bu3, bu4>>, bu4>);
    static_assert(is_same<ListLength_v<List<bu2, bu3, bu2>>, bu3>);
    static_assert(
        is_same<ListLength_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>, bu6>);
    static_assert(is_same<ListLength_v<List<bu5>>, bu1>);
    static_assert(is_same<ListLength_v<List<bu1, bu2>>, bu2>);
    static_assert(is_same<ListLength_v<List<bu3, bu4, bu5>>, bu3>);
    static_assert(is_same<ListLength_v<List<bu2, bu3, bu4, bu5>>, bu4>);
    static_assert(is_same<ListLength_v<List<bu1, bu2, bu3, bu4, bu5>>, bu5>);
    static_assert(
        is_same<ListLength_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>, bu6>);
    static_assert(
        is_same<ListLength_v<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>, bu7>);
    static_assert(
        is_same<ListLength_v<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>,
                bu8>);
    static_assert(
        is_same<ListLength_v<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>,
                bu9>);
} // namespace list_legth_tests
