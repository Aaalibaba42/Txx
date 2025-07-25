#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace AddImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Add;

    template <Any_t LHS, Any_t RHS>
    using Add_v = Add<LHS, RHS>::result;

    struct AddFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Add_v<LHS, RHS>;
        };
    };
} // namespace AddImpl

using AddImpl::AddFunc;
using AddImpl::Add_v;
