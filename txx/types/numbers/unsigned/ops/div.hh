#pragma once

#include "control_flow/ternary.hh"
#include "types/bits/literals.hh"
#include "types/list/list.hh"
#include "types/list/ops/append.hh"
#include "types/list/ops/reverse.hh"
#include "types/numbers/unsigned/ops/add.hh"
#include "types/numbers/unsigned/ops/ge.hh"
#include "types/numbers/unsigned/ops/left_shift.hh"
#include "types/numbers/unsigned/ops/sub.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/numbers/unsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/utils/fromList.hh"

namespace UnsignedDivImpl
{
    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    struct UnsignedDivStep;

    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    using UnsignedDivStep_quot =
        UnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::quotient;

    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    using UnsignedDivStep_rem =
        UnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::remainder;

    // No more bits
    template <Unsigned_t Divisor, Unsigned_t Remainder, List_t QuotientMSB>
    struct UnsignedDivStep<List<>, Divisor, Remainder, QuotientMSB>
    {
        using quotient = QuotientMSB;
        using remainder = Remainder;
    };

    template <Bit_t B0, Bit_t... BRest, Unsigned_t Divisor,
              Unsigned_t Remainder, List_t QuotientMSB>
    struct UnsignedDivStep<List<B0, BRest...>, Divisor, Remainder, QuotientMSB>
    {
        using Shifted = UnsignedLShift_v<Remainder, Unsigned<One>>;
        using NewRem = UnsignedAdd_v<Shifted, Unsigned<B0>>;

        using UpdatedRem = Ternary_v<UnsignedGE_v<NewRem, Divisor>,
                                     UnsignedSub_v<NewRem, Divisor>, NewRem>;

        using NewQuot =
            ListAppend_v<Ternary_v<UnsignedGE_v<NewRem, Divisor>, One, Zero>,
                         QuotientMSB>;

        using Rec =
            UnsignedDivStep<List<BRest...>, Divisor, UpdatedRem, NewQuot>;

        using quotient = Rec::quotient;
        using remainder = Rec::remainder;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedDivModCommon;

    template <Bit_t... LHSBits>
    struct UnsignedDivModCommon<Unsigned<LHSBits...>, Unsigned<>>
    {
        static_assert(false, "UnsignedModDivCommon: Division by 0");
    };

    template <Bit_t... LHSBits, Bit_t... RHSBits>
    struct UnsignedDivModCommon<Unsigned<LHSBits...>, Unsigned<RHSBits...>>
    {
        using LHSList = List<LHSBits...>;
        using RHSNum = Unsigned<RHSBits...>;
        using LHSBitsMSB = ListReverse_v<LHSList>;

        using Quotient = ListReverse_v<
            UnsignedDivStep_quot<LHSBitsMSB, RHSNum, Unsigned<>, List<>>>;

        using DivStep = UnsignedDivStep<LHSBitsMSB, RHSNum, Unsigned<>, List<>>;

        using remainder = Canonicalize_v<typename DivStep::remainder>;
        using quotient = Canonicalize_v<
            ToUnsigned_v<ListReverse_v<typename DivStep::quotient>>>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedDiv_v = UnsignedDivModCommon<LHS, RHS>::quotient;
} // namespace UnsignedDivImpl

using UnsignedDivImpl::UnsignedDiv_v;
