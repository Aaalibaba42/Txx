#pragma once

#include "types/list/list.hh"
#include "types/numbers/unsigned/unsigned.hh"

template <typename List>
struct ToUnsigned;

template <typename... Bits>
using ToUnsigned_v = ToUnsigned<Bits...>::result;

template <typename... Bits>
struct ToUnsigned<TypeList<Bits...>>
{
    using result = Unsigned<Bits...>;
};
