#pragma once

#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

// LHS and RHS are assumed canonicalized
//
// We could economize slightly is templating depth by redoing the logic of
// IsSame here, but it would be less readable

namespace EqImpl
{
    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Eq<LHS, RHS>;

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Eq<LHS, RHS>
    {
        using result = IsSame_v<LHS, RHS>;
    };
} // namespace EqImpl
