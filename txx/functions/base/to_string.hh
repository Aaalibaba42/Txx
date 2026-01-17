#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ToStringImpl
{
    template <Any_t V>
    struct ToString
    {
        static_assert(false, "Polymorphism failed to find a valid type.");
    };

    template <Any_t V>
    using ToString_v = ToString<V>::result;

    struct ToStringFunc
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = ToString_v<V>;
        };
    };
} // namespace ToStringImpl

using ToStringImpl::ToStringFunc;
using ToStringImpl::ToString_v;

