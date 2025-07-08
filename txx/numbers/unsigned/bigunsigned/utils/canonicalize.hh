#pragma once

#include "functions/ternary.hh"
#include "functions/is_same.hh"
#include "bits/concept.hh"
#include "bits/literals.hh"
#include "list/list.hh"
#include "list/concept.hh"
#include "list/ops/reverse.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "numbers/unsigned/bigunsigned/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/utils/fromList.hh"

// The technique here is to reverse the bitpack of the number, dropping leading
// Zeros and reversing it back. Without the Reverse would lead to fewer template
// instantiation depth, but is quite harder to do, so I don't know if it would
// even be worth it in the end.

namespace BigUnsignedCanonicalizeImpl
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

    template <BigUnsigned_t Number>
    struct BigUnsignedCanonicalize;

    template <BigUnsigned_t Number>
    using BigUnsignedCanonicalize_v = BigUnsignedCanonicalize<Number>::result;

    template <BigUnsigned_t Number>
    struct BigUnsignedCanonicalize;

    template <Bit_t... Bits>
    struct BigUnsignedCanonicalize<BigUnsigned<Bits...>>
    {
        using rev = ListReverse_v<List<Bits...>>;
        using stripped = DropLeadingZeros_v<rev>;
        using result_list = ListReverse_v<stripped>;
        using result = ToBigUnsigned_v<result_list>;
    };

    struct BigUnsignedCanonicalizeFunc
    {
        using is_function = IsFunction;

        template <BigUnsigned_t Number>
        struct apply
        {
            using result = BigUnsignedCanonicalize_v<Number>;
        };
    };
} // namespace BigUnsignedCanonicalizeImpl

using BigUnsignedCanonicalizeImpl::BigUnsignedCanonicalize_v;
using BigUnsignedCanonicalizeImpl::BigUnsignedCanonicalizeFunc;
