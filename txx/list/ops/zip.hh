#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace ZipImpl
{
    template <Any_t L1, Any_t L2>
        requires List_t<L1> && List_t<L2>
    struct Zip<L1, L2>;

    template <Any_t... L2Elems>
    struct Zip<List<>, List<L2Elems...>>
    {
        using result = List<>;
    };

    template <Any_t H1, Any_t... T1>
    struct Zip<List<H1, T1...>, List<>>
    {
        using result = List<>;
    };

    template <Any_t H1, Any_t... T1, Any_t H2, Any_t... T2>
    struct Zip<List<H1, T1...>, List<H2, T2...>>
    {
        using pair = List<H1, H2>;
        using tail_result = Zip_v<List<T1...>, List<T2...>>;
        using result = Prepend_v<pair, tail_result>;
    };
} // namespace ZipImpl
