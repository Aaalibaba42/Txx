#pragma once

#include "bools/literals.hh"
#include "functions/function.hh"
#include "meta/any.hh"

namespace IsSameImpl
{
    template <Any_t T1, Any_t T2>
    struct IsSame;

    template <Any_t T1, Any_t T2>
    using IsSame_v = IsSame<T1, T2>::result;

    template <Any_t T>
    struct IsSame<T, T>
    {
        using result = True;
    };

    template <Any_t T1, Any_t T2>
    struct IsSame
    {
        using result = False;
    };

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
