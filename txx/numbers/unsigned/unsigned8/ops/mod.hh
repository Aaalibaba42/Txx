#pragma once

#include "functions/base.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/ops/div.hh"

namespace ModImpl
{
    template <Any_t LHS, Any_t RHS>
        requires Unsigned8_t<LHS> && Unsigned8_t<RHS>
    struct Mod<LHS, RHS>
    {
        using result = DivImpl::DivModCommon<LHS, RHS>::remainder;
    };
} // namespace ModImpl
