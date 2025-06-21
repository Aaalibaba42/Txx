struct None
{};

template <typename... Types>
struct TypeList;

template <typename Curr, typename... Rest>
struct TypeList<Curr, Rest...>
{
    using curr = Curr;
    using rest = TypeList<Rest...>;
};

template <>
struct TypeList<>
{
    using curr = None;
    using rest = None;
};

struct Zero
{};
struct One
{};

template <typename... BitPack>
struct Number
{
    using Bits = TypeList<BitPack...>;
};

struct True
{};

struct False
{};

template <typename Cond, typename Success, typename Failure = None>
struct If;

template <typename Cond, typename Success, typename Failure = None>
using If_v = If<Cond, Success, Failure>::result;

template <typename Cond, typename Success, typename Failure>
struct If
{
    static_assert(false, "If could not instantiate correctly");
};

template <typename Success, typename Failure>
struct If<True, Success, Failure>
{
    using result = Success;
};

template <typename Success, typename Failure>
struct If<False, Success, Failure>
{
    using result = Failure;
};

template <typename T1, typename T2>
struct is_same;

template <typename T1, typename T2>
using is_same_v = is_same<T1, T2>::result;

template <typename T>
struct is_same<T, T>
{
    using result = True;
};

template <typename T1, typename T2>
struct is_same
{
    using result = False;
};

template <typename Bit, typename Carry>
struct FullAdder;

template <>
struct FullAdder<Zero, Zero>
{
    using Sum = Zero;
    using Carry = Zero;
};

template <>
struct FullAdder<Zero, One>
{
    using Sum = One;
    using Carry = Zero;
};

template <>
struct FullAdder<One, Zero>
{
    using Sum = One;
    using Carry = Zero;
};

template <>
struct FullAdder<One, One>
{
    using Sum = Zero;
    using Carry = One;
};

template <typename List>
struct ToNumber;

template <typename... Bits>
using ToNumber_v = ToNumber<TypeList<Bits...>>::result;

template <typename... Bits>
struct ToNumber<TypeList<Bits...>>
{
    using result = Number<Bits...>;
};

template <typename Bit, typename List>
struct Prepend;

template <typename Bit, typename List>
using Prepend_v = Prepend<Bit, List>::result;

template <typename Bit, typename... Bits>
struct Prepend<Bit, TypeList<Bits...>>
{
    using result = TypeList<Bit, Bits...>;
};

template <typename Number, typename Carry = One>
struct IncImpl;

template <typename Carry>
struct IncImpl<Number<>, Carry>
{
    using result = If_v<is_same_v<Carry, One>, Number<One>, Number<>>;
};

template <typename Bit, typename... Rest, typename Carry>
struct IncImpl<Number<Bit, Rest...>, Carry>
{
    using FA = FullAdder<Bit, Carry>;
    using Tail = IncImpl<Number<Rest...>, typename FA::Carry>::result;
    using Bits = Prepend_v<typename FA::Sum, typename Tail::Bits>;
    using result = ToNumber_v<Bits>;
};

template <typename... Bits>
struct Inc
{
    using result = IncImpl<Number<Bits...>>::result;
};

template <typename Number, typename Carry = One>
using Inc_v = Inc<Number, Carry>::result;

int main(void)
{
    using N3 = Number<One, One, Zero>;
    using N4 = Inc_v<N3>;

    static_assert(is_same_v<N4, Number<Zero, Zero, One>>);
}
