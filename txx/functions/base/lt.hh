#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace LtImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Lt;

    template <Any_t LHS, Any_t RHS>
    using Lt_v = Lt<LHS, RHS>::result;

    struct LtFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Lt_v<LHS, RHS>;
        };
    };
} // namespace LtImpl
using LtImpl::LtFunc;
using LtImpl::Lt_v;
