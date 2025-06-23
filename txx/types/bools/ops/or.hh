#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"

template <Bool_t... Bools>
struct LOr;

template <Bool_t... Bools>
using LOr_v = LOr<Bools...>::result;

template <Bool_t LastBool>
struct LOr<LastBool>
{
    using result = LastBool;
};

template <Bool_t... Bools>
struct LOr<True, Bools...>
{
    using result = True;
};

template <Bool_t... Bools>
struct LOr<False, Bools...>
{
    using result = LOr<Bools...>::result;
};
