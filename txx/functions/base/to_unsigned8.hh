#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ToUnsigned8Impl
{
    template <Any_t V>
    struct ToUnsigned8;

    template <Any_t V>
    struct ToUnsigned8
    {
        static_assert(false, "Polymorphism failed to find a valid type.");
    };

    template <Any_t V>
    using ToUnsigned8_v = ToUnsigned8<V>::result;

    struct ToUnsigned8Func
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = ToUnsigned8_v<V>;
        };
    };
} // namespace ToUnsigned8Impl

using ToUnsigned8Impl::ToUnsigned8Func;
using ToUnsigned8Impl::ToUnsigned8_v;
