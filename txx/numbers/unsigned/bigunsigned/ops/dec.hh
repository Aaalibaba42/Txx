#pragma once

#include "bits/concept.hh"
#include "bits/ops/fullsubtractor.hh"
#include "casts/big_unsigned.hh"
#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "functions/base/ternary.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/prepend.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/utils/canonicalize.hh"

namespace DecImpl
{
    template <List_t List, Bit_t Borrow>
    struct SubBorrow;

    template <List_t List, Bit_t Borrow>
    using SubBorrow_v = SubBorrow<List, Borrow>::result;

    template <Bit_t Borrow>
    struct SubBorrow<List<>, Borrow>
    {
        // Saturating Underflow (technically I'd rather say it's UB)
        using result = List<>;
    };

    template <Bit_t Curr, Bit_t... Rest, Bit_t Borrow>
    struct SubBorrow<List<Curr, Rest...>, Borrow>
    {
        using FS = FullSubtractor<Curr, Zero, Borrow>;

        using tail = SubBorrow_v<List<Rest...>, typename FS::Borrow>;

        using result = Prepend_v<typename FS::Diff, tail>;
    };

    template <Any_t Num>
        requires BigUnsigned_t<Num>
    struct Dec<Num>;

    template <Bit_t... Bits>
    struct Dec<BigUnsigned<Bits...>>
    {
        using result = Canonicalize_v<ToBigUnsigned_v<SubBorrow_v<List<Bits...>, One>>>;
    };

    template <>
    struct Dec<BigUnsigned<>>
    {
        using result = BigUnsigned<>;
    };
} // namespace DecImpl

