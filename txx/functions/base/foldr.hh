#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace FoldRImpl
{
    template <Any_t Func, Any_t List, Any_t Acc>
    struct FoldR;

    template <Any_t Func, Any_t List, Any_t Acc>
    using FoldR_v = FoldR<Func, List, Acc>::result;

    struct FoldRFunc
    {
        using is_function = IsFunction;

        template <Any_t Func, Any_t List, Any_t Acc>
        struct apply
        {
            using result = FoldR_v<Func, List, Acc>;
        };
    };
} // namespace FoldRImpl

using FoldRImpl::FoldRFunc;
using FoldRImpl::FoldR_v;
