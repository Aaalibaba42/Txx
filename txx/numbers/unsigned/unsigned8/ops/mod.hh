#pragma once

#include "functions/function.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/ops/div.hh"

namespace Unsigned8ModImpl
{
    template <Unsigned8_t LHS, Unsigned8_t RHS>
    using Unsigned8Mod_v =
        Unsigned8DivImpl::Unsigned8DivModCommon<LHS, RHS>::remainder;

    struct Unsigned8ModFunc
    {
        using is_function = IsFunction;

        template <Unsigned8_t LHS, Unsigned8_t RHS>
        struct apply
        {
            using result = Unsigned8Mod_v<LHS, RHS>;
        };
    };
} // namespace Unsigned8ModImpl

using Unsigned8ModImpl::Unsigned8ModFunc;
using Unsigned8ModImpl::Unsigned8Mod_v;
