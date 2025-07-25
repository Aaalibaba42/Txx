#pragma once

#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "numbers/unsigned/unsigned8/concept.hh"

// We could economize slightly is templating depth by redoing the logic of
// IsSame here, but it would be less readable

namespace EqImpl
{
    template <Any_t LHS, Any_t RHS>
        requires Unsigned8_t<LHS> && Unsigned8_t<RHS>
    struct Eq<LHS, RHS>;

    template <Any_t LHS, Any_t RHS>
        requires Unsigned8_t<LHS> && Unsigned8_t<RHS>
    struct Eq<LHS, RHS>
    {
        using result = IsSame_v<LHS, RHS>;
    };
} // namespace EqImpl
