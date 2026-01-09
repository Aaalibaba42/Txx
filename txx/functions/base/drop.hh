#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace DropImpl
{
    template <Any_t N, Any_t L>
    struct Drop;

    template <Any_t N, Any_t L>
    using Drop_v = Drop<N, L>::result;

    struct DropFunc
    {
        using is_function = IsFunction;

        template <Any_t N, Any_t L>
        struct apply
        {
            using result = Drop_v<N, L>;
        };
    };
} // namespace DropImpl

using DropImpl::Drop_v;
using DropImpl::DropFunc;
