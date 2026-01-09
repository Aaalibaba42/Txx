#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

// Constant function (K combinator)
// Const x y = x
// Curried: Const x = \y -> x

namespace ConstImpl
{
    struct ConstFunc
    {
        using is_function = IsFunction;

        template <Any_t X>
        struct apply
        {
            struct Curried
            {
                using is_function = IsFunction;

                template <Any_t Y>
                struct apply
                {
                    using result = X;
                };
            };

            using result = Curried;
        };
    };

    // Convenience: Const_v<X> returns a function that always returns X
    template <Any_t X>
    using Const_v = ConstFunc::template apply<X>::result;
} // namespace ConstImpl

using ConstImpl::Const_v;
using ConstImpl::ConstFunc;
