#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace TakeImpl
{
    template <Any_t N, Any_t L>
    struct Take;

    template <Any_t N, Any_t L>
    using Take_v = Take<N, L>::result;

    struct TakeFunc
    {
        using is_function = IsFunction;

        template <Any_t N, Any_t L>
        struct apply
        {
            using result = Take_v<N, L>;
        };
    };
} // namespace TakeImpl

using TakeImpl::Take_v;
using TakeImpl::TakeFunc;
