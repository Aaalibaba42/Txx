#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace LengthImpl
{
    template <Any_t V>
    struct Length;

    template <Any_t V>
    using Length_v = Length<V>::result;

    struct LengthFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = Length_v<L>;
        };
    };

} // namespace LengthImpl

using LengthImpl::LengthFunc;
using LengthImpl::Length_v;
