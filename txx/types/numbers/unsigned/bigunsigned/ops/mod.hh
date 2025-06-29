#pragma once

#include "div.hh"

namespace BigUnsignedModImpl
{
    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedMod_v =
        BigUnsignedDivImpl::BigUnsignedDivModCommon<LHS, RHS>::remainder;
} // namespace BigUnsignedModImpl

using BigUnsignedModImpl::BigUnsignedMod_v;
