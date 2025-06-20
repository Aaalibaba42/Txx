#pragma once

#include "types/bools/literals.hh"

template <typename... Bools>
struct LOr;

template <typename... Bools>
using LOr_v = LOr<Bools...>::result;

template <typename... Bools>
struct LOr
{
    static_assert(false, "LOr with no or wrong operand(s)");
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
