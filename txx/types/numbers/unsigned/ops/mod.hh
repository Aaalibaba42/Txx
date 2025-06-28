#pragma once

#include "div.hh"

namespace UnsignedModImpl
{
    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedMod_v =
        UnsignedDivImpl::UnsignedDivModCommon<LHS, RHS>::remainder;
} // namespace UnsignedModImpl

using UnsignedModImpl::UnsignedMod_v;
