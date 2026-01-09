#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace FilterImpl
{
    template <Any_t Pred, Any_t L>
    struct Filter;

    template <Any_t Pred, Any_t L>
    using Filter_v = Filter<Pred, L>::result;

    struct FilterFunc
    {
        using is_function = IsFunction;

        template <Any_t Pred, Any_t L>
        struct apply
        {
            using result = Filter_v<Pred, L>;
        };
    };
} // namespace FilterImpl

using FilterImpl::Filter_v;
using FilterImpl::FilterFunc;
