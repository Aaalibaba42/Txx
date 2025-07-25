#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace RShiftImpl
{
    template <Any_t Value, Any_t Amount>
    struct RShift;

    template <Any_t Value, Any_t Amount>
    using RShift_v = RShift<Value, Amount>::result;

    struct RShiftFunc
    {
        using is_function = IsFunction;

        template <Any_t Value, Any_t Amount>
        struct apply
        {
            using result = RShift_v<Value, Amount>;
        };
    };
} // namespace RShiftImpl

using RShiftImpl::RShiftFunc;
using RShiftImpl::RShift_v;
