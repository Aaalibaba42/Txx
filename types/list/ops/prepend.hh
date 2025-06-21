#pragma once

#include "types/list/list.hh"

template <typename Bit, typename List>
struct Prepend;

template <typename Bit, typename List>
using Prepend_v = Prepend<Bit, List>::result;

template <typename Bit, typename... Bits>
struct Prepend<Bit, TypeList<Bits...>>
{
    using result = TypeList<Bit, Bits...>;
};
