#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

template <Bool_t B1, Bool_t B2>
struct BoolXor;

template <Bool_t B1, Bool_t B2>
using BoolXor_v = BoolXor<B1, B2>::result;

template <Bool_t B1, Bool_t B2>
struct BoolXor
{
    using result = True;
};

template <Bool_t T>
struct BoolXor<T, T>
{
    using result = False;
};
