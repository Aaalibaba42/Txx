#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace CanonicalizeImpl
{
    template <Any_t V>
    struct Canonicalize;

    template <Any_t V>
    using Canonicalize_v = Canonicalize<V>::result;

    struct CanonicalizeFunc
    {
        using is_function = IsFunction;

        template <Any_t V>
        struct apply
        {
            using result = Canonicalize_v<V>;
        };
    };
} // namespace CanonicalizeImpl

using CanonicalizeImpl::CanonicalizeFunc;
using CanonicalizeImpl::Canonicalize_v;
