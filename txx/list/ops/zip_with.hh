#pragma once

#include "functions/base.hh"
#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "meta/any.hh"

namespace ZipWithImpl
{
    template <Any_t Func, Any_t L1, Any_t L2>
        requires Function_t<Func> && List_t<L1> && List_t<L2>
    struct ZipWith<Func, L1, L2>;

    template <Function_t Func, Any_t... L2Elems>
    struct ZipWith<Func, List<>, List<L2Elems...>>
    {
        using result = List<>;
    };

    template <Function_t Func, Any_t H1, Any_t... T1>
    struct ZipWith<Func, List<H1, T1...>, List<>>
    {
        using result = List<>;
    };

    template <Function_t Func, Any_t H1, Any_t... T1, Any_t H2, Any_t... T2>
    struct ZipWith<Func, List<H1, T1...>, List<H2, T2...>>
    {
        using head_result = Apply_v<Func, H1, H2>;
        using tail_result = ZipWith_v<Func, List<T1...>, List<T2...>>;
        using result = Prepend_v<head_result, tail_result>;
    };
} // namespace ZipWithImpl
