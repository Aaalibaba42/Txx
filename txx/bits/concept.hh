#pragma once

#include "literals/bits.hh"

namespace BitTImpl
{
    void bit_t_stub(Zero);
    void bit_t_stub(One);

    template <typename T>
    concept Bit_t = requires(T b) {
        { bit_t_stub(b) };
    };
} // namespace BitTImpl

using BitTImpl::Bit_t;
