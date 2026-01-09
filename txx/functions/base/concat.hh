#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ConcatImpl
{
    template <Any_t L1, Any_t L2>
    struct Concat;

    template <Any_t L1, Any_t L2>
    using Concat_v = Concat<L1, L2>::result;

    struct ConcatFunc
    {
        using is_function = IsFunction;

        template <Any_t L1, Any_t L2>
        struct apply
        {
            using result = Concat_v<L1, L2>;
        };
    };
} // namespace ConcatImpl

using ConcatImpl::Concat_v;
using ConcatImpl::ConcatFunc;
