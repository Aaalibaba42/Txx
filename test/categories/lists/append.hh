#pragma once

#include "../../utils/is_same.hh"
#include "list/list.hh"
#include "list/ops/append.hh"
#include "literals/bigunsigned.hh"

namespace list_append_tests
{
    static_assert(is_same<ListAppend_v<bu1, List<>>, List<bu1>>);
    static_assert(is_same<ListAppend_v<bu2, List<bu1>>, List<bu1, bu2>>);
    static_assert(is_same<ListAppend_v<bu4, List<bu1, bu2, bu3>>,
                          List<bu1, bu2, bu3, bu4>>);
    static_assert(
        is_same<ListAppend_v<bu5, List<bu2, bu4>>, List<bu2, bu4, bu5>>);
    static_assert(is_same<ListAppend_v<bu3, List<bu1>>, List<bu1, bu3>>);
    static_assert(is_same<List<bu1>, List<bu1>>);
    using L6 = ListAppend_v<bu3, List<bu1, bu2>>;
    static_assert(is_same<L6, List<bu1, bu2, bu3>>);
    static_assert(is_same<ListAppend_v<bu4, L6>, List<bu1, bu2, bu3, bu4>>);
    static_assert(is_same<ListAppend_v<bu6, List<bu1, bu2, bu3, bu4, bu5>>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6>>);
    static_assert(is_same<ListAppend_v<bu2, List<bu2, bu3, bu2>>,
                          List<bu2, bu3, bu2, bu2>>);
    static_assert(is_same<ListAppend_v<bu4, List<bu5>>, List<bu5, bu4>>);
    static_assert(is_same<List<bu5>, List<bu5>>);
    static_assert(
        is_same<ListAppend_v<bu6, List<bu1, bu2>>, List<bu1, bu2, bu6>>);
    static_assert(is_same<List<bu1, bu2>, List<bu1, bu2>>);
    static_assert(is_same<ListAppend_v<bu3, List<bu4, bu5, bu6>>,
                          List<bu4, bu5, bu6, bu3>>);
    static_assert(is_same<List<bu4, bu5, bu6>, List<bu4, bu5, bu6>>);
    static_assert(is_same<ListAppend_v<bu1, List<bu2, bu3, bu4, bu5>>,
                          List<bu2, bu3, bu4, bu5, bu1>>);
    static_assert(is_same<List<bu2, bu3, bu4, bu5>, List<bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListAppend_v<bu6, List<bu1, bu2, bu3, bu4, bu5>>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6>>);
    static_assert(
        is_same<List<bu1, bu2, bu3, bu4, bu5>, List<bu1, bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListAppend_v<bu2, List<bu3, bu4, bu5, bu6, bu1, bu2>>,
                          List<bu3, bu4, bu5, bu6, bu1, bu2, bu2>>);
    static_assert(is_same<List<bu3, bu4, bu5, bu6, bu1, bu2>,
                          List<bu3, bu4, bu5, bu6, bu1, bu2>>);
    static_assert(
        is_same<ListAppend_v<bu4, List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>>,
                List<bu5, bu6, bu1, bu2, bu3, bu4, bu5, bu4>>);
    static_assert(is_same<List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>,
                          List<bu5, bu6, bu1, bu2, bu3, bu4, bu5>>);
} // namespace list_append_tests
