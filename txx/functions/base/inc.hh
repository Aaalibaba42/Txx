#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace IncImpl
{
    template <Any_t Num>
    struct Inc;

    template <Any_t Num>
    using Inc_v = Inc<Num>::result;

    struct IncFunc
    {
        using is_function = IsFunction;

        template <Any_t Num>
        struct apply
        {
            using result = Inc_v<Num>;
        };
    };
} // namespace IncImpl

using IncImpl::IncFunc;
using IncImpl::Inc_v;
