#pragma once

#include "types/list/list.hh"

template <typename Bit, typename List>
struct Append;

template <typename Bit, typename List>
using Append_v = Append<Bit, List>::result;

template <typename Bit, typename... Bits>
struct Append<Bit, TypeList<Bits...>>
{
    using result = TypeList<Bits..., Bit>;
};
