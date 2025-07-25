#pragma once

#include "bools/concept.hh"
#include "functions/base.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace NotImpl
{
    template <Any_t Bool>
        requires Bool_t<Bool>
    struct Not<Bool>
    {
        static_assert(false, "Unreachable");
    };

    template <>
    struct Not<True>
    {
        using result = False;
    };

    template <>
    struct Not<False>
    {
        using result = True;
    };
} // namespace NotImpl
