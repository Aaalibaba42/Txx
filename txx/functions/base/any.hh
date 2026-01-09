#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace AnyImpl
{
    template <Any_t Pred, Any_t L>
    struct Any;

    template <Any_t Pred, Any_t L>
    using Any_v = Any<Pred, L>::result;

    struct AnyFunc
    {
        using is_function = IsFunction;

        template <Any_t Pred, Any_t L>
        struct apply
        {
            using result = Any_v<Pred, L>;
        };
    };
} // namespace AnyImpl

using AnyImpl::Any_v;
using AnyImpl::AnyFunc;
