#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace MulImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Mul;

    template <Any_t LHS, Any_t RHS>
    using Mul_v = Mul<LHS, RHS>::result;

    struct MulFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Mul_v<LHS, RHS>;
        };
    };
} // namespace MulImpl

using MulImpl::MulFunc;
using MulImpl::Mul_v;
