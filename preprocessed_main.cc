struct Zero
{};

struct One
{};

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

template <typename... BitPack>
struct Unsigned
{
    using Bits = TypeList<BitPack...>;
};

struct True
{};

struct False
{};

template <typename Cond, typename Success, typename Failure>
struct Ternary;

template <typename Cond, typename Success, typename Failure>
using Ternary_v = Ternary<Cond, Success, Failure>::result;

template <typename Cond, typename Success, typename Failure>
struct Ternary
{
    static_assert(
        false,
        "struct Ternary's Cond is neither struct True, nor struct False");
};

template <typename Success, typename Failure>
struct Ternary<True, Success, Failure>
{
    using result = Success;
};

template <typename Success, typename Failure>
struct Ternary<False, Success, Failure>
{
    using result = Failure;
};

template <typename T1, typename T2>
struct IsSame;

template <typename T1, typename T2>
using IsSame_v = IsSame<T1, T2>::result;

template <typename T>
struct IsSame<T, T>
{
    using result = True;
};

template <typename T1, typename T2>
struct IsSame
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

template <typename Bit, typename List>
struct Prepend;

template <typename Bit, typename List>
using Prepend_v = Prepend<Bit, List>::result;

template <typename Bit, typename... Bits>
struct Prepend<Bit, TypeList<Bits...>>
{
    using result = TypeList<Bit, Bits...>;
};

template <typename List>
struct ToUnsigned;

template <typename... Bits>
using ToUnsigned_v = ToUnsigned<Bits...>::result;

template <typename... Bits>
struct ToUnsigned<TypeList<Bits...>>
{
    using result = Unsigned<Bits...>;
};

template <typename List, typename Carry>
struct AddCarry;

template <typename Carry>
struct AddCarry<TypeList<>, Carry>
{
    using result = Ternary_v<IsSame_v<Carry, One>, TypeList<One>, TypeList<>>;
};

template <typename Curr, typename... Rest, typename Carry>
struct AddCarry<TypeList<Curr, Rest...>, Carry>
{
    using FA = FullAdder<Curr, Carry>;

    using tail =
        typename AddCarry<TypeList<Rest...>, typename FA::Carry>::result;

    using result = Prepend_v<typename FA::Sum, tail>;
};

template <typename Num>
struct UnsignedInc;

template <typename... Bits>
struct UnsignedInc<Unsigned<Bits...>>
{
    using result =
        ToUnsigned_v<typename AddCarry<TypeList<Bits...>, One>::result>;
};
template <typename Num>
using UnsignedInc_v = UnsignedInc<Num>::result;

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using N3 = Unsigned<One, One>;
    using N4 = UnsignedInc_v<N3>;

    static_assert(is_same<N4, Unsigned<Zero, Zero, One>>);

    using N0 = Unsigned<>;
    using N1 = UnsignedInc_v<N0>;

    static_assert(is_same<N1, Unsigned<One>>);
}
