#pragma once

#include "types/meta/any.hh"
#include "types/meta/none.hh"

template <Any_t... Elems>
struct List;

template <Any_t Curr, Any_t... Rest>
struct List<Curr, Rest...>
{
    using curr = Curr;
    using rest = List<Rest...>;
};

template <Any_t Curr>
struct List<Curr>
{
    using curr = Curr;
    using rest = None;
};

template <>
struct List<>
{
    using curr = None;
    using rest = None;
};
