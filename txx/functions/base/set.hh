#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace SetImpl
{
    template <Any_t L, Any_t Elem, Any_t Position>
    struct Set;

    template <Any_t L, Any_t Elem, Any_t Position>
    using Set_v = Set<L, Elem, Position>::result;

    struct SetFunc
    {
        using is_function = IsFunction;

        template <Any_t L, Any_t Elem, Any_t Position>
        struct apply
        {
            using result = Set_v<L, Elem, Position>;
        };
    };
} // namespace SetImpl

using SetImpl::SetFunc;
using SetImpl::Set_v;
