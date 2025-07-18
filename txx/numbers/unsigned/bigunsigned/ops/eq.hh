#pragma once

#include "functions/function.hh"
#include "functions/is_same.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

// LHS and RHS are assumed canonicalized
//
// We could economize slightly is templating depth by redoing the logic of
// IsSame here, but it would be less readable

namespace BigUnsignedEQImpl
{
    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedEQ;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedEQ_v = BigUnsignedEQ<LHS, RHS>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedEQ
    {
        using result = IsSame_v<LHS, RHS>;
    };

    struct BigUnsignedEQFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedEQ_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedEQImpl

using BigUnsignedEQImpl::BigUnsignedEQFunc;
using BigUnsignedEQImpl::BigUnsignedEQ_v;
