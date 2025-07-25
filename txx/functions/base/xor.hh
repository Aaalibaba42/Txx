#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace XorImpl
{
    template <Any_t V1, Any_t V2>
    struct Xor
    {
        static_assert(false);
    };

    template <Any_t V1, Any_t V2>
    using Xor_v = Xor<V1, V2>::result;

    struct XorFunc
    {
        using is_function = IsFunction;

        template <Any_t V1, Any_t V2>
        struct apply
        {
            using result = Xor_v<V1, V2>;
        };
    };
} // namespace XorImpl

using XorImpl::XorFunc;
using XorImpl::Xor_v;
