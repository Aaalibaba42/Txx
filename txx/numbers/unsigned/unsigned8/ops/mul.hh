#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/ops/add.hh"
#include "numbers/unsigned/unsigned8/ops/left_shift.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace Unsigned8MulImpl
{
    template <Unsigned8_t LHS, Bit_t Mask, Unsigned8_t ShiftAmount>
    struct MulPartial;

    template <Unsigned8_t LHS, Unsigned8_t ShiftAmount>
    struct MulPartial<LHS, Zero, ShiftAmount>
    {
        using result = u8_0;
    };

    template <Unsigned8_t LHS, Unsigned8_t ShiftAmount>
    struct MulPartial<LHS, One, ShiftAmount>
    {
        using result = Unsigned8LShift_v<LHS, ShiftAmount>;
    };

    template <Unsigned8_t LHS, Unsigned8_t RHS>
    struct Unsigned8Mul;

    template <Unsigned8_t LHS, Unsigned8_t RHS>
    using Unsigned8Mul_v = Unsigned8Mul<LHS, RHS>::result;

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t A7, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3,
              Bit_t B4, Bit_t B5, Bit_t B6, Bit_t B7>
    struct Unsigned8Mul<Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>,
                        Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using LHS = Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>;

        using P0 = MulPartial<LHS, B0, u8_0>::result;
        using P1 = MulPartial<LHS, B1, u8_1>::result;
        using P2 = MulPartial<LHS, B2, u8_2>::result;
        using P3 = MulPartial<LHS, B3, u8_3>::result;
        using P4 = MulPartial<LHS, B4, u8_4>::result;
        using P5 = MulPartial<LHS, B5, u8_5>::result;
        using P6 = MulPartial<LHS, B6, u8_6>::result;
        using P7 = MulPartial<LHS, B7, u8_7>::result;

        using S01 = Unsigned8Add_v<P0, P1>;
        using S23 = Unsigned8Add_v<P2, P3>;
        using S45 = Unsigned8Add_v<P4, P5>;
        using S67 = Unsigned8Add_v<P6, P7>;

        using S0123 = Unsigned8Add_v<S01, S23>;
        using S4567 = Unsigned8Add_v<S45, S67>;

        using result = Unsigned8Add_v<S0123, S4567>;
    };

    struct Unsigned8MulFunc
    {
        using is_function = IsFunction;

        template <Unsigned8_t LHS, Unsigned8_t RHS>
        struct apply
        {
            using result = Unsigned8Mul<LHS, RHS>::result;
        };
    };

} // namespace Unsigned8MulImpl

using Unsigned8MulImpl::Unsigned8MulFunc;
using Unsigned8MulImpl::Unsigned8Mul_v;
