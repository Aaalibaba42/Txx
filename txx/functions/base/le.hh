#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace LeImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Le;

    template <Any_t LHS, Any_t RHS>
    using Le_v = Le<LHS, RHS>::result;

    struct LeFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Le_v<LHS, RHS>;
        };
    };
} // namespace LeImpl

using LeImpl::LeFunc;
using LeImpl::Le_v;
