#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace AndImpl
{
    template <Any_t... Vs>
    struct And
    {
        static_assert(false);
    };

    template <Any_t... Vs>
    using And_v = And<Vs...>::result;

    struct AndFunc
    {
        using is_function = IsFunction;

        template <Any_t... Vs>
        struct apply
        {
            using result = And_v<Vs...>;
        };
    };
} // namespace AndImpl

using AndImpl::AndFunc;
using AndImpl::And_v;
