#pragma once

#include "bits/concept.hh"
#include "casts/big_unsigned.hh"
#include "functions/base.hh"
#include "functions/base/ternary.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/append.hh"
#include "list/ops/reverse.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/ge.hh"
#include "numbers/unsigned/bigunsigned/ops/left_shift.hh"
#include "numbers/unsigned/bigunsigned/ops/sub.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace DivImpl
{
    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct DivStep;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using DivStep_quot =
        DivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::quotient;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using DivStep_rem =
        DivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::remainder;

    // No more bits
    template <BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct DivStep<List<>, Divisor, Remainder, QuotientMSB>
    {
        using quotient = QuotientMSB;
        using remainder = Remainder;
    };

    template <Bit_t B0, Bit_t... BRest, BigUnsigned_t Divisor,
              BigUnsigned_t Remainder, List_t QuotientMSB>
    struct DivStep<List<B0, BRest...>, Divisor, Remainder, QuotientMSB>
    {
        using Shifted = LShift_v<Remainder, BigUnsigned<One>>;
        using NewRem = Add_v<Shifted, BigUnsigned<B0>>;

        using UpdatedRem =
            Ternary_v<Ge_v<NewRem, Divisor>, Sub_v<NewRem, Divisor>, NewRem>;

        using NewQuot =
            Append_v<Ternary_v<Ge_v<NewRem, Divisor>, One, Zero>, QuotientMSB>;

        using Rec = DivStep<List<BRest...>, Divisor, UpdatedRem, NewQuot>;

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
        using LHSBitsMSB = Reverse_v<LHSList>;

        using Quotient =
            Reverse_v<DivStep_quot<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>>;

        using DS = DivStep<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>;

        using remainder = Canonicalize_v<typename DS::remainder>;
        using quotient =
            Canonicalize_v<ToBigUnsigned_v<Reverse_v<typename DS::quotient>>>;
    };

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Div<LHS, RHS>
    {
        using result = BigUnsignedDivModCommon<LHS, RHS>::quotient;
    };
} // namespace DivImpl
