#pragma once

#include "bools/concept.hh"
#include "functions/base.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace AndImpl
{
    template <Any_t LastBool>
        requires Bool_t<LastBool>
    struct And<LastBool>
    {
        using result = LastBool;
    };

    template <Any_t... Bools>
        requires(Bool_t<Bools> && ...)
    struct And<False, Bools...>
    {
        using result = False;
    };

    template <Any_t... Bools>
        requires(Bool_t<Bools> && ...)
    struct And<True, Bools...>
    {
        using result = And_v<Bools...>;
    };
} // namespace AndImpl
