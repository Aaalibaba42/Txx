#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace OrImpl
{
    template <Any_t... Vs>
    struct Or
    {
        static_assert(false);
    };

    template <Any_t... Vs>
    using Or_v = Or<Vs...>::result;

    struct OrFunc
    {
        using is_function = IsFunction;

        template <Any_t... Vs>
        struct apply
        {
            using result = Or_v<Vs...>;
        };
    };

} // namespace OrImpl

using OrImpl::OrFunc;
using OrImpl::Or_v;
