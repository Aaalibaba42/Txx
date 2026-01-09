#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace TailImpl
{
    template <Any_t L>
    struct Tail;

    template <Any_t L>
    using Tail_v = Tail<L>::result;

    struct TailFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = Tail_v<L>;
        };
    };
} // namespace TailImpl

using TailImpl::Tail_v;
using TailImpl::TailFunc;
