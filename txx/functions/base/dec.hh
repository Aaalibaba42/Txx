#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace DecImpl
{
    template <Any_t Num>
    struct Dec;

    template <Any_t Num>
    using Dec_v = Dec<Num>::result;

    struct DecFunc
    {
        using is_function = IsFunction;

        template <Any_t Num>
        struct apply
        {
            using result = Dec_v<Num>;
        };
    };
} // namespace DecImpl

using DecImpl::DecFunc;
using DecImpl::Dec_v;
