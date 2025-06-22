#pragma once

#include "types/bools/literals.hh"

template <typename B1, typename B2>
struct LXor;

template <typename B1, typename B2>
using LXor_v = LXor<B1, B2>::result;

template <typename B1, typename B2>
struct LXor
{
    using result = True;
};

template <typename T>
struct LXor<T, T>
{
    using result = False;
};
