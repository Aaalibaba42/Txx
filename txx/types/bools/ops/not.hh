#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

template <Bool_t Bool>
struct LNot;

template <Bool_t Bool>
using LNot_v = LNot<Bool>::result;

template <>
struct LNot<True>
{
    using result = False;
};

template <>
struct LNot<False>
{
    using result = True;
};
