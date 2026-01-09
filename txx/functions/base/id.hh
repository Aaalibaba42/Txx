#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

// Identity function (I combinator)
// Id x = x

namespace IdImpl
{
    struct IdFunc
    {
        using is_function = IsFunction;

        template <Any_t X>
        struct apply
        {
            using result = X;
        };
    };
} // namespace IdImpl

using IdImpl::IdFunc;
