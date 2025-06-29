#pragma once

#include "control_flow/ternary.hh"
#include "types/bits/literals.hh"
#include "types/list/list.hh"
#include "types/list/ops/append.hh"
#include "types/list/ops/reverse.hh"
#include "types/numbers/unsigned/bigunsigned/ops/add.hh"
#include "types/numbers/unsigned/bigunsigned/ops/ge.hh"
#include "types/numbers/unsigned/bigunsigned/ops/left_shift.hh"
#include "types/numbers/unsigned/bigunsigned/ops/sub.hh"
#include "types/numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "types/numbers/unsigned/bigunsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/bigunsigned/utils/fromList.hh"

namespace BigUnsignedDivImpl
{
    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct BigUnsignedDivStep;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using BigUnsignedDivStep_quot =
        BigUnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::quotient;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using BigUnsignedDivStep_rem =
        BigUnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::remainder;

    // No more bits
    template <BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct BigUnsignedDivStep<List<>, Divisor, Remainder, QuotientMSB>
    {
        using quotient = QuotientMSB;
        using remainder = Remainder;
    };

    template <Bit_t B0, Bit_t... BRest, BigUnsigned_t Divisor,
              BigUnsigned_t Remainder, List_t QuotientMSB>
    struct BigUnsignedDivStep<List<B0, BRest...>, Divisor, Remainder,
                              QuotientMSB>
    {
        using Shifted = BigUnsignedLShift_v<Remainder, BigUnsigned<One>>;
        using NewRem = BigUnsignedAdd_v<Shifted, BigUnsigned<B0>>;

        using UpdatedRem = Ternary_v<BigUnsignedGE_v<NewRem, Divisor>,
                                     BigUnsignedSub_v<NewRem, Divisor>, NewRem>;

        using NewQuot =
            ListAppend_v<Ternary_v<BigUnsignedGE_v<NewRem, Divisor>, One, Zero>,
                         QuotientMSB>;

        using Rec =
            BigUnsignedDivStep<List<BRest...>, Divisor, UpdatedRem, NewQuot>;

        using quotient = Rec::quotient;
        using remainder = Rec::remainder;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedDivModCommon;

    template <Bit_t... LHSBits>
    struct BigUnsignedDivModCommon<BigUnsigned<LHSBits...>, BigUnsigned<>>
    {
        static_assert(false, "BigUnsignedModDivCommon: Division by 0");
    };

    template <Bit_t... LHSBits, Bit_t... RHSBits>
    struct BigUnsignedDivModCommon<BigUnsigned<LHSBits...>,
                                   BigUnsigned<RHSBits...>>
    {
        using LHSList = List<LHSBits...>;
        using RHSNum = BigUnsigned<RHSBits...>;
        using LHSBitsMSB = ListReverse_v<LHSList>;

        using Quotient = ListReverse_v<
            BigUnsignedDivStep_quot<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>>;

        using DivStep =
            BigUnsignedDivStep<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>;

        using remainder =
            BigUnsignedCanonicalize_v<typename DivStep::remainder>;
        using quotient = BigUnsignedCanonicalize_v<
            ToBigUnsigned_v<ListReverse_v<typename DivStep::quotient>>>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedDiv_v = BigUnsignedDivModCommon<LHS, RHS>::quotient;
} // namespace BigUnsignedDivImpl

using BigUnsignedDivImpl::BigUnsignedDiv_v;
