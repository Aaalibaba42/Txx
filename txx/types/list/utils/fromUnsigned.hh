#pragma once

#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/bits/concept.hh"
#include "types/list/list.hh"

template <Unsigned_t T>
struct ToList;

template <Unsigned_t T>
using ToList_v = ToList<T>::result;

template <Bit_t... Bits>
struct ToList<Unsigned<Bits...>>
{
    using result = List<Bits...>;
};
