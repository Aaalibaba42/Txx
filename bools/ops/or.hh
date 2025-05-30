#pragma once

#include "bools/literals.hh"

template <typename... Bools>
struct LOr
{
    static_assert(false, "LOr with no operand");
};

template <typename LastBool>
struct LOr<LastBool>
{
    using result = LastBool;
};

template <typename... Bools>
struct LOr<True, Bools...>
{
    using result = True;
};

template <typename... Bools>
struct LOr<False, Bools...>
{
    using result = LOr<Bools...>::result;
};
