#pragma once

#include "bits/concept.hh"
#include "bits/ops/fulladder.hh"
#include "functions/function.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

namespace Unsigned8AddImpl
{
    template <Unsigned8_t A, Unsigned8_t B>
    struct Unsigned8Add;

    template <Unsigned8_t A, Unsigned8_t B>
    using Unsigned8Add_v = Unsigned8Add<A, B>::result;

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t A7, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3,
              Bit_t B4, Bit_t B5, Bit_t B6, Bit_t B7>
    struct Unsigned8Add<Unsigned8<A0, A1, A2, A3, A4, A5, A6, A7>,
                        Unsigned8<B0, B1, B2, B3, B4, B5, B6, B7>>
    {
        using FA0 = FullAdder<A0, B0>;
        using FA1 = FullAdder<A1, B1>;
        using S1 = FullAdder<typename FA0::Carry, typename FA1::Sum>;
        using C1 = FullAdder<typename FA1::Carry, typename S1::Carry>;

        using FA2 = FullAdder<A2, B2>;
        using S2 = FullAdder<typename C1::Sum, typename FA2::Sum>;
        using C2 = FullAdder<typename FA2::Carry, typename S2::Carry>;

        using FA3 = FullAdder<A3, B3>;
        using S3 = FullAdder<typename C2::Sum, typename FA3::Sum>;
        using C3 = FullAdder<typename FA3::Carry, typename S3::Carry>;

        using FA4 = FullAdder<A4, B4>;
        using S4 = FullAdder<typename C3::Sum, typename FA4::Sum>;
        using C4 = FullAdder<typename FA4::Carry, typename S4::Carry>;

        using FA5 = FullAdder<A5, B5>;
        using S5 = FullAdder<typename C4::Sum, typename FA5::Sum>;
        using C5 = FullAdder<typename FA5::Carry, typename S5::Carry>;

        using FA6 = FullAdder<A6, B6>;
        using S6 = FullAdder<typename C5::Sum, typename FA6::Sum>;
        using C6 = FullAdder<typename FA6::Carry, typename S6::Carry>;

        using FA7 = FullAdder<A7, B7>;
        using S7 = FullAdder<typename C6::Sum, typename FA7::Sum>;
        using C7 = FullAdder<typename FA7::Carry, typename S7::Carry>;

        using result =
            Unsigned8<typename FA0::Sum, typename S1::Sum, typename S2::Sum,
                      typename S3::Sum, typename S4::Sum, typename S5::Sum,
                      typename S6::Sum, typename S7::Sum>;
    };

    struct Unsigned8AddFunc
    {
        using is_function = IsFunction;

        template <Unsigned8_t A, Unsigned8_t B>
        struct apply
        {
            using result = Unsigned8Add_v<A, B>;
        };
    };
} // namespace Unsigned8AddImpl

using Unsigned8AddImpl::Unsigned8Add_v;
using Unsigned8AddImpl::Unsigned8AddFunc;
