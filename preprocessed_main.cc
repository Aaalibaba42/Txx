struct Zero
{};

struct One
{};

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

template <typename T>
concept Any_t = true;

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

void bit_t_stub(Zero);
void bit_t_stub(One);

template <typename T>
concept Bit_t = requires(T b) {
    { bit_t_stub(b) };
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

template <Bit_t... BitPack>
struct Unsigned
{
    using Bits = List<BitPack...>;
};

template <Bit_t... bits>
void unsigned_t_stub(Unsigned<bits...>);

template <typename T>
concept Unsigned_t = requires(T us) {
    { unsigned_t_stub(us) };
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

template <List_t LHS, List_t RHS, Bit_t Carry>
struct AddUnsignedCarry;

template <List_t LHS, List_t RHS, Bit_t Carry>
using AddUnsignedCarry_v = AddUnsignedCarry<LHS, RHS, Carry>::result;

template <Bit_t Carry>
struct AddUnsignedCarry<List<>, List<>, Carry>
{
    using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
};

template <Bit_t L0, Bit_t... LRest, Bit_t Carry>
struct AddUnsignedCarry<List<L0, LRest...>, List<>, Carry>
{
    using FA = FullAdder<L0, Carry>;
    using tail = AddUnsignedCarry_v<List<LRest...>, List<>, typename FA::Carry>;
    using result = Prepend_v<typename FA::Sum, tail>;
};

template <Bit_t R0, Bit_t... RRest, Bit_t Carry>
struct AddUnsignedCarry<List<>, List<R0, RRest...>, Carry>
{
    using FA = FullAdder<R0, Carry>;
    using tail = AddUnsignedCarry_v<List<>, List<RRest...>, typename FA::Carry>;
    using result = Prepend_v<typename FA::Sum, tail>;
};

template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Carry>
struct AddUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Carry>
{
    using FA1 = FullAdder<L0, R0>;
    using FA2 = FullAdder<typename FA1::Sum, Carry>;

    using result_carry = FA1::Carry;
    using result_sum = FA2::Sum;
    using next_carry = FullAdder<typename FA1::Carry, typename FA2::Carry>::Sum;

    using tail = AddUnsignedCarry_v<List<LRest...>, List<RRest...>, next_carry>;
    using result = Prepend_v<result_sum, tail>;
};

template <Unsigned_t A, Unsigned_t B>
struct UnsignedAdd;

template <Unsigned_t A, Unsigned_t B>
using UnsignedAdd_v = UnsignedAdd<A, B>::result;

template <Bit_t... A, Bit_t... B>
struct UnsignedAdd<Unsigned<A...>, Unsigned<B...>>
{
    using result =
        ToUnsigned_v<AddUnsignedCarry_v<List<A...>, List<B...>, Zero>>;
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

template <Bit_t LHS, Bit_t RHS, Bit_t Borrow>
struct FullSubtractor;

template <>
struct FullSubtractor<Zero, Zero, Zero>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<Zero, Zero, One>
{
    using Diff = One;
    using Borrow = One;
};

template <>
struct FullSubtractor<Zero, One, Zero>
{
    using Diff = One;
    using Borrow = One;
};

template <>
struct FullSubtractor<Zero, One, One>
{
    using Diff = Zero;
    using Borrow = One;
};

template <>
struct FullSubtractor<One, Zero, Zero>
{
    using Diff = One;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, Zero, One>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, One, Zero>
{
    using Diff = Zero;
    using Borrow = Zero;
};

template <>
struct FullSubtractor<One, One, One>
{
    using Diff = One;
    using Borrow = One;
};

template <List_t In, List_t Acc = List<>>
struct Reverse;

template <List_t In, List_t Acc = List<>>
using Reverse_v = Reverse<In, Acc>::result;

template <List_t Acc>
struct Reverse<List<>, Acc>
{
    using result = Acc;
};

template <typename Head, typename... Tail, List_t Acc>
struct Reverse<List<Head, Tail...>, Acc>
{
    using result = Reverse<List<Tail...>, Prepend_v<Head, Acc>>::result;
};

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

template <List_t A, List_t B, Bit_t Borrow>
struct SubUnsignedCarry;

template <List_t A, List_t B, Bit_t Borrow>
using SubUnsignedCarry_v = SubUnsignedCarry<A, B, Borrow>::result;

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
    using result = Prepend_v<typename FS::Diff, tail>;
};

template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
struct SubUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
{
    using FS = FullSubtractor<Zero, R0, Borrow>;
    using tail =
        SubUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
    using result = Prepend_v<typename FS::Diff, tail>;
};
template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
struct SubUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
{
    using FS = FullSubtractor<L0, R0, Borrow>;
    using tail =
        SubUnsignedCarry_v<List<LRest...>, List<RRest...>, typename FS::Borrow>;
    using result = Prepend_v<typename FS::Diff, tail>;
};

template <Unsigned_t A, Unsigned_t B>
struct UnsignedSub;

template <Unsigned_t A, Unsigned_t B>
using UnsignedSub_v = UnsignedSub<A, B>::result;

template <Bit_t... A, Bit_t... B>
struct UnsignedSub<Unsigned<A...>, Unsigned<B...>>
{
    using result = Canonicalize_v<
        ToUnsigned_v<SubUnsignedCarry_v<List<A...>, List<B...>, Zero>>>;
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
    using n17 = Unsigned<One, Zero, Zero, Zero, One>;
    using n18 = Unsigned<Zero, One, Zero, Zero, One>;
    using n19 = Unsigned<One, One, Zero, Zero, One>;
    using n20 = Unsigned<Zero, Zero, One, Zero, One>;
    using n21 = Unsigned<One, Zero, One, Zero, One>;
    using n22 = Unsigned<Zero, One, One, Zero, One>;
    using n23 = Unsigned<One, One, One, Zero, One>;
    using n24 = Unsigned<Zero, Zero, Zero, One, One>;
    using n25 = Unsigned<One, Zero, Zero, One, One>;
    using n26 = Unsigned<Zero, One, Zero, One, One>;
    using n27 = Unsigned<One, One, Zero, One, One>;
    using n28 = Unsigned<Zero, Zero, One, One, One>;
    using n29 = Unsigned<One, Zero, One, One, One>;
    using n30 = Unsigned<Zero, One, One, One, One>;
    using n31 = Unsigned<One, One, One, One, One>;
    using n32 = Unsigned<Zero, Zero, Zero, Zero, Zero, One>;
    using n33 = Unsigned<One, Zero, Zero, Zero, Zero, One>;
    using n34 = Unsigned<Zero, One, Zero, Zero, Zero, One>;
    using n35 = Unsigned<One, One, Zero, Zero, Zero, One>;
    using n36 = Unsigned<Zero, Zero, One, Zero, Zero, One>;
    using n37 = Unsigned<One, Zero, One, Zero, Zero, One>;
    using n38 = Unsigned<Zero, One, One, Zero, Zero, One>;
    using n39 = Unsigned<One, One, One, Zero, Zero, One>;
    using n40 = Unsigned<Zero, Zero, Zero, One, Zero, One>;
    using n41 = Unsigned<One, Zero, Zero, One, Zero, One>;
    using n42 = Unsigned<Zero, One, Zero, One, Zero, One>;
    using n43 = Unsigned<One, One, Zero, One, Zero, One>;
    using n44 = Unsigned<Zero, Zero, One, One, Zero, One>;
    using n45 = Unsigned<One, Zero, One, One, Zero, One>;
    using n46 = Unsigned<Zero, One, One, One, Zero, One>;
    using n47 = Unsigned<One, One, One, One, Zero, One>;
    using n48 = Unsigned<Zero, Zero, Zero, Zero, One, One>;
    using n49 = Unsigned<One, Zero, Zero, Zero, One, One>;
    using n50 = Unsigned<Zero, One, Zero, Zero, One, One>;
    using n51 = Unsigned<One, One, Zero, Zero, One, One>;
    using n52 = Unsigned<Zero, Zero, One, Zero, One, One>;
    using n53 = Unsigned<One, Zero, One, Zero, One, One>;
    using n54 = Unsigned<Zero, One, One, Zero, One, One>;
    using n55 = Unsigned<One, One, One, Zero, One, One>;
    using n56 = Unsigned<Zero, Zero, Zero, One, One, One>;
    using n57 = Unsigned<One, Zero, Zero, One, One, One>;
    using n58 = Unsigned<Zero, One, Zero, One, One, One>;
    using n59 = Unsigned<One, One, Zero, One, One, One>;
    using n60 = Unsigned<Zero, Zero, One, One, One, One>;
    using n61 = Unsigned<One, Zero, One, One, One, One>;
    using n62 = Unsigned<Zero, One, One, One, One, One>;
    using n63 = Unsigned<One, One, One, One, One, One>;
    using n64 = Unsigned<Zero, Zero, Zero, Zero, Zero, Zero, One>;

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
    using N17 = UnsignedInc_v<N16>;
    using N18 = UnsignedInc_v<N17>;
    using N19 = UnsignedInc_v<N18>;
    using N20 = UnsignedInc_v<N19>;
    using N21 = UnsignedInc_v<N20>;
    using N22 = UnsignedInc_v<N21>;
    using N23 = UnsignedInc_v<N22>;
    using N24 = UnsignedInc_v<N23>;
    using N25 = UnsignedInc_v<N24>;
    using N26 = UnsignedInc_v<N25>;
    using N27 = UnsignedInc_v<N26>;
    using N28 = UnsignedInc_v<N27>;
    using N29 = UnsignedInc_v<N28>;
    using N30 = UnsignedInc_v<N29>;
    using N31 = UnsignedInc_v<N30>;
    using N32 = UnsignedInc_v<N31>;
    using N33 = UnsignedInc_v<N32>;
    using N34 = UnsignedInc_v<N33>;
    using N35 = UnsignedInc_v<N34>;
    using N36 = UnsignedInc_v<N35>;
    using N37 = UnsignedInc_v<N36>;
    using N38 = UnsignedInc_v<N37>;
    using N39 = UnsignedInc_v<N38>;
    using N40 = UnsignedInc_v<N39>;
    using N41 = UnsignedInc_v<N40>;
    using N42 = UnsignedInc_v<N41>;
    using N43 = UnsignedInc_v<N42>;
    using N44 = UnsignedInc_v<N43>;
    using N45 = UnsignedInc_v<N44>;
    using N46 = UnsignedInc_v<N45>;
    using N47 = UnsignedInc_v<N46>;
    using N48 = UnsignedInc_v<N47>;
    using N49 = UnsignedInc_v<N48>;
    using N50 = UnsignedInc_v<N49>;
    using N51 = UnsignedInc_v<N50>;
    using N52 = UnsignedInc_v<N51>;
    using N53 = UnsignedInc_v<N52>;
    using N54 = UnsignedInc_v<N53>;
    using N55 = UnsignedInc_v<N54>;
    using N56 = UnsignedInc_v<N55>;
    using N57 = UnsignedInc_v<N56>;
    using N58 = UnsignedInc_v<N57>;
    using N59 = UnsignedInc_v<N58>;
    using N60 = UnsignedInc_v<N59>;
    using N61 = UnsignedInc_v<N60>;
    using N62 = UnsignedInc_v<N61>;
    using N63 = UnsignedInc_v<N62>;
    using N64 = UnsignedInc_v<N63>;

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
    static_assert(is_same<n17, N17>);
    static_assert(is_same<n18, N18>);
    static_assert(is_same<n19, N19>);
    static_assert(is_same<n20, N20>);
    static_assert(is_same<n21, N21>);
    static_assert(is_same<n22, N22>);
    static_assert(is_same<n23, N23>);
    static_assert(is_same<n24, N24>);
    static_assert(is_same<n25, N25>);
    static_assert(is_same<n26, N26>);
    static_assert(is_same<n27, N27>);
    static_assert(is_same<n28, N28>);
    static_assert(is_same<n29, N29>);
    static_assert(is_same<n30, N30>);
    static_assert(is_same<n31, N31>);
    static_assert(is_same<n32, N32>);
    static_assert(is_same<n33, N33>);
    static_assert(is_same<n34, N34>);
    static_assert(is_same<n35, N35>);
    static_assert(is_same<n36, N36>);
    static_assert(is_same<n37, N37>);
    static_assert(is_same<n38, N38>);
    static_assert(is_same<n39, N39>);
    static_assert(is_same<n40, N40>);
    static_assert(is_same<n41, N41>);
    static_assert(is_same<n42, N42>);
    static_assert(is_same<n43, N43>);
    static_assert(is_same<n44, N44>);
    static_assert(is_same<n45, N45>);
    static_assert(is_same<n46, N46>);
    static_assert(is_same<n47, N47>);
    static_assert(is_same<n48, N48>);
    static_assert(is_same<n49, N49>);
    static_assert(is_same<n50, N50>);
    static_assert(is_same<n51, N51>);
    static_assert(is_same<n52, N52>);
    static_assert(is_same<n53, N53>);
    static_assert(is_same<n54, N54>);
    static_assert(is_same<n55, N55>);
    static_assert(is_same<n56, N56>);
    static_assert(is_same<n57, N57>);
    static_assert(is_same<n58, N58>);
    static_assert(is_same<n59, N59>);
    static_assert(is_same<n60, N60>);
    static_assert(is_same<n61, N61>);
    static_assert(is_same<n62, N62>);
    static_assert(is_same<n63, N63>);
    static_assert(is_same<n64, N64>);

    using A5 = UnsignedAdd_v<n3, n2>;
    using A16 = UnsignedAdd_v<n8, n8>;
    using A8 = UnsignedAdd_v<n7, n1>;
    using A1 = UnsignedAdd_v<n0, n1>;
    using A0 = UnsignedAdd_v<n0, n0>;
    using A15_1 = UnsignedAdd_v<n15, n0>;
    using A15_2 = UnsignedAdd_v<n0, n15>;
    using A16_1 = UnsignedAdd_v<n15, n1>;
    using A16_2 = UnsignedAdd_v<n1, n15>;
    using A6 = UnsignedAdd_v<n2, n4>;
    using A9 = UnsignedAdd_v<n5, n4>;
    using A11 = UnsignedAdd_v<n3, n8>;
    using A14 = UnsignedAdd_v<n6, n8>;
    using A15 = UnsignedAdd_v<n7, n8>;
    using A10 = UnsignedAdd_v<n4, n6>;
    using A13 = UnsignedAdd_v<n5, n8>;
    using A17 = UnsignedAdd_v<n9, n8>;
    using A19 = UnsignedAdd_v<n11, n8>;
    using A22 = UnsignedAdd_v<n14, n8>;
    using A25 = UnsignedAdd_v<n16, n9>;
    using A28 = UnsignedAdd_v<n19, n9>;
    using A30 = UnsignedAdd_v<n20, n10>;
    using A33 = UnsignedAdd_v<n22, n11>;
    using A35 = UnsignedAdd_v<n24, n11>;
    using A38 = UnsignedAdd_v<n27, n11>;
    using A40 = UnsignedAdd_v<n30, n10>;
    using A42 = UnsignedAdd_v<n33, n9>;
    using A45 = UnsignedAdd_v<n36, n9>;
    using A48 = UnsignedAdd_v<n39, n9>;
    using A50 = UnsignedAdd_v<n41, n9>;

    static_assert(is_same<A6, n6>);
    static_assert(is_same<A9, n9>);
    static_assert(is_same<A11, n11>);
    static_assert(is_same<A14, n14>);
    static_assert(is_same<A15, n15>);
    static_assert(is_same<A10, n10>);
    static_assert(is_same<A13, n13>);
    static_assert(is_same<A17, n17>);
    static_assert(is_same<A19, n19>);
    static_assert(is_same<A22, n22>);
    static_assert(is_same<A25, n25>);
    static_assert(is_same<A28, n28>);
    static_assert(is_same<A30, n30>);
    static_assert(is_same<A33, n33>);
    static_assert(is_same<A35, n35>);
    static_assert(is_same<A38, n38>);
    static_assert(is_same<A40, n40>);
    static_assert(is_same<A42, n42>);
    static_assert(is_same<A45, n45>);
    static_assert(is_same<A48, n48>);
    static_assert(is_same<A50, n50>);
    static_assert(is_same<A5, n5>);
    static_assert(is_same<A16, n16>);
    static_assert(is_same<A8, n8>);
    static_assert(is_same<A1, n1>);
    static_assert(is_same<A0, n0>);
    static_assert(is_same<A15_1, n15>);
    static_assert(is_same<A15_2, n15>);
    static_assert(is_same<A16_1, n16>);
    static_assert(is_same<A16_2, n16>);

    using S1 = UnsignedSub_v<n3, n2>;
    using S0 = UnsignedSub_v<n8, n8>;
    using S6 = UnsignedSub_v<n7, n1>;
    using S7 = UnsignedSub_v<n8, n1>;
    using S15 = UnsignedSub_v<n15, n0>;
    using S14 = UnsignedSub_v<n15, n1>;
    using S5 = UnsignedSub_v<n6, n1>;
    using S8 = UnsignedSub_v<n10, n2>;
    using S9 = UnsignedSub_v<n11, n2>;
    using S10 = UnsignedSub_v<n12, n2>;
    using S11 = UnsignedSub_v<n13, n2>;
    using S12 = UnsignedSub_v<n14, n2>;
    using S13 = UnsignedSub_v<n15, n2>;
    using S14_1 = UnsignedSub_v<n16, n2>;
    using S15_1 = UnsignedSub_v<n17, n2>;
    using S16 = UnsignedSub_v<n18, n2>;
    using S17 = UnsignedSub_v<n19, n2>;
    using S18 = UnsignedSub_v<n20, n2>;
    using S19 = UnsignedSub_v<n21, n2>;
    using S20 = UnsignedSub_v<n22, n2>;
    using S21 = UnsignedSub_v<n23, n2>;
    using S22 = UnsignedSub_v<n24, n2>;
    using S23 = UnsignedSub_v<n25, n2>;
    using S24 = UnsignedSub_v<n26, n2>;
    using S25 = UnsignedSub_v<n27, n2>;
    using S26 = UnsignedSub_v<n28, n2>;
    using S27 = UnsignedSub_v<n29, n2>;
    using S28 = UnsignedSub_v<n30, n2>;
    using S29 = UnsignedSub_v<n31, n2>;
    using S30 = UnsignedSub_v<n32, n2>;
    using S31 = UnsignedSub_v<n33, n2>;
    using S32 = UnsignedSub_v<n34, n2>;
    using S33 = UnsignedSub_v<n35, n2>;
    using S34 = UnsignedSub_v<n36, n2>;
    using S35 = UnsignedSub_v<n37, n2>;
    using S36 = UnsignedSub_v<n38, n2>;
    using S37 = UnsignedSub_v<n39, n2>;
    using S38 = UnsignedSub_v<n40, n2>;
    using S39 = UnsignedSub_v<n41, n2>;
    using S40 = UnsignedSub_v<n42, n2>;

    static_assert(is_same<S1, n1>);
    static_assert(is_same<S0, n0>);
    static_assert(is_same<S6, n6>);
    static_assert(is_same<S7, n7>);
    static_assert(is_same<S15, n15>);
    static_assert(is_same<S14, n14>);
    static_assert(is_same<S5, n5>);
    static_assert(is_same<S8, n8>);
    static_assert(is_same<S9, n9>);
    static_assert(is_same<S10, n10>);
    static_assert(is_same<S11, n11>);
    static_assert(is_same<S12, n12>);
    static_assert(is_same<S13, n13>);
    static_assert(is_same<S14_1, n14>);
    static_assert(is_same<S15_1, n15>);
    static_assert(is_same<S16, n16>);
    static_assert(is_same<S17, n17>);
    static_assert(is_same<S18, n18>);
    static_assert(is_same<S19, n19>);
    static_assert(is_same<S20, n20>);
    static_assert(is_same<S21, n21>);
    static_assert(is_same<S22, n22>);
    static_assert(is_same<S23, n23>);
    static_assert(is_same<S24, n24>);
    static_assert(is_same<S25, n25>);
    static_assert(is_same<S26, n26>);
    static_assert(is_same<S27, n27>);
    static_assert(is_same<S28, n28>);
    static_assert(is_same<S29, n29>);
    static_assert(is_same<S30, n30>);
    static_assert(is_same<S31, n31>);
    static_assert(is_same<S32, n32>);
    static_assert(is_same<S33, n33>);
    static_assert(is_same<S34, n34>);
    static_assert(is_same<S35, n35>);
    static_assert(is_same<S36, n36>);
    static_assert(is_same<S37, n37>);
    static_assert(is_same<S38, n38>);
    static_assert(is_same<S39, n39>);
    static_assert(is_same<S40, n40>);
}
