#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "functions/base/compare.hh"
#include "functions/base/eq.hh"
#include "functions/base/lt.hh"
#include "functions/base/ternary.hh"
#include "literals/ordering.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace CompareImpl
{
    template <Any_t L1, Any_t L2>
        requires List_t<L1> && List_t<L2>
    struct CompareCharLists;

    template <Any_t L1, Any_t L2>
        requires List_t<L1> && List_t<L2>
    using CompareCharLists_v = CompareCharLists<L1, L2>::result;

    // Both empty: equal
    template <>
    struct CompareCharLists<List<>, List<>>
    {
        using result = Equal;
    };

    // LHS empty, RHS non-empty: LHS is shorter, so LT
    template <Unsigned8_t H, Unsigned8_t... T>
    struct CompareCharLists<List<>, List<H, T...>>
    {
        using result = Lower;
    };

    // LHS non-empty, RHS empty: LHS is longer, so GT
    template <Unsigned8_t H, Unsigned8_t... T>
    struct CompareCharLists<List<H, T...>, List<>>
    {
        using result = Greater;
    };

    // Both non-empty: compare heads, then tails
    template <Unsigned8_t H1, Unsigned8_t... T1, Unsigned8_t H2, Unsigned8_t... T2>
    struct CompareCharLists<List<H1, T1...>, List<H2, T2...>>
    {
        using heads_eq = Eq_v<H1, H2>;
        using h1_lt_h2 = Lt_v<H1, H2>;
        using head_order = Ternary_v<h1_lt_h2, Lower, Greater>;
        using tail_order = CompareCharLists_v<List<T1...>, List<T2...>>;
        using result = Ternary_v<heads_eq, tail_order, head_order>;
    };

    // String comparison via list comparison
    template <Any_t S1, Any_t S2>
        requires String_t<S1> && String_t<S2>
    struct Compare<S1, S2>
    {
        using result = CompareCharLists_v<ToList_v<S1>, ToList_v<S2>>;
    };
} // namespace CompareImpl

