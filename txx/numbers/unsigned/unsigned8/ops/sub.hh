#pragma once

#include "bits/concept.hh"
#include "bits/ops/fullsubtractor.hh"
#include "functions/base.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace SubImpl
{
    template <Any_t A, Any_t B>
        requires Unsigned8_t<A> && Unsigned8_t<B>
    struct Sub<A, B>;

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t A7, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3,
              Bit_t B4, Bit_t B5, Bit_t B6, Bit_t B7>
    struct Sub<Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>,
               Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using FS0 = FullSubtractor<A0, B0, Zero>;
        using FS1 = FullSubtractor<A1, B1, typename FS0::Borrow>;
        using FS2 = FullSubtractor<A2, B2, typename FS1::Borrow>;
        using FS3 = FullSubtractor<A3, B3, typename FS2::Borrow>;
        using FS4 = FullSubtractor<A4, B4, typename FS3::Borrow>;
        using FS5 = FullSubtractor<A5, B5, typename FS4::Borrow>;
        using FS6 = FullSubtractor<A6, B6, typename FS5::Borrow>;
        using FS7 = FullSubtractor<A7, B7, typename FS6::Borrow>;

        using result = Unsigned8<typename FS0::Diff, typename FS1::Diff,
                                 typename FS2::Diff, typename FS3::Diff,
                                 typename FS4::Diff, typename FS5::Diff,
                                 typename FS6::Diff, typename FS7::Diff>;
    };
} // namespace SubImpl
