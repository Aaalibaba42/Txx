#pragma once

#include "bools/concept.hh"
#include "functions/base.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace XorImpl
{
    template <Any_t B1, Any_t B2>
        requires Bool_t<B1> && Bool_t<B2>
    struct Xor<B1, B2>
    {
        using result = True;
    };

    template <Any_t T>
        requires Bool_t<T>
    struct Xor<T, T>
    {
        using result = False;
    };
} // namespace XorImpl
