#pragma once

#include "types/bits/concept.hh"
#include "types/numbers/unsigned/unsigned.hh"

template <Bit_t... bits>
void unsigned_t_stub(Unsigned<bits...>);

template <typename T>
concept Unsigned_t = requires(T us) {
    { unsigned_t_stub(us) };
};
