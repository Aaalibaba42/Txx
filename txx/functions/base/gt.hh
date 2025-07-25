#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace GtImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Gt;

    template <Any_t LHS, Any_t RHS>
    using Gt_v = Gt<LHS, RHS>::result;

    struct GtFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Gt_v<LHS, RHS>;
        };
    };
} // namespace GtImpl

using GtImpl::GtFunc;
using GtImpl::Gt_v;
