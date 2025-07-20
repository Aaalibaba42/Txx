#pragma once

#include "functions/apply.hh"
#include "functions/concept.hh"
#include "meta/any.hh"

namespace CurryImpl
{
    template <Function_t F, Any_t... BoundArgs>
    struct CurryFunc
    {
        using is_function = IsFunction;

        struct Curried
        {
            using is_function = IsFunction;

            template <Any_t... Rest>
            struct apply
            {
                using result = Apply_v<F, BoundArgs..., Rest...>;
            };
        };

        using result = Curried;
    };

    template <Function_t F, Any_t... BoundArgs>
    using Curry_v = CurryFunc<F, BoundArgs...>::result;
} // namespace CurryImpl

using CurryImpl::CurryFunc;
using CurryImpl::Curry_v;
