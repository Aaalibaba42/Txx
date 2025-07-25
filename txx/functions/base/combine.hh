#pragma once

#include "functions/base.hh"
#include "functions/concept.hh"
#include "meta/any.hh"

namespace CombineImpl
{
    template <Function_t F, Function_t G>
    struct CombineFunc
    {
        using is_function = IsFunction;

        struct Fn
        {
            using is_function = IsFunction;

            template <Any_t... Xs>
            struct apply
            {
                using result = Apply_v<G, Apply_v<F, Xs...>>;
            };
        };

        using result = Fn;
    };

    template <Function_t F, Function_t G>
    using Combine_v = CombineFunc<F, G>::result;
} // namespace CombineImpl

using CombineImpl::CombineFunc;
using CombineImpl::Combine_v;
