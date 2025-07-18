#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "functions/ternary.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"
#include "numbers/unsigned/unsigned8/ops/ge.hh"
#include "numbers/unsigned/unsigned8/ops/sub.hh"
#include "numbers/unsigned/unsigned8/ops/left_shift.hh"
#include "numbers/unsigned/unsigned8/ops/add.hh"

namespace Unsigned8DivImpl
{
    template <Unsigned8_t Dividend, Unsigned8_t Divisor>
    struct Unsigned8DivModCommon;

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t A7, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3,
              Bit_t B4, Bit_t B5, Bit_t B6, Bit_t B7>
    struct Unsigned8DivModCommon<Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>,
                                 Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using Dividend = Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>;
        using Divisor = Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>;
        using Rem0 = Unsigned8<>;

        using NewRem0 =
            Ternary_v<Unsigned8GE_v<Unsigned8<A7>, Divisor>,
                      Unsigned8Sub_v<Unsigned8<A7>, Divisor>, Unsigned8<A7>>;
        using Q0 = Ternary_v<Unsigned8GE_v<Unsigned8<A7>, Divisor>, One, Zero>;

        using ShiftedRem1 = Unsigned8LShift_v<NewRem0, u8_1>;
        using AddedShifted1 = Unsigned8Add_v<ShiftedRem1, Unsigned8<A6>>;
        using NewRem1 =
            Ternary_v<Unsigned8GE_v<AddedShifted1, Divisor>,
                      Unsigned8Sub_v<AddedShifted1, Divisor>, AddedShifted1>;
        using Q1 = Ternary_v<Unsigned8GE_v<AddedShifted1, Divisor>, One, Zero>;

        using ShiftedRem2 = Unsigned8LShift_v<NewRem1, u8_1>;
        using AddedShifted2 = Unsigned8Add_v<ShiftedRem2, Unsigned8<A5>>;
        using NewRem2 =
            Ternary_v<Unsigned8GE_v<AddedShifted2, Divisor>,
                      Unsigned8Sub_v<AddedShifted2, Divisor>, AddedShifted2>;
        using Q2 = Ternary_v<Unsigned8GE_v<AddedShifted2, Divisor>, One, Zero>;

        using ShiftedRem3 = Unsigned8LShift_v<NewRem2, u8_1>;
        using AddedShifted3 = Unsigned8Add_v<ShiftedRem3, Unsigned8<A4>>;
        using NewRem3 =
            Ternary_v<Unsigned8GE_v<AddedShifted3, Divisor>,
                      Unsigned8Sub_v<AddedShifted3, Divisor>, AddedShifted3>;
        using Q3 = Ternary_v<Unsigned8GE_v<AddedShifted3, Divisor>, One, Zero>;

        using ShiftedRem4 = Unsigned8LShift_v<NewRem3, u8_1>;
        using AddedShifted4 = Unsigned8Add_v<ShiftedRem4, Unsigned8<A3>>;
        using NewRem4 =
            Ternary_v<Unsigned8GE_v<AddedShifted4, Divisor>,
                      Unsigned8Sub_v<AddedShifted4, Divisor>, AddedShifted4>;
        using Q4 = Ternary_v<Unsigned8GE_v<AddedShifted4, Divisor>, One, Zero>;

        using ShiftedRem5 = Unsigned8LShift_v<NewRem4, u8_1>;
        using AddedShifted5 = Unsigned8Add_v<ShiftedRem5, Unsigned8<A2>>;
        using NewRem5 =
            Ternary_v<Unsigned8GE_v<AddedShifted5, Divisor>,
                      Unsigned8Sub_v<AddedShifted5, Divisor>, AddedShifted5>;
        using Q5 = Ternary_v<Unsigned8GE_v<AddedShifted5, Divisor>, One, Zero>;

        using ShiftedRem6 = Unsigned8LShift_v<NewRem5, u8_1>;
        using AddedShifted6 = Unsigned8Add_v<ShiftedRem6, Unsigned8<A1>>;
        using NewRem6 =
            Ternary_v<Unsigned8GE_v<AddedShifted6, Divisor>,
                      Unsigned8Sub_v<AddedShifted6, Divisor>, AddedShifted6>;
        using Q6 = Ternary_v<Unsigned8GE_v<AddedShifted6, Divisor>, One, Zero>;

        using ShiftedRem7 = Unsigned8LShift_v<NewRem6, u8_1>;
        using AddedShifted7 = Unsigned8Add_v<ShiftedRem7, Unsigned8<A0>>;
        using NewRem7 =
            Ternary_v<Unsigned8GE_v<AddedShifted7, Divisor>,
                      Unsigned8Sub_v<AddedShifted7, Divisor>, AddedShifted7>;
        using Q7 = Ternary_v<Unsigned8GE_v<AddedShifted7, Divisor>, One, Zero>;

        using quotient = Unsigned8<Q7, Q6, Q5, Q4, Q3, Q2, Q1, Q0>;
        using remainder = NewRem7;
    };

    template <Unsigned8_t Dividend, Unsigned8_t Divisor>
    using Unsigned8Div_v = Unsigned8DivModCommon<Dividend, Divisor>::quotient;

    struct Unsigned8DivFunc
    {
        using is_function = IsFunction;

        template <Unsigned8_t LHS, Unsigned8_t RHS>
        struct apply
        {
            using result = Unsigned8Div_v<LHS, RHS>;
        };
    };
} // namespace Unsigned8DivImpl

using Unsigned8DivImpl::Unsigned8DivFunc;
using Unsigned8DivImpl::Unsigned8Div_v;
