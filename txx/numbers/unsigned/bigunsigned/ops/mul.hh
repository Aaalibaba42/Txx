#pragma once

#include "bits/concept.hh"
#include "bits/literals.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"
#include "numbers/unsigned/bigunsigned/ops/left_shift.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace BigUnsignedMulImpl
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
        using result = BigUnsignedLShift_v<LHS, Shift>;
    };

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper;

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    using BigUnsignedMulHelper_v =
        BigUnsignedMulHelper<LHS, BList, Shift>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper<LHS, List<>, Shift>
    {
        using result = BigUnsigned<>;
    };

    template <Bit_t R0, Bit_t... RRest, BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper<LHS, List<R0, RRest...>, Shift>
    {
        using partial = MulByBit_v<LHS, R0, Shift>;
        using rest = BigUnsignedMulHelper_v<LHS, List<RRest...>,
                                            BigUnsignedInc_v<Shift>>;
        using result = BigUnsignedAdd_v<partial, rest>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedMul;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedMul_v = BigUnsignedMul<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedMul<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = BigUnsignedCanonicalize_v<BigUnsignedMulHelper_v<
            BigUnsigned<LHS...>, List<RHS...>, BigUnsigned<>>>;
    };

    struct BigUnsignedMulFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t LHS, BigUnsigned_t RHS>
        struct apply
        {
            using result = BigUnsignedMul_v<LHS, RHS>;
        };
    };
} // namespace BigUnsignedMulImpl

using BigUnsignedMulImpl::BigUnsignedMul_v;
using BigUnsignedMulImpl::BigUnsignedMulFunc;
