#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"
#include "types/meta/any.hh"

template <Bool_t Cond, Any_t Success, Any_t Failure>
struct Ternary;

template <Bool_t Cond, Any_t Success, Any_t Failure>
using Ternary_v = Ternary<Cond, Success, Failure>::result;

template <Any_t Success, Any_t Failure>
struct Ternary<True, Success, Failure>
{
    using result = Success;
};

template <Any_t Success, Any_t Failure>
struct Ternary<False, Success, Failure>
{
    using result = Failure;
};
