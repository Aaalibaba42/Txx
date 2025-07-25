#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace NotImpl
{
    template <Any_t V>
    struct Not
    {
        static_assert(false);
    };

    template <Any_t V>
    using Not_v = Not<V>::result;

    struct NotFunc
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = Not_v<V>;
        };
    };

} // namespace NotImpl

using NotImpl::NotFunc;
using NotImpl::Not_v;
