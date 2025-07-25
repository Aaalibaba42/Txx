#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace DivImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Div;

    template <Any_t LHS, Any_t RHS>
    using Div_v = Div<LHS, RHS>::result;

    struct DivFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Div_v<LHS, RHS>;
        };
    };
} // namespace DivImpl

using DivImpl::DivFunc;
using DivImpl::Div_v;
