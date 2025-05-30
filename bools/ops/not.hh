#pragma once

#include "bools/literals.hh"

template <typename Bool>
struct LNot
{
    static_assert(false, "LNot with no operand");
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
