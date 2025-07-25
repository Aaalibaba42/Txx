#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "literals/bits.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace LShiftImpl
{
    template <Any_t Num, Any_t Amount>
        requires Unsigned8_t<Num> && Unsigned8_t<Amount>
    struct LShift<Num, Amount>;

    // For shiftamount > 7
    template <Any_t Num, Any_t Amount>
        requires Unsigned8_t<Num> && Unsigned8_t<Amount>
    struct LShift<Num, Amount>
    {
        using result = u8_0;
    };

    template <Unsigned8_t Num>
    struct LShift<Num, u8_0>
    {
        using result = Num;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_1>
    {
        using result = Unsigned8<Zero, B0, B1, B2, B3, B4, B5, B6>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_2>
    {
        using result = Unsigned8<Zero, Zero, B0, B1, B2, B3, B4, B5>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_3>
    {
        using result = Unsigned8<Zero, Zero, Zero, B0, B1, B2, B3, B4>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_4>
    {
        using result = Unsigned8<Zero, Zero, Zero, Zero, B0, B1, B2, B3>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_5>
    {
        using result = Unsigned8<Zero, Zero, Zero, Zero, Zero, B0, B1, B2>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_6>
    {
        using result = Unsigned8<Zero, Zero, Zero, Zero, Zero, Zero, B0, B1>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct LShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_7>
    {
        using result = Unsigned8<Zero, Zero, Zero, Zero, Zero, Zero, Zero, B0>;
    };
} // namespace LShiftImpl
