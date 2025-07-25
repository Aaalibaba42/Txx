#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace SubImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Sub;

    template <Any_t LHS, Any_t RHS>
    using Sub_v = Sub<LHS, RHS>::result;

    struct SubFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Sub_v<LHS, RHS>;
        };
    };
} // namespace SubImpl

using SubImpl::SubFunc;
using SubImpl::Sub_v;
