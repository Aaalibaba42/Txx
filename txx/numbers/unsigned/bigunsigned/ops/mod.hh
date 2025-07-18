#pragma once

#include "functions/function.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/div.hh"

namespace BigUnsignedModImpl
{
    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedMod_v =
        BigUnsignedDivImpl::BigUnsignedDivModCommon<LHS, RHS>::remainder;

    struct BigUnsignedModFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedMod_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedModImpl

using BigUnsignedModImpl::BigUnsignedModFunc;
using BigUnsignedModImpl::BigUnsignedMod_v;
