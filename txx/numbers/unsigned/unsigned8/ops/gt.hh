#pragma once

#include "bits/concept.hh"
#include "functions/base.hh"
#include "literals/bits.hh"
#include "literals/bools.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "numbers/unsigned/unsigned8/unsigned8.hh"

// This might not be the most elegant design, but it works, and has very shallow
// instantiation depth, so I guess it's okay

namespace GtImpl
{
    template <Any_t LHS, Any_t RHS>
        requires Unsigned8_t<LHS> && Unsigned8_t<RHS>
    struct Gt<LHS, RHS>;

    template <Unsigned8_t Same>
    struct Gt<Same, Same>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4,
              Bit_t B5, Bit_t B6>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, A5, A6, One>,
              Unsigned8<B0, B1, B2, B3, B4, B5, B6, Zero>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t A6, Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4,
              Bit_t B5, Bit_t B6>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, A5, A6, Zero>,
              Unsigned8<B0, B1, B2, B3, B4, B5, B6, One>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, A5, One, C7>,
              Unsigned8<B0, B1, B2, B3, B4, B5, Zero, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t A5,
              Bit_t B0, Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t B5,
              Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, A5, Zero, C7>,
              Unsigned8<B0, B1, B2, B3, B4, B5, One, C7>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t B0,
              Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, One, C6, C7>,
              Unsigned8<B0, B1, B2, B3, B4, Zero, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t A4, Bit_t B0,
              Bit_t B1, Bit_t B2, Bit_t B3, Bit_t B4, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, A4, Zero, C6, C7>,
              Unsigned8<B0, B1, B2, B3, B4, One, C6, C7>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t B0, Bit_t B1,
              Bit_t B2, Bit_t B3, Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, One, C5, C6, C7>,
              Unsigned8<B0, B1, B2, B3, Zero, C5, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t A3, Bit_t B0, Bit_t B1,
              Bit_t B2, Bit_t B3, Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, A3, Zero, C5, C6, C7>,
              Unsigned8<B0, B1, B2, B3, One, C5, C6, C7>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t B0, Bit_t B1, Bit_t B2,
              Bit_t C4, Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, One, C4, C5, C6, C7>,
              Unsigned8<B0, B1, B2, Zero, C4, C5, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t A2, Bit_t B0, Bit_t B1, Bit_t B2,
              Bit_t C4, Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, A2, Zero, C4, C5, C6, C7>,
              Unsigned8<B0, B1, B2, One, C4, C5, C6, C7>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t A1, Bit_t B0, Bit_t B1, Bit_t C3, Bit_t C4,
              Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, One, C3, C4, C5, C6, C7>,
              Unsigned8<B0, B1, Zero, C3, C4, C5, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t A1, Bit_t B0, Bit_t B1, Bit_t C3, Bit_t C4,
              Bit_t C5, Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, A1, Zero, C3, C4, C5, C6, C7>,
              Unsigned8<B0, B1, One, C3, C4, C5, C6, C7>>
    {
        using result = False;
    };

    template <Bit_t A0, Bit_t B0, Bit_t C2, Bit_t C3, Bit_t C4, Bit_t C5,
              Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, One, C2, C3, C4, C5, C6, C7>,
              Unsigned8<B0, Zero, C2, C3, C4, C5, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t A0, Bit_t B0, Bit_t C2, Bit_t C3, Bit_t C4, Bit_t C5,
              Bit_t C6, Bit_t C7>
    struct Gt<Unsigned8<A0, Zero, C2, C3, C4, C5, C6, C7>,
              Unsigned8<B0, One, C2, C3, C4, C5, C6, C7>>
    {
        using result = False;
    };

    template <Bit_t C1, Bit_t C2, Bit_t C3, Bit_t C4, Bit_t C5, Bit_t C6,
              Bit_t C7>
    struct Gt<Unsigned8<One, C1, C2, C3, C4, C5, C6, C7>,
              Unsigned8<Zero, C1, C2, C3, C4, C5, C6, C7>>
    {
        using result = True;
    };
    template <Bit_t C1, Bit_t C2, Bit_t C3, Bit_t C4, Bit_t C5, Bit_t C6,
              Bit_t C7>
    struct Gt<Unsigned8<Zero, C1, C2, C3, C4, C5, C6, C7>,
              Unsigned8<One, C1, C2, C3, C4, C5, C6, C7>>
    {
        using result = False;
    };
} // namespace GtImpl
