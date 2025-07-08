#pragma once

#include "bools/concept.hh"
#include "bools/literals.hh"
#include "functions/function.hh"

namespace BoolXorImpl
{
    template <Bool_t B1, Bool_t B2>
    struct BoolXor;

    template <Bool_t B1, Bool_t B2>
    using BoolXor_v = BoolXor<B1, B2>::result;

    template <Bool_t B1, Bool_t B2>
    struct BoolXor
    {
        using result = True;
    };

    template <Bool_t T>
    struct BoolXor<T, T>
    {
        using result = False;
    };

    struct BoolXorFunc
    {
        using is_function = IsFunction;

        template <Bool_t B1, Bool_t B2>
        struct apply
        {
            using result = BoolXor_v<B1, B2>;
        };
    };
} // namespace BoolXorImpl

using BoolXorImpl::BoolXorFunc;
using BoolXorImpl::BoolXor_v;
