#pragma once

#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "meta/any.hh"

// On combinator
// (f `on` g) x y = f (g x) (g y)
//
// Useful for comparing/combining by a projection:
//   compare `on` length  -- compare lists by their length
//   max `on` fst         -- max of pairs by first element

namespace OnImpl
{
    template <Function_t F, Function_t G>
    struct OnFunc
    {
        using is_function = IsFunction;

        template <Any_t X, Any_t Y>
        struct apply
        {
            using gx = Apply_v<G, X>;
            using gy = Apply_v<G, Y>;
            using result = Apply_v<F, gx, gy>;
        };
    };

    struct OnCombinator
    {
        using is_function = IsFunction;

        template <Function_t F, Function_t G>
        struct apply
        {
            using result = OnFunc<F, G>;
        };
    };

    template <Function_t F, Function_t G>
    using On_v = OnFunc<F, G>;
} // namespace OnImpl

using OnImpl::On_v;
using OnImpl::OnCombinator;
