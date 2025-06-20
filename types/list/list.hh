#pragma once

#include "types/none.hh"

template <typename... Types>
struct TypeList;

template <typename Curr, typename... Rest>
struct TypeList<Curr, Rest...>
{
    using curr = Curr;
    using rest = TypeList<Rest...>;
};

template <>
struct TypeList<>
{
    using curr = None;
    using rest = None;
};
