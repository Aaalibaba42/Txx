#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace IsEmptyImpl
{
    template <Any_t L>
    struct IsEmpty;

    template <Any_t L>
    using IsEmpty_v = IsEmpty<L>::result;

    struct IsEmptyFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = IsEmpty_v<L>;
        };
    };
} // namespace IsEmptyImpl

using IsEmptyImpl::IsEmpty_v;
using IsEmptyImpl::IsEmptyFunc;
