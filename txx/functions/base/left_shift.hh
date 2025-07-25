#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace LShiftImpl
{
    template <Any_t Value, Any_t Amount>
    struct LShift;

    template <Any_t Value, Any_t Amount>
    using LShift_v = LShift<Value, Amount>::result;

    struct LShiftFunc
    {
        using is_function = IsFunction;

        template <Any_t Value, Any_t Amount>
        struct apply
        {
            using result = LShift_v<Value, Amount>;
        };
    };
} // namespace LShiftImpl

using LShiftImpl::LShiftFunc;
using LShiftImpl::LShift_v;
