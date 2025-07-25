#pragma once

#include "bits/concept.hh"
#include "casts/big_unsigned.hh"
#include "functions/base.hh"
#include "functions/base/is_same.hh"
#include "functions/base/ternary.hh"
#include "functions/function.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "list/ops/reverse.hh"
#include "literals/bits.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"

// The technique here is to reverse the bitpack of the number, dropping leading
// Zeros and reversing it back. Without the Reverse would lead to fewer template
// instantiation depth, but is quite harder to do, so I don't know if it would
// even be worth it in the end.

namespace CanonicalizeImpl
{
    template <List_t List>
    struct DropLeadingZeros;

    template <List_t List>
    using DropLeadingZeros_v = DropLeadingZeros<List>::result;

    template <>
    struct DropLeadingZeros<List<>>
    {
        using result = List<>;
    };

    template <Bit_t Head, Bit_t... Tail>
    struct DropLeadingZeros<List<Head, Tail...>>
    {
    private:
        using TailResult = DropLeadingZeros_v<List<Tail...>>;

    public:
        using result =
            Ternary_v<IsSame_v<Head, Zero>, TailResult, List<Head, Tail...>>;
    };

    template <Any_t Number>
        requires BigUnsigned_t<Number>
    struct Canonicalize<Number>;

    template <Bit_t... Bits>
    struct Canonicalize<BigUnsigned<Bits...>>
    {
        using rev = Reverse_v<List<Bits...>>;
        using stripped = DropLeadingZeros_v<rev>;
        using result_list = Reverse_v<stripped>;
        using result = ToBigUnsigned_v<result_list>;
    };
} // namespace CanonicalizeImpl
