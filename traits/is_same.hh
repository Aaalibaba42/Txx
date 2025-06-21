#pragma once

#include "types/bools/literals.hh"

template <typename T1, typename T2>
struct is_same;

template <typename T1, typename T2>
using is_same_v = is_same<T1, T2>::result;

template <typename T>
struct is_same<T, T>
{
    using result = True;
};

template <typename T1, typename T2>
struct is_same
{
    using result = False;
};
