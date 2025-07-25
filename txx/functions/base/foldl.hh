#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace FoldLImpl
{
    template <Any_t Func, Any_t Acc, Any_t List>
    struct FoldL;

    template <Any_t Func, Any_t Acc, Any_t List>
    using FoldL_v = FoldL<Func, Acc, List>::result;

    struct FoldLFunc
    {
        using is_function = IsFunction;

        template <Any_t Func, Any_t Acc, Any_t List>
        struct apply
        {
            using result = FoldL_v<Func, Acc, List>;
        };
    };
} // namespace FoldLImpl

using FoldLImpl::FoldLFunc;
using FoldLImpl::FoldL_v;
