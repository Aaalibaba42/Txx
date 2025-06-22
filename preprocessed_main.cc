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

template <typename List>
struct ToNumber;

template <typename... Bits>
using ToNumber_v = ToNumber<Bits...>::result;

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

template <typename List, typename Carry>
struct AddCarry;

template <typename Carry>
struct AddCarry<TypeList<>, Carry>
{
    using result = If_v<IsSame_v<Carry, One>, TypeList<One>, TypeList<>>;
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
struct Inc;

template <typename... Bits>
struct Inc<Number<Bits...>>
{
    using result =
        ToNumber_v<typename AddCarry<TypeList<Bits...>, One>::result>;
};
template <typename Num>
using Inc_v = Inc<Num>::result;

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using N3 = Number<One, One, Zero>;
    using N4 = Inc_v<N3>;

    static_assert(is_same<N4, Number<Zero, Zero, One>>);
}
