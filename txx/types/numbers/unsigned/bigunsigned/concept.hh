#pragma once

#include "types/bits/concept.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"

template <Bit_t... bits>
void bigunsigned_t_stub(BigUnsigned<bits...>);

template <typename T>
concept BigUnsigned_t = requires(T us) {
    { bigunsigned_t_stub(us) };
};
