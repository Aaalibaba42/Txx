#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace CompareImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Compare;

    template <Any_t LHS, Any_t RHS>
    using Compare_v = Compare<LHS, RHS>::result;

    struct CompareFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Compare_v<LHS, RHS>;
        };
    };
} // namespace CompareImpl

using CompareImpl::CompareFunc;
using CompareImpl::Compare_v;

