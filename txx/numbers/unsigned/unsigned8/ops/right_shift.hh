#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "literals/bits.hh"
#include "literals/unsigned8.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace RShiftImpl
{
    template <Any_t Num, Any_t Amount>
        requires Unsigned8_t<Num> && Unsigned8_t<Amount>
    struct RShift<Num, Amount>;

    // For shiftamount > 7
    template <Any_t Num, Any_t Amount>
        requires Unsigned8_t<Num> && Unsigned8_t<Amount>
    struct RShift<Num, Amount>
    {
        using result = u8_0;
    };

    template <Unsigned8_t Num>
    struct RShift<Num, u8_0>
    {
        using result = Num;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_1>
    {
        using result = Unsigned8<B1, B2, B3, B4, B5, B6, B7, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_2>
    {
        using result = Unsigned8<B2, B3, B4, B5, B6, B7, Zero, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_3>
    {
        using result = Unsigned8<B3, B4, B5, B6, B7, Zero, Zero, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_4>
    {
        using result = Unsigned8<B4, B5, B6, B7, Zero, Zero, Zero, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_5>
    {
        using result = Unsigned8<B5, B6, B7, Zero, Zero, Zero, Zero, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_6>
    {
        using result = Unsigned8<B6, B7, Zero, Zero, Zero, Zero, Zero, Zero>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct RShift<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>, u8_7>
    {
        using result = Unsigned8<B7, Zero, Zero, Zero, Zero, Zero, Zero, Zero>;
    };
} // namespace RShiftImpl
