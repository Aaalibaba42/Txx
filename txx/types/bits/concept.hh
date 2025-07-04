#pragma once

#include "types/bits/literals.hh"

void bit_t_stub(Zero);
void bit_t_stub(One);

template <typename T>
concept Bit_t = requires(T b) {
    { bit_t_stub(b) };
};
