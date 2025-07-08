#pragma once

#include "bools/concept.hh"
#include "functions/function.hh"
#include "literals/bools.hh"

namespace BoolNotImpl
{
    template <Bool_t Bool>
    struct BoolNot;

    template <Bool_t Bool>
    using BoolNot_v = BoolNot<Bool>::result;

    template <>
    struct BoolNot<True>
    {
        using result = False;
    };

    template <>
    struct BoolNot<False>
    {
        using result = True;
    };

    struct BoolNotFunc
    {
        using is_function = IsFunction;

        template <Bool_t Bool>
        struct apply
        {
            using result = BoolNot_v<Bool>;
        };
    };
} // namespace BoolNotImpl

using BoolNotImpl::BoolNotFunc;
using BoolNotImpl::BoolNot_v;
