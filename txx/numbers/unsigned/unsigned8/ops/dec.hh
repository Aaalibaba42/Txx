#pragma once

#include "bits/concept.hh"
#include "bits/ops/fullsubtractor.hh"
#include "functions/base.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace DecImpl
{
    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7, Bit_t Borrow>
    struct SubBorrow8;

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct SubBorrow8<B0, B1, B2, B3, B4, B5, B6, B7, Zero>
    {
        using result = Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7, Bit_t Borrow>
    struct SubBorrow8
    {
        using FS0 = FullSubtractor<B0, Zero, Borrow>;
        using FS1 = FullSubtractor<B1, Zero, typename FS0::Borrow>;
        using FS2 = FullSubtractor<B2, Zero, typename FS1::Borrow>;
        using FS3 = FullSubtractor<B3, Zero, typename FS2::Borrow>;
        using FS4 = FullSubtractor<B4, Zero, typename FS3::Borrow>;
        using FS5 = FullSubtractor<B5, Zero, typename FS4::Borrow>;
        using FS6 = FullSubtractor<B6, Zero, typename FS5::Borrow>;
        using FS7 = FullSubtractor<B7, Zero, typename FS6::Borrow>;

        using result = Unsigned8<typename FS0::Diff, typename FS1::Diff,
                                 typename FS2::Diff, typename FS3::Diff,
                                 typename FS4::Diff, typename FS5::Diff,
                                 typename FS6::Diff, typename FS7::Diff>;
    };

    template <Any_t Num>
        requires Unsigned8_t<Num>
    struct Dec<Num>;

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct Dec<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using result = SubBorrow8<B0, B1, B2, B3, B4, B5, B6, B7, One>::result;
    };
} // namespace DecImpl
