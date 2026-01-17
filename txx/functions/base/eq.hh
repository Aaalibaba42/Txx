#pragma once

#include "functions/base/is_same.hh"
#include "functions/function.hh"
#include "meta/any.hh"

namespace EqImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Eq
    {
        using result = IsSame_v<LHS, RHS>;
    };

    template <Any_t LHS, Any_t RHS>
    using Eq_v = Eq<LHS, RHS>::result;

    struct EqFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Eq_v<LHS, RHS>;
        };
    };
} // namespace EqImpl

using EqImpl::EqFunc;
using EqImpl::Eq_v;
