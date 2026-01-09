#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ZipWithImpl
{
    template <Any_t Func, Any_t L1, Any_t L2>
    struct ZipWith;

    template <Any_t Func, Any_t L1, Any_t L2>
    using ZipWith_v = ZipWith<Func, L1, L2>::result;

    struct ZipWithFunc
    {
        using is_function = IsFunction;

        template <Any_t Func, Any_t L1, Any_t L2>
        struct apply
        {
            using result = ZipWith_v<Func, L1, L2>;
        };
    };
} // namespace ZipWithImpl

using ZipWithImpl::ZipWith_v;
using ZipWithImpl::ZipWithFunc;
