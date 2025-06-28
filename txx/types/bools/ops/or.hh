#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

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
} // namespace BoolOrImpl

using BoolOrImpl::BoolOr_v;
