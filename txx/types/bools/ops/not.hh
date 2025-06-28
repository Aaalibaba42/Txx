#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

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
} // namespace BoolNotImpl

using BoolNotImpl::BoolNot_v;
