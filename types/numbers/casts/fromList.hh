#pragma once

#include "types/numbers/numbers.hh"
#include "types/list/list.hh"

template <typename List>
struct ToNumber;

template <typename... Bits>
using ToNumber_v = ToNumber<Bits...>::result;

template <typename... Bits>
struct ToNumber<TypeList<Bits...>>
{
    using result = Number<Bits...>;
};
