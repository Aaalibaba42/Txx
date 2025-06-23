#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

template <Bool_t... Bools>
struct LAnd;

template <Bool_t... Bools>
using LAnd_v = LAnd<Bools...>::result;

template <Bool_t LastBool>
struct LAnd<LastBool>
{
    using result = LastBool;
};

template <Bool_t... Bools>
struct LAnd<False, Bools...>
{
    using result = False;
};

template <Bool_t... Bools>
struct LAnd<True, Bools...>
{
    using result = LAnd_v<Bools...>;
};
