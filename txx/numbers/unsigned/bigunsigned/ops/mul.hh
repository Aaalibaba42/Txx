#pragma once

#include "bits/concept.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"
#include "numbers/unsigned/bigunsigned/ops/left_shift.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace MulImpl
{
    template <BigUnsigned_t LHS, Bit_t RHS, BigUnsigned_t Shift>
    struct MulByBit;

    template <BigUnsigned_t LHS, Bit_t RHS, BigUnsigned_t Shift>
    using MulByBit_v = MulByBit<LHS, RHS, Shift>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulByBit<LHS, Zero, Shift>
    {
        using result = BigUnsigned<>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulByBit<LHS, One, Shift>
    {
        using result = LShift_v<LHS, Shift>;
    };

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    struct MulHelper;

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    using MulHelper_v = MulHelper<LHS, BList, Shift>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulHelper<LHS, List<>, Shift>
    {
        using result = BigUnsigned<>;
    };

    template <Bit_t R0, Bit_t... RRest, BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulHelper<LHS, List<R0, RRest...>, Shift>
    {
        using partial = MulByBit_v<LHS, R0, Shift>;
        using rest = MulHelper_v<LHS, List<RRest...>, Inc_v<Shift>>;
        using result = Add_v<partial, rest>;
    };

    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Mul<LHS, RHS>;

    template <Bit_t... LHS, Bit_t... RHS>
    struct Mul<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = Canonicalize_v<
            MulHelper_v<BigUnsigned<LHS...>, List<RHS...>, BigUnsigned<>>>;
    };
} // namespace MulImpl
