#pragma once

#include "../../utils/is_same.hh"
#include "list/list.hh"
#include "list/ops/reverse.hh"
#include "literals/bigunsigned.hh"

namespace list_reverse_tests
{
    static_assert(is_same<ListReverse_v<List<>>, List<>>);
    static_assert(is_same<ListReverse_v<List<bu1>>, List<bu1>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2>>, List<bu2, bu1>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2, bu3, bu4>>,
                          List<bu4, bu3, bu2, bu1>>);
    static_assert(
        is_same<ListReverse_v<List<bu2, bu3, bu2>>, List<bu2, bu3, bu2>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>,
                          List<bu6, bu5, bu4, bu3, bu2, bu1>>);
    static_assert(is_same<ListReverse_v<List<bu5>>, List<bu5>>);
    static_assert(is_same<List<bu5>, List<bu5>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2>>, List<bu2, bu1>>);
    static_assert(is_same<List<bu1, bu2>, List<bu1, bu2>>);
    static_assert(
        is_same<ListReverse_v<List<bu3, bu4, bu5>>, List<bu5, bu4, bu3>>);
    static_assert(is_same<List<bu3, bu4, bu5>, List<bu3, bu4, bu5>>);
    static_assert(is_same<ListReverse_v<List<bu2, bu3, bu4, bu5>>,
                          List<bu5, bu4, bu3, bu2>>);
    static_assert(is_same<List<bu2, bu3, bu4, bu5>, List<bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2, bu3, bu4, bu5>>,
                          List<bu5, bu4, bu3, bu2, bu1>>);
    static_assert(
        is_same<List<bu1, bu2, bu3, bu4, bu5>, List<bu1, bu2, bu3, bu4, bu5>>);
    static_assert(is_same<ListReverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6>>,
                          List<bu6, bu5, bu4, bu3, bu2, bu1>>);
    static_assert(is_same<List<bu1, bu2, bu3, bu4, bu5, bu6>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6>>);
    static_assert(
        is_same<ListReverse_v<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>,
                List<bu7, bu6, bu1, bu2, bu3, bu4, bu5>>);
    static_assert(is_same<List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>,
                          List<bu5, bu4, bu3, bu2, bu1, bu6, bu7>>);
    static_assert(
        is_same<ListReverse_v<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>,
                List<bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>);
    static_assert(is_same<List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>,
                          List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8>>);
    static_assert(
        is_same<
            ListReverse_v<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>,
            List<bu1, bu2, bu3, bu4, bu5, bu6, bu7, bu8, bu9>>);
    static_assert(is_same<List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>,
                          List<bu9, bu8, bu7, bu6, bu5, bu4, bu3, bu2, bu1>>);
} // namespace list_reverse_tests
