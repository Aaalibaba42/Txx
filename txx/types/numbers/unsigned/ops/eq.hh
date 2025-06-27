#pragma once

#include "types/numbers/unsigned/concept.hh"
#include "traits/is_same.hh"

// LHS and RHS are assumed canonicalized
//
// We could economize slightly is templating depth by redoing the logic of
// IsSame here, but it would be less readable

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedEq;

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedEq_v = UnsignedEq<LHS, RHS>::result;

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedEq
{
    using result = IsSame_v<LHS, RHS>;
};
