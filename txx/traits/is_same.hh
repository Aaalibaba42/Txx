#pragma once

#include "types/bools/literals.hh"

template <typename T1, typename T2>
struct IsSame;

template <typename T1, typename T2>
using IsSame_v = IsSame<T1, T2>::result;

template <typename T>
struct IsSame<T, T>
{
    using result = True;
};

template <typename T1, typename T2>
struct IsSame
{
    using result = False;
};
