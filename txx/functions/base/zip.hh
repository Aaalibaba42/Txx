#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ZipImpl
{
    template <Any_t L1, Any_t L2>
    struct Zip;

    template <Any_t L1, Any_t L2>
    using Zip_v = Zip<L1, L2>::result;

    struct ZipFunc
    {
        using is_function = IsFunction;

        template <Any_t L1, Any_t L2>
        struct apply
        {
            using result = Zip_v<L1, L2>;
        };
    };
} // namespace ZipImpl

using ZipImpl::Zip_v;
using ZipImpl::ZipFunc;
