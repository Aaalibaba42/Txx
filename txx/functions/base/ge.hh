#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace GeImpl
{

    template <Any_t LHS, Any_t RHS>
    struct Ge;

    template <Any_t LHS, Any_t RHS>
    using Ge_v = Ge<LHS, RHS>::result;

    struct GeFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Ge_v<LHS, RHS>;
        };
    };
} // namespace GeImpl

using GeImpl::GeFunc;
using GeImpl::Ge_v;
