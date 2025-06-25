#pragma once

#include "control_flow/ternary.hh"
#include "traits/is_same.hh"
#include "types/bits/concept.hh"
#include "types/bits/literals.hh"
#include "types/list/list.hh"
#include "types/list/ops/reverse.hh"
#include "types/numbers/unsigned/concept.hh"
#include "types/numbers/unsigned/unsigned.hh"
#include "types/numbers/unsigned/utils/fromList.hh"

// The technique here is to reverse the bitpack of the number, dropping leading
// Zeros and reversing it back. Without the Reverse would lead to fewer template
// instantiation depth, but is quite harder to do, so I don't know if it would
// even be worth it in the end.

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

template <Unsigned_t Number>
struct Canonicalize;

template <Unsigned_t Number>
using Canonicalize_v = Canonicalize<Number>::result;

template <Unsigned_t Number>
struct Canonicalize;

template <Bit_t... Bits>
struct Canonicalize<Unsigned<Bits...>>
{
    using rev = Reverse_v<List<Bits...>>;
    using stripped = DropLeadingZeros_v<rev>;
    using result_list = Reverse_v<stripped>;
    using result = ToUnsigned_v<result_list>;
};
