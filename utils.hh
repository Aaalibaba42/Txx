#pragma once

#include "bools/literals.hh"

template <typename T, typename U>
struct IsSame
{
    using result = False;
};

template <typename T>
struct IsSame<T, T>
{
    using result = True;
};
