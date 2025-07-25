#pragma once

#include "functions/function.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace IsSameImpl
{
    template <Any_t T1, Any_t T2>
    struct IsSame
    {
        using result = False;
    };

    template <Any_t T>
    struct IsSame<T, T>
    {
        using result = True;
    };

    template <Any_t T1, Any_t T2>
    using IsSame_v = IsSame<T1, T2>::result;

    struct IsSameFunc
    {
        using is_function = IsFunction;

        template <Any_t T1, Any_t T2>
        struct apply
        {
            using result = IsSame_v<T1, T2>;
        };
    };
} // namespace IsSameImpl

using IsSameImpl::IsSameFunc;
using IsSameImpl::IsSame_v;
