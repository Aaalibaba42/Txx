#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"
#include "types/functions/function.hh"

namespace BoolAndImpl
{
    template <Bool_t... Bools>
    struct BoolAnd;

    template <Bool_t... Bools>
    using BoolAnd_v = BoolAnd<Bools...>::result;

    template <Bool_t LastBool>
    struct BoolAnd<LastBool>
    {
        using result = LastBool;
    };

    template <Bool_t... Bools>
    struct BoolAnd<False, Bools...>
    {
        using result = False;
    };

    template <Bool_t... Bools>
    struct BoolAnd<True, Bools...>
    {
        using result = BoolAnd_v<Bools...>;
    };

    struct BoolAndFunc
    {
        using is_function = IsFunction;

        template <Bool_t... Bools>
        struct apply
        {
            using result = BoolAnd_v<Bools...>;
        };
    };
} // namespace BoolAndImpl

using BoolAndImpl::BoolAndFunc;
using BoolAndImpl::BoolAnd_v;
