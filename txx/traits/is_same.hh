#pragma once

#include "types/bools/literals.hh"
#include "types/meta/any.hh"

namespace IsSameImpl
{
    template <Any_t T1, Any_t T2>
    struct IsSame;

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
} // namespace IsSameImpl

template <Any_t T1, Any_t T2>
using IsSame_v = IsSameImpl::IsSame<T1, T2>::result;
