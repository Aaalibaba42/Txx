#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace AllImpl
{
    template <Any_t Pred, Any_t L>
    struct All;

    template <Any_t Pred, Any_t L>
    using All_v = All<Pred, L>::result;

    struct AllFunc
    {
        using is_function = IsFunction;

        template <Any_t Pred, Any_t L>
        struct apply
        {
            using result = All_v<Pred, L>;
        };
    };
} // namespace AllImpl

using AllImpl::All_v;
using AllImpl::AllFunc;
