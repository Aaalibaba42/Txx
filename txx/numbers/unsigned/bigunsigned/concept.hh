#pragma once

#include "bits/concept.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"

namespace BigUnsignedConceptImpl
{
    template <Bit_t... bits>
    void bigunsigned_t_stub(BigUnsigned<bits...>);

    template <typename T>
    concept BigUnsigned_t = requires(T bu) {
        { bigunsigned_t_stub(bu) };
    };
} // namespace BigUnsignedConceptImpl

using BigUnsignedConceptImpl::BigUnsigned_t;
