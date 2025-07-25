#pragma once

#include "bools/concept.hh"
#include "functions/base.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace OrImpl
{
    template <Any_t LastBool>
        requires Bool_t<LastBool>
    struct Or<LastBool>
    {
        using result = LastBool;
    };

    template <Any_t... Bools>
        requires(Bool_t<Bools> && ...)
    struct Or<True, Bools...>
    {
        using result = True;
    };

    template <Any_t... Bools>
        requires(Bool_t<Bools> && ...)
    struct Or<False, Bools...>
    {
        using result = Or<Bools...>::result;
    };
} // namespace OrImpl
