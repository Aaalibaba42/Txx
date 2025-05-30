#pragma once

#include "bools/literals.hh"

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
