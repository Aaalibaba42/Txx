#pragma once

#include "bools/concept.hh"
#include "functions/function.hh"
#include "literals/bools.hh"

namespace BoolOrImpl
{
    template <Bool_t... Bools>
    struct BoolOr;

    template <Bool_t... Bools>
    using BoolOr_v = BoolOr<Bools...>::result;

    template <Bool_t LastBool>
    struct BoolOr<LastBool>
    {
        using result = LastBool;
    };

    template <Bool_t... Bools>
    struct BoolOr<True, Bools...>
    {
        using result = True;
    };

    template <Bool_t... Bools>
    struct BoolOr<False, Bools...>
    {
        using result = BoolOr<Bools...>::result;
    };

    struct BoolOrFunc
    {
        using is_function = IsFunction;

        template <Bool_t... Bools>
        struct apply
        {
            using result = BoolOr_v<Bools...>;
        };
    };
} // namespace BoolOrImpl

using BoolOrImpl::BoolOrFunc;
using BoolOrImpl::BoolOr_v;
