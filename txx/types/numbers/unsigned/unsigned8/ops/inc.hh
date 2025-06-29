#pragma once

#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bits/ops/fulladder.hh"
#include "types/numbers/unsigned/unsigned8/concept.hh"
#include "types/numbers/unsigned/unsigned8/unsigned8.hh"

namespace Unsigned8IncImpl
{
    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7, Bit_t Carry>
    struct AddCarry8;

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct AddCarry8<B0, B1, B2, B3, B4, B5, B6, B7, Zero>
    {
        using result = Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>;
    };

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7, Bit_t Carry>
    struct AddCarry8
    {
        using FA0 = FullAdder<B0, Carry>;
        using FA1 = FullAdder<B1, typename FA0::Carry>;
        using FA2 = FullAdder<B2, typename FA1::Carry>;
        using FA3 = FullAdder<B3, typename FA2::Carry>;
        using FA4 = FullAdder<B4, typename FA3::Carry>;
        using FA5 = FullAdder<B5, typename FA4::Carry>;
        using FA6 = FullAdder<B6, typename FA5::Carry>;
        using FA7 = FullAdder<B7, typename FA6::Carry>;

        using result =
            Unsigned8<typename FA0::Sum, typename FA1::Sum, typename FA2::Sum,
                      typename FA3::Sum, typename FA4::Sum, typename FA5::Sum,
                      typename FA6::Sum, typename FA7::Sum>;
    };

    template <Unsigned8_t Num>
    struct Unsigned8Inc;

    template <Unsigned8_t Num>
    using Unsigned8Inc_v = Unsigned8Inc<Num>::result;

    template <Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t B6, Bit_t B7>
    struct Unsigned8Inc<Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using result = AddCarry8<B0, B1, B2, B3, B4, B5, B6, B7, One>::result;
    };

} // namespace Unsigned8IncImpl

using Unsigned8IncImpl::Unsigned8Inc_v;
