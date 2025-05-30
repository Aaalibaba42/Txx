#pragma once

#include "bools/literals.hh"

template <typename... Bools>
struct And;

template <>
struct And<>
{
    using result = True;
};

template <typename LastBool>
struct And<LastBool>
{
    using result = LastBool;
};

template <typename... Bools>
struct And<False, Bools...>
{
    using result = False;
};

template <typename... Bools>
struct And<True, Bools...>
{
    using result = And<Bools...>;
};
