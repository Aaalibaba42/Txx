#pragma once

#include "types/bools/literals.hh"

template <typename Bool>
struct LNot;

template <typename Bool>
using LNot_v = LNot<Bool>::result;

template <typename Bool>
struct LNot
{
    static_assert(false, "LNot with no or wrong operand");
};

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
