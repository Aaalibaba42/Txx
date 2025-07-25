#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ToListImpl
{
    template <Any_t V>
    struct ToList
    {
        static_assert(false, "Polymorphism failed to find a valid type.");
    };

    template <Any_t V>
    using ToList_v = ToList<V>::result;

    struct ToListFunc
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = ToList_v<V>;
        };
    };
} // namespace ToListImpl

using ToListImpl::ToListFunc;
using ToListImpl::ToList_v;
