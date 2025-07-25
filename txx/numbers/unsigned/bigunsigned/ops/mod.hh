#pragma once

#include "functions/base.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/div.hh"

namespace ModImpl
{
    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Mod<LHS, RHS>
    {
        using result = DivImpl::BigUnsignedDivModCommon<LHS, RHS>::remainder;
    };
} // namespace ModImpl

using ModImpl::ModFunc;
using ModImpl::Mod_v;
