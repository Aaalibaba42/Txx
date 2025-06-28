#pragma once

#include "control_flow/ternary.hh"
#include "traits/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/bits/ops/fullsubtractor.hh"
#include "types/list/concept.hh"
#include "types/list/list.hh"
#include "types/list/ops/prepend.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/numbers/unsigned/utils/canonicalize.hh"
#include "types/numbers/unsigned/utils/fromList.hh"

namespace UnsignedSubImpl
{
    template <List_t LHS, List_t RHS, Bit_t Borrow>
    struct SubUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Borrow>
    using SubUnsignedCarry_v = SubUnsignedCarry<LHS, RHS, Borrow>::result;

    template <Bit_t Borrow>
    struct SubUnsignedCarry<List<>, List<>, Borrow>
    {
        using result = Ternary_v<IsSame_v<Borrow, One>, List<>, List<>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t Borrow>
    struct SubUnsignedCarry<List<L0, LRest...>, List<>, Borrow>
    {
        using FS = FullSubtractor<L0, Zero, Borrow>;
        using tail =
            SubUnsignedCarry_v<List<LRest...>, List<>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<Zero, R0, Borrow>;
        using tail =
            SubUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<L0, R0, Borrow>;
        using tail = SubUnsignedCarry_v<List<LRest...>, List<RRest...>,
                                        typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedSub;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedSub_v = UnsignedSub<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedSub<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using result = Canonicalize_v<
            ToUnsigned_v<SubUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>>;
    };
} // namespace UnsignedSubImpl

using UnsignedSubImpl::UnsignedSub_v;
