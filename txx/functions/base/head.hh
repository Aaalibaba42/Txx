#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace HeadImpl
{
    template <Any_t L>
    struct Head;

    template <Any_t L>
    using Head_v = Head<L>::result;

    struct HeadFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = Head_v<L>;
        };
    };
} // namespace HeadImpl

using HeadImpl::Head_v;
using HeadImpl::HeadFunc;
