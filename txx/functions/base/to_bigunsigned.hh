#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ToBigUnsignedImpl
{
    template <Any_t V>
    struct ToBigUnsigned
    {
        static_assert(false, "Polymorphism failed to find a valid type.");
    };

    template <Any_t V>
    using ToBigUnsigned_v = ToBigUnsigned<V>::result;

    struct ToBigUnsignedFunc
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = ToBigUnsigned_v<V>;
        };
    };
} // namespace ToBigUnsignedImpl

using ToBigUnsignedImpl::ToBigUnsignedFunc;
using ToBigUnsignedImpl::ToBigUnsigned_v;
