struct Zero
{};

struct One
{};

void bit_t_stub(Zero);
void bit_t_stub(One);

template <typename T>
concept Bit_t = requires(T b) {
    { bit_t_stub(b) };
};

template <typename T>
concept Any_t = true;

struct None
{};

template <Any_t... Elems>
struct List;

template <Any_t Curr, Any_t... Rest>
struct List<Curr, Rest...>
{
    using curr = Curr;
    using rest = List<Rest...>;
};

template <Any_t Curr>
struct List<Curr>
{
    using curr = Curr;
    using rest = None;
};

template <>
struct List<>
{
    using curr = None;
    using rest = None;
};

template <Bit_t... BitPack>
struct Unsigned
{
    using Bits = List<BitPack...>;
};

struct True
{};

struct False
{};

void bool_t_stub(True);
void bool_t_stub(False);

template <typename T>
concept Bool_t = requires(T b) {
    { bool_t_stub(b) };
};

template <Bool_t Cond, Any_t Success, Any_t Failure>
struct Ternary;

template <Bool_t Cond, Any_t Success, Any_t Failure>
using Ternary_v = Ternary<Cond, Success, Failure>::result;

template <Any_t Success, Any_t Failure>
struct Ternary<True, Success, Failure>
{
    using result = Success;
};

template <Any_t Success, Any_t Failure>
struct Ternary<False, Success, Failure>
{
    using result = Failure;
};

template <Any_t T1, Any_t T2>
struct IsSame;

template <Any_t T1, Any_t T2>
using IsSame_v = IsSame<T1, T2>::result;

template <Any_t T>
struct IsSame<T, T>
{
    using result = True;
};

template <Any_t T1, Any_t T2>
struct IsSame
{
    using result = False;
};

template <Bit_t Bit, Bit_t Carry>
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

template <typename... Elems>
void list_t_stub(List<Elems...>);

template <typename T>
concept List_t = requires(T list) {
    { list_t_stub(list) };
};

template <Any_t Elem, List_t List>
struct Prepend;

template <Any_t Elem, List_t List>
using Prepend_v = Prepend<Elem, List>::result;

template <Any_t Elem, Any_t... Rest>
struct Prepend<Elem, List<Rest...>>
{
    using result = List<Elem, Rest...>;
};

template <List_t List>
struct ToUnsigned;

template <List_t List>
using ToUnsigned_v = ToUnsigned<List>::result;

template <Bit_t... Bits>
struct ToUnsigned<List<Bits...>>
{
    using result = Unsigned<Bits...>;
};

template <Bit_t... bits>
void unsigned_t_stub(Unsigned<bits...>);

template <typename T>
concept Unsigned_t = requires(T us) {
    { unsigned_t_stub(us) };
};

template <List_t List, Bit_t Carry>
struct AddCarry;

template <List_t List, Bit_t Carry>
using AddCarry_v = AddCarry<List, Carry>::result;

template <Bit_t Carry>
struct AddCarry<List<>, Carry>
{
    using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
};

template <Bit_t Curr, Bit_t... Rest, Bit_t Carry>
struct AddCarry<List<Curr, Rest...>, Carry>
{
    using FA = FullAdder<Curr, Carry>;

    using tail = AddCarry_v<List<Rest...>, typename FA::Carry>;

    using result = Prepend_v<typename FA::Sum, tail>;
};

template <Unsigned_t Num>
struct UnsignedInc;

template <Unsigned_t Num>
using UnsignedInc_v = UnsignedInc<Num>::result;

template <Bit_t... Bits>
struct UnsignedInc<Unsigned<Bits...>>
{
    using result = ToUnsigned_v<AddCarry_v<List<Bits...>, One>>;
};

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using n0 = Unsigned<>;
    using n1 = Unsigned<One>;
    using n2 = Unsigned<Zero, One>;
    using n3 = Unsigned<One, One>;
    using n4 = Unsigned<Zero, Zero, One>;
    using n5 = Unsigned<One, Zero, One>;
    using n6 = Unsigned<Zero, One, One>;
    using n7 = Unsigned<One, One, One>;
    using n8 = Unsigned<Zero, Zero, Zero, One>;
    using n9 = Unsigned<One, Zero, Zero, One>;
    using n10 = Unsigned<Zero, One, Zero, One>;
    using n11 = Unsigned<One, One, Zero, One>;
    using n12 = Unsigned<Zero, Zero, One, One>;
    using n13 = Unsigned<One, Zero, One, One>;
    using n14 = Unsigned<Zero, One, One, One>;
    using n15 = Unsigned<One, One, One, One>;
    using n16 = Unsigned<Zero, Zero, Zero, Zero, One>;

    using N0 = Unsigned<>;
    using N1 = UnsignedInc_v<N0>;
    using N2 = UnsignedInc_v<N1>;
    using N3 = UnsignedInc_v<N2>;
    using N4 = UnsignedInc_v<N3>;
    using N5 = UnsignedInc_v<N4>;
    using N6 = UnsignedInc_v<N5>;
    using N7 = UnsignedInc_v<N6>;
    using N8 = UnsignedInc_v<N7>;
    using N9 = UnsignedInc_v<N8>;
    using N10 = UnsignedInc_v<N9>;
    using N11 = UnsignedInc_v<N10>;
    using N12 = UnsignedInc_v<N11>;
    using N13 = UnsignedInc_v<N12>;
    using N14 = UnsignedInc_v<N13>;
    using N15 = UnsignedInc_v<N14>;
    using N16 = UnsignedInc_v<N15>;

    static_assert(is_same<n0, N0>);
    static_assert(is_same<n1, N1>);
    static_assert(is_same<n2, N2>);
    static_assert(is_same<n3, N3>);
    static_assert(is_same<n4, N4>);
    static_assert(is_same<n5, N5>);
    static_assert(is_same<n6, N6>);
    static_assert(is_same<n7, N7>);
    static_assert(is_same<n8, N8>);
    static_assert(is_same<n9, N9>);
    static_assert(is_same<n10, N10>);
    static_assert(is_same<n11, N11>);
    static_assert(is_same<n12, N12>);
    static_assert(is_same<n13, N13>);
    static_assert(is_same<n14, N14>);
    static_assert(is_same<n15, N15>);
    static_assert(is_same<n16, N16>);
}
