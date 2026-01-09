#pragma once

#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "meta/any.hh"

// Flip combinator
// Flip f x y = f y x

namespace FlipImpl
{
    template <Function_t F>
    struct FlippedFunc
    {
        using is_function = IsFunction;

        template <Any_t X, Any_t Y>
        struct apply
        {
            using result = Apply_v<F, Y, X>;
        };
    };

    struct FlipFunc
    {
        using is_function = IsFunction;

        template <Function_t F>
        struct apply
        {
            using result = FlippedFunc<F>;
        };
    };

    template <Function_t F>
    using Flip_v = FlippedFunc<F>;
} // namespace FlipImpl

using FlipImpl::Flip_v;
using FlipImpl::FlipFunc;
