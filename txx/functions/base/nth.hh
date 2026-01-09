#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace NthImpl
{
    template <Any_t L, Any_t Idx>
    struct Nth;

    template <Any_t L, Any_t Idx>
    using Nth_v = Nth<L, Idx>::result;

    struct NthFunc
    {
        using is_function = IsFunction;

        template <Any_t L, Any_t Idx>
        struct apply
        {
            using result = Nth_v<L, Idx>;
        };
    };
} // namespace NthImpl

using NthImpl::Nth_v;
using NthImpl::NthFunc;
