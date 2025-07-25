#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ReverseImpl
{
    template <Any_t Range>
    struct Reverse;

    template <Any_t Range>
    using Reverse_v = Reverse<Range>::result;

    struct ReverseFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = Reverse_v<L>;
        };
    };
} // namespace ReverseImpl

using ReverseImpl::ReverseFunc;
using ReverseImpl::Reverse_v;
