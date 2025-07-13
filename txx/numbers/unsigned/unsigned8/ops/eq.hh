#pragma once

#include "functions/function.hh"
#include "functions/is_same.hh"
#include "numbers/unsigned/unsigned8/concept.hh"

// We could economize slightly is templating depth by redoing the logic of
// IsSame here, but it would be less readable

namespace Unsigned8EQImpl
{
    template <Unsigned8_t LHS, Unsigned8_t RHS>
    struct Unsigned8EQ;

    template <Unsigned8_t LHS, Unsigned8_t RHS>
    using Unsigned8EQ_v = Unsigned8EQ<LHS, RHS>::result;

    template <Unsigned8_t LHS, Unsigned8_t RHS>
    struct Unsigned8EQ
    {
        using result = IsSame_v<LHS, RHS>;
    };

    struct Unsigned8EQFunc
    {
        using is_function = IsFunction;

        template <Unsigned8_t LHS, Unsigned8_t RHS>
        struct apply
        {
            using result = Unsigned8EQ_v<LHS, RHS>;
        };
    };
} // namespace Unsigned8EQImpl

using Unsigned8EQImpl::Unsigned8EQFunc;
using Unsigned8EQImpl::Unsigned8EQ_v;
