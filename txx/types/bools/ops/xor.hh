#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

template <Bool_t B1, Bool_t B2>
struct LXor;

template <Bool_t B1, Bool_t B2>
using LXor_v = LXor<B1, B2>::result;

template <Bool_t B1, Bool_t B2>
struct LXor
{
    using result = True;
};

template <Bool_t T>
struct LXor<T, T>
{
    using result = False;
};
