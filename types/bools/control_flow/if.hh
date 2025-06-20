#pragma once

#include "types/bools/literals.hh"
#include "types/none.hh"

template <typename Cond, typename Success, typename Failure = None>
struct If;

template <typename Cond, typename Success, typename Failure = None>
using If_v = If<Cond, Success, Failure>::result;

template <typename Cond, typename Success, typename Failure>
struct If
{
    static_assert(false, "If could not instantiate correctly");
};

template <typename Success, typename Failure>
struct If<True, Success, Failure>
{
    using result = Success;
};

template <typename Success, typename Failure>
struct If<False, Success, Failure>
{
    using result = Failure;
};
