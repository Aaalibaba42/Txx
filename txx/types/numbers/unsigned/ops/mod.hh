#pragma once

#include "div.hh"

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedMod_v = UnsignedDivModCommon<LHS, RHS>::remainder;
