#pragma once

#include "types/bools/literals.hh"

template <typename T1, typename T2>
struct is_same;

template <typename Same>
struct is_same<Same, Same>
{
    using result = True;
};

template <typename T1, typename T2>
struct is_same
{
    using result = False;
};

template <typename T1, typename T2>
using is_same_v = is_same<T1, T2>::result;
