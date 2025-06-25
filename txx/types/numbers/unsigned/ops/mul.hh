#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/list/list.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/ops/add.hh"
#include "types/numbers/unsigned/ops/inc.hh"
#include "types/numbers/unsigned/ops/left_shift.hh"
#include "types/numbers/unsigned/unsigned.hh"

template <Unsigned_t LHS, Bit_t RHS, Unsigned_t Shift>
struct MulByBit;

template <Unsigned_t LHS, Bit_t RHS, Unsigned_t Shift>
using MulByBit_v = MulByBit<LHS, RHS, Shift>::result;

template <Unsigned_t LHS, Unsigned_t Shift>
struct MulByBit<LHS, Zero, Shift>
{
    using result = Unsigned<>;
};

template <Unsigned_t LHS, Unsigned_t Shift>
struct MulByBit<LHS, One, Shift>
{
    using result = UnsignedLShift_v<LHS, Shift>;
};

template <Unsigned_t LHS, List_t BList, Unsigned_t Shift>
struct UnsignedMulHelper;

template <Unsigned_t LHS, List_t BList, Unsigned_t Shift>
using UnsignedMulHelper_v = UnsignedMulHelper<LHS, BList, Shift>::result;

template <Unsigned_t LHS, Unsigned_t Shift>
struct UnsignedMulHelper<LHS, List<>, Shift>
{
    using result = Unsigned<>;
};

template <Bit_t R0, Bit_t... RRest, Unsigned_t LHS, Unsigned_t Shift>
struct UnsignedMulHelper<LHS, List<R0, RRest...>, Shift>
{
    using partial = MulByBit_v<LHS, R0, Shift>;
    using rest = UnsignedMulHelper_v<LHS, List<RRest...>, UnsignedInc_v<Shift>>;
    using result = UnsignedAdd_v<partial, rest>;
};

template <Unsigned_t LHS, Unsigned_t RHS>
struct UnsignedMul;

template <Unsigned_t LHS, Unsigned_t RHS>
using UnsignedMul_v = UnsignedMul<LHS, RHS>::result;

template <Bit_t... LHS, Bit_t... RHS>
struct UnsignedMul<Unsigned<LHS...>, Unsigned<RHS...>>
{
    using result = Canonicalize_v<
        UnsignedMulHelper_v<Unsigned<LHS...>, List<RHS...>, Unsigned<>>>;
};
