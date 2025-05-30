#pragma once

#include "bools/literals.hh"

template <typename... Bools>
struct LAnd;

template <typename... Bools>
using LAnd_v = LAnd<Bools...>::result;

template <typename... Bools>
struct LAnd
{
    static_assert(false, "LAnd with no or wrong operand(s)");
};

template <typename LastBool>
struct LAnd<LastBool>
{
    using result = LastBool;
};

template <typename... Bools>
struct LAnd<False, Bools...>
{
    using result = False;
};

template <typename... Bools>
struct LAnd<True, Bools...>
{
    using result = LAnd_v<Bools...>;
};
