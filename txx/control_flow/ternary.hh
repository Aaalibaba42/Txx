#pragma once

#include "types/bools/literals.hh"

template <typename Cond, typename Success, typename Failure>
struct Ternary;

template <typename Cond, typename Success, typename Failure>
using Ternary_v = Ternary<Cond, Success, Failure>::result;

template <typename Cond, typename Success, typename Failure>
struct Ternary
{
    static_assert(
        false,
        "struct Ternary's Cond is neither struct True, nor struct False");
};

template <typename Success, typename Failure>
struct Ternary<True, Success, Failure>
{
    using result = Success;
};

template <typename Success, typename Failure>
struct Ternary<False, Success, Failure>
{
    using result = Failure;
};
