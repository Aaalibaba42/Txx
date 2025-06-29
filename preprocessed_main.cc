

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

namespace TernaryImpl
{
    template <Bool_t Cond, Any_t Success, Any_t Failure>
    struct Ternary;

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
} // namespace TernaryImpl

template <Bool_t Cond, Any_t Success, Any_t Failure>
using Ternary_v = TernaryImpl::Ternary<Cond, Success, Failure>::result;

namespace IsSameImpl
{
    template <Any_t T1, Any_t T2>
    struct IsSame;

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
} // namespace IsSameImpl

template <Any_t T1, Any_t T2>
using IsSame_v = IsSameImpl::IsSame<T1, T2>::result;

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

namespace FullAdderImpl
{
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
} // namespace FullAdderImpl

using FullAdderImpl::FullAdder;

template <Any_t... Elems>
struct List
{};

template <Any_t... Elems>
void list_t_stub(List<Elems...>);

template <typename T>
concept List_t = requires(T list) {
    { list_t_stub(list) };
};

namespace ListPrependImpl
{
    template <Any_t Elem, List_t List>
    struct ListPrepend;

    template <Any_t Elem, List_t List>
    using ListPrepend_v = ListPrepend<Elem, List>::result;

    template <Any_t Elem, Any_t... Rest>
    struct ListPrepend<Elem, List<Rest...>>
    {
        using result = List<Elem, Rest...>;
    };
} // namespace ListPrependImpl

using ListPrependImpl::ListPrepend_v;

template <Bit_t... BitPack>
struct BigUnsigned
{};

template <Bit_t... bits>
void bigunsigned_t_stub(BigUnsigned<bits...>);

template <typename T>
concept BigUnsigned_t = requires(T us) {
    { bigunsigned_t_stub(us) };
};

namespace ToBigUnsignedImpl
{
    template <List_t List>
    struct ToBigUnsigned;

    template <List_t List>
    using ToBigUnsigned_v = ToBigUnsigned<List>::result;

    template <Bit_t... Bits>
    struct ToBigUnsigned<List<Bits...>>
    {
        using result = BigUnsigned<Bits...>;
    };
} // namespace ToBigUnsignedImpl

using ToBigUnsignedImpl::ToBigUnsigned_v;

namespace BigUnsignedAddImpl
{
    template <List_t LHS, List_t RHS, Bit_t Carry>
    struct AddBigUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Carry>
    using AddBigUnsignedCarry_v = AddBigUnsignedCarry<LHS, RHS, Carry>::result;

    template <Bit_t Carry>
    struct AddBigUnsignedCarry<List<>, List<>, Carry>
    {
        using result = Ternary_v<IsSame_v<Carry, One>, List<One>, List<>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<L0, LRest...>, List<>, Carry>
    {
        using FA = FullAdder<L0, Carry>;
        using tail =
            AddBigUnsignedCarry_v<List<LRest...>, List<>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<>, List<R0, RRest...>, Carry>
    {
        using FA = FullAdder<R0, Carry>;
        using tail =
            AddBigUnsignedCarry_v<List<>, List<RRest...>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddBigUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Carry>
    {
        using FA1 = FullAdder<L0, R0>;
        using FA2 = FullAdder<typename FA1::Sum, Carry>;

        using result_carry = FA1::Carry;
        using result_sum = FA2::Sum;
        using next_carry =
            FullAdder<typename FA1::Carry, typename FA2::Carry>::Sum;

        using tail =
            AddBigUnsignedCarry_v<List<LRest...>, List<RRest...>, next_carry>;
        using result = ListPrepend_v<result_sum, tail>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedAdd;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedAdd_v = BigUnsignedAdd<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedAdd<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = ToBigUnsigned_v<
            AddBigUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>;
    };
} // namespace BigUnsignedAddImpl

using BigUnsignedAddImpl::BigUnsignedAdd_v;

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

using n0 = BigUnsigned<>;
using n1 = BigUnsigned<One>;
using n2 = BigUnsigned<Zero, One>;
using n3 = BigUnsigned<One, One>;
using n4 = BigUnsigned<Zero, Zero, One>;
using n5 = BigUnsigned<One, Zero, One>;
using n6 = BigUnsigned<Zero, One, One>;
using n7 = BigUnsigned<One, One, One>;
using n8 = BigUnsigned<Zero, Zero, Zero, One>;
using n9 = BigUnsigned<One, Zero, Zero, One>;
using n10 = BigUnsigned<Zero, One, Zero, One>;
using n11 = BigUnsigned<One, One, Zero, One>;
using n12 = BigUnsigned<Zero, Zero, One, One>;
using n13 = BigUnsigned<One, Zero, One, One>;
using n14 = BigUnsigned<Zero, One, One, One>;
using n15 = BigUnsigned<One, One, One, One>;
using n16 = BigUnsigned<Zero, Zero, Zero, Zero, One>;
using n17 = BigUnsigned<One, Zero, Zero, Zero, One>;
using n18 = BigUnsigned<Zero, One, Zero, Zero, One>;
using n19 = BigUnsigned<One, One, Zero, Zero, One>;
using n20 = BigUnsigned<Zero, Zero, One, Zero, One>;
using n21 = BigUnsigned<One, Zero, One, Zero, One>;
using n22 = BigUnsigned<Zero, One, One, Zero, One>;
using n23 = BigUnsigned<One, One, One, Zero, One>;
using n24 = BigUnsigned<Zero, Zero, Zero, One, One>;
using n25 = BigUnsigned<One, Zero, Zero, One, One>;
using n26 = BigUnsigned<Zero, One, Zero, One, One>;
using n27 = BigUnsigned<One, One, Zero, One, One>;
using n28 = BigUnsigned<Zero, Zero, One, One, One>;
using n29 = BigUnsigned<One, Zero, One, One, One>;
using n30 = BigUnsigned<Zero, One, One, One, One>;
using n31 = BigUnsigned<One, One, One, One, One>;
using n32 = BigUnsigned<Zero, Zero, Zero, Zero, Zero, One>;
using n33 = BigUnsigned<One, Zero, Zero, Zero, Zero, One>;
using n34 = BigUnsigned<Zero, One, Zero, Zero, Zero, One>;
using n35 = BigUnsigned<One, One, Zero, Zero, Zero, One>;
using n36 = BigUnsigned<Zero, Zero, One, Zero, Zero, One>;
using n37 = BigUnsigned<One, Zero, One, Zero, Zero, One>;
using n38 = BigUnsigned<Zero, One, One, Zero, Zero, One>;
using n39 = BigUnsigned<One, One, One, Zero, Zero, One>;
using n40 = BigUnsigned<Zero, Zero, Zero, One, Zero, One>;
using n41 = BigUnsigned<One, Zero, Zero, One, Zero, One>;
using n42 = BigUnsigned<Zero, One, Zero, One, Zero, One>;
using n43 = BigUnsigned<One, One, Zero, One, Zero, One>;
using n44 = BigUnsigned<Zero, Zero, One, One, Zero, One>;
using n45 = BigUnsigned<One, Zero, One, One, Zero, One>;
using n46 = BigUnsigned<Zero, One, One, One, Zero, One>;
using n47 = BigUnsigned<One, One, One, One, Zero, One>;
using n48 = BigUnsigned<Zero, Zero, Zero, Zero, One, One>;
using n49 = BigUnsigned<One, Zero, Zero, Zero, One, One>;
using n50 = BigUnsigned<Zero, One, Zero, Zero, One, One>;
using n51 = BigUnsigned<One, One, Zero, Zero, One, One>;
using n52 = BigUnsigned<Zero, Zero, One, Zero, One, One>;
using n53 = BigUnsigned<One, Zero, One, Zero, One, One>;
using n54 = BigUnsigned<Zero, One, One, Zero, One, One>;
using n55 = BigUnsigned<One, One, One, Zero, One, One>;
using n56 = BigUnsigned<Zero, Zero, Zero, One, One, One>;
using n57 = BigUnsigned<One, Zero, Zero, One, One, One>;
using n58 = BigUnsigned<Zero, One, Zero, One, One, One>;
using n59 = BigUnsigned<One, One, Zero, One, One, One>;
using n60 = BigUnsigned<Zero, Zero, One, One, One, One>;
using n61 = BigUnsigned<One, Zero, One, One, One, One>;
using n62 = BigUnsigned<Zero, One, One, One, One, One>;
using n63 = BigUnsigned<One, One, One, One, One, One>;
using n64 = BigUnsigned<Zero, Zero, Zero, Zero, Zero, Zero, One>;

namespace unsigned_add_tests
{
    using A5 = BigUnsignedAdd_v<n3, n2>;
    using A16 = BigUnsignedAdd_v<n8, n8>;
    using A8 = BigUnsignedAdd_v<n7, n1>;
    using A1 = BigUnsignedAdd_v<n0, n1>;
    using A0 = BigUnsignedAdd_v<n0, n0>;
    using A15_1 = BigUnsignedAdd_v<n15, n0>;
    using A15_2 = BigUnsignedAdd_v<n0, n15>;
    using A16_1 = BigUnsignedAdd_v<n15, n1>;
    using A16_2 = BigUnsignedAdd_v<n1, n15>;
    using A6 = BigUnsignedAdd_v<n2, n4>;
    using A9 = BigUnsignedAdd_v<n5, n4>;
    using A11 = BigUnsignedAdd_v<n3, n8>;
    using A14 = BigUnsignedAdd_v<n6, n8>;
    using A15 = BigUnsignedAdd_v<n7, n8>;
    using A10 = BigUnsignedAdd_v<n4, n6>;
    using A13 = BigUnsignedAdd_v<n5, n8>;
    using A17 = BigUnsignedAdd_v<n9, n8>;
    using A19 = BigUnsignedAdd_v<n11, n8>;
    using A22 = BigUnsignedAdd_v<n14, n8>;
    using A25 = BigUnsignedAdd_v<n16, n9>;
    using A28 = BigUnsignedAdd_v<n19, n9>;
    using A30 = BigUnsignedAdd_v<n20, n10>;
    using A33 = BigUnsignedAdd_v<n22, n11>;
    using A35 = BigUnsignedAdd_v<n24, n11>;
    using A38 = BigUnsignedAdd_v<n27, n11>;
    using A40 = BigUnsignedAdd_v<n30, n10>;
    using A42 = BigUnsignedAdd_v<n33, n9>;
    using A45 = BigUnsignedAdd_v<n36, n9>;
    using A48 = BigUnsignedAdd_v<n39, n9>;
    using A50 = BigUnsignedAdd_v<n41, n9>;

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
} // namespace unsigned_add_tests

namespace ListAppendImpl
{
    template <Any_t Elem, List_t List>
    struct ListAppend;

    template <Any_t Elem, List_t List>
    using ListAppend_v = ListAppend<Elem, List>::result;

    template <Any_t Elem, Any_t... Rest>
    struct ListAppend<Elem, List<Rest...>>
    {
        using result = List<Rest..., Elem>;
    };
} // namespace ListAppendImpl

using ListAppendImpl::ListAppend_v;

namespace ListReverseImpl
{
    template <List_t In, List_t Acc = List<>>
    struct ListReverse;

    template <List_t In, List_t Acc = List<>>
    using ListReverse_v = ListReverse<In, Acc>::result;

    template <List_t Acc>
    struct ListReverse<List<>, Acc>
    {
        using result = Acc;
    };

    template <Any_t Head, Any_t... Tail, List_t Acc>
    struct ListReverse<List<Head, Tail...>, Acc>
    {
        using result = ListReverse_v<List<Tail...>, ListPrepend_v<Head, Acc>>;
    };
} // namespace ListReverseImpl

using ListReverseImpl::ListReverse_v;

namespace BigUnsignedIncImpl
{
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

        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <BigUnsigned_t Num>
    struct BigUnsignedInc;

    template <BigUnsigned_t Num>
    using BigUnsignedInc_v = BigUnsignedInc<Num>::result;

    template <Bit_t... Bits>
    struct BigUnsignedInc<BigUnsigned<Bits...>>
    {
        using result = ToBigUnsigned_v<AddCarry_v<List<Bits...>, One>>;
    };
} // namespace BigUnsignedIncImpl

using BigUnsignedIncImpl::BigUnsignedInc_v;

namespace ListLengthImpl
{
    template <List_t L>
    struct ListLength;

    template <List_t L>
    using ListLength_v = typename ListLength<L>::result;

    template <>
    struct ListLength<List<>>
    {
        using result = BigUnsigned<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct ListLength<List<Head, Tail...>>
    {
        using result = BigUnsignedInc_v<ListLength_v<List<Tail...>>>;
    };
} // namespace ListLengthImpl

using ListLengthImpl::ListLength_v;

namespace BigUnsignedGEImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedGreaterEqImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedGreaterEqImpl_v =
        BigUnsignedGreaterEqImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedGreaterEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct BigUnsignedGreaterEqImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<SameBit, LRest...>,
                                    List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedGreaterEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedGreaterEqImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = IsSame_v<L0, One>;
    };

    template <List_t LHS, List_t RHS>
    struct GEImplIsRHSLongest;

    template <List_t LHS, List_t RHS>
    using GEImplIsLHSLongest_v = GEImplIsRHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct GEImplIsRHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = GEImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct GEImplIsRHSLongest<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct GEImplIsRHSLongest<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct GEImplIsRHSLongest<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedGE;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedGE_v = BigUnsignedGE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedGE<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            BigUnsignedGreaterEqImpl_v<ListReverse_v<List<LHS...>>,
                                       ListReverse_v<List<RHS...>>>,

            GEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace BigUnsignedGEImpl

using BigUnsignedGEImpl::BigUnsignedGE_v;

namespace ToListImpl
{
    template <BigUnsigned_t T>
    struct ToList;

    template <BigUnsigned_t T>
    using ToList_v = ToList<T>::result;

    template <Bit_t... Bits>
    struct ToList<BigUnsigned<Bits...>>
    {
        using result = List<Bits...>;
    };
} // namespace ToListImpl

using ToListImpl::ToList_v;

namespace FullSubtractorImpl
{

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
} // namespace FullSubtractorImpl

using FullSubtractorImpl::FullSubtractor;

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
} // namespace BigUnsignedCanonicalizeImpl

using BigUnsignedCanonicalizeImpl::BigUnsignedCanonicalize_v;

namespace BigUnsignedSubImpl
{
    template <List_t LHS, List_t RHS, Bit_t Borrow>
    struct SubBigUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Borrow>
    using SubBigUnsignedCarry_v = SubBigUnsignedCarry<LHS, RHS, Borrow>::result;

    template <Bit_t Borrow>
    struct SubBigUnsignedCarry<List<>, List<>, Borrow>
    {
        using result = Ternary_v<IsSame_v<Borrow, One>, List<>, List<>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<L0, LRest...>, List<>, Borrow>
    {
        using FS = FullSubtractor<L0, Zero, Borrow>;
        using tail =
            SubBigUnsignedCarry_v<List<LRest...>, List<>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<Zero, R0, Borrow>;
        using tail =
            SubBigUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubBigUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<L0, R0, Borrow>;
        using tail = SubBigUnsignedCarry_v<List<LRest...>, List<RRest...>,
                                           typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedSub;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedSub_v = BigUnsignedSub<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedSub<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = BigUnsignedCanonicalize_v<ToBigUnsigned_v<
            SubBigUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>>;
    };
} // namespace BigUnsignedSubImpl

using BigUnsignedSubImpl::BigUnsignedSub_v;

namespace BigUnsignedLShiftImpl
{
    template <BigUnsigned_t Value, BigUnsigned_t Amount>
    struct BigUnsignedLShift;

    template <BigUnsigned_t Value, BigUnsigned_t Amount>
    using BigUnsignedLShift_v = BigUnsignedLShift<Value, Amount>::result;

    template <BigUnsigned_t Value>
    struct BigUnsignedLShift<Value, BigUnsigned<>>
    {
        using result = Value;
    };

    template <BigUnsigned_t Value, Bit_t... AmountBits>
    struct BigUnsignedLShift<Value, BigUnsigned<AmountBits...>>
    {
        using NewBits = ListPrepend_v<Zero, ToList_v<Value>>;
        using ShiftedOnce = ToBigUnsigned_v<NewBits>;

        using Decrement =
            BigUnsignedSub_v<BigUnsigned<AmountBits...>, BigUnsigned<One>>;
        using result = BigUnsignedCanonicalize_v<
            BigUnsignedLShift_v<ShiftedOnce, Decrement>>;
    };
} // namespace BigUnsignedLShiftImpl

using BigUnsignedLShiftImpl::BigUnsignedLShift_v;

namespace BigUnsignedDivImpl
{
    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct BigUnsignedDivStep;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using BigUnsignedDivStep_quot =
        BigUnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::quotient;

    template <List_t BitsMSB, BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    using BigUnsignedDivStep_rem =
        BigUnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::remainder;

    template <BigUnsigned_t Divisor, BigUnsigned_t Remainder,
              List_t QuotientMSB>
    struct BigUnsignedDivStep<List<>, Divisor, Remainder, QuotientMSB>
    {
        using quotient = QuotientMSB;
        using remainder = Remainder;
    };

    template <Bit_t B0, Bit_t... BRest, BigUnsigned_t Divisor,
              BigUnsigned_t Remainder, List_t QuotientMSB>
    struct BigUnsignedDivStep<List<B0, BRest...>, Divisor, Remainder,
                              QuotientMSB>
    {
        using Shifted = BigUnsignedLShift_v<Remainder, BigUnsigned<One>>;
        using NewRem = BigUnsignedAdd_v<Shifted, BigUnsigned<B0>>;

        using UpdatedRem = Ternary_v<BigUnsignedGE_v<NewRem, Divisor>,
                                     BigUnsignedSub_v<NewRem, Divisor>, NewRem>;

        using NewQuot =
            ListAppend_v<Ternary_v<BigUnsignedGE_v<NewRem, Divisor>, One, Zero>,
                         QuotientMSB>;

        using Rec =
            BigUnsignedDivStep<List<BRest...>, Divisor, UpdatedRem, NewQuot>;

        using quotient = Rec::quotient;
        using remainder = Rec::remainder;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedDivModCommon;

    template <Bit_t... LHSBits>
    struct BigUnsignedDivModCommon<BigUnsigned<LHSBits...>, BigUnsigned<>>
    {
        static_assert(false, "BigUnsignedModDivCommon: Division by 0");
    };

    template <Bit_t... LHSBits, Bit_t... RHSBits>
    struct BigUnsignedDivModCommon<BigUnsigned<LHSBits...>,
                                   BigUnsigned<RHSBits...>>
    {
        using LHSList = List<LHSBits...>;
        using RHSNum = BigUnsigned<RHSBits...>;
        using LHSBitsMSB = ListReverse_v<LHSList>;

        using Quotient = ListReverse_v<
            BigUnsignedDivStep_quot<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>>;

        using DivStep =
            BigUnsignedDivStep<LHSBitsMSB, RHSNum, BigUnsigned<>, List<>>;

        using remainder =
            BigUnsignedCanonicalize_v<typename DivStep::remainder>;
        using quotient = BigUnsignedCanonicalize_v<
            ToBigUnsigned_v<ListReverse_v<typename DivStep::quotient>>>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedDiv_v = BigUnsignedDivModCommon<LHS, RHS>::quotient;
} // namespace BigUnsignedDivImpl

using BigUnsignedDivImpl::BigUnsignedDiv_v;

namespace unsigned_div_tests
{

    static_assert(is_same<BigUnsignedDiv_v<n1, n2>, n0>);
    static_assert(is_same<BigUnsignedDiv_v<n5, n5>, n1>);
    static_assert(is_same<BigUnsignedDiv_v<n10, n2>, n5>);
    static_assert(is_same<BigUnsignedDiv_v<n10, n1>, n10>);
    static_assert(is_same<BigUnsignedDiv_v<n0, n5>, n0>);
    static_assert(is_same<BigUnsignedDiv_v<n20, n4>, n5>);
    static_assert(is_same<BigUnsignedDiv_v<n50, n10>, n5>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n2>, n32>);
    static_assert(is_same<BigUnsignedDiv_v<n25, n3>, n8>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n1>, n64>);
    static_assert(is_same<BigUnsignedDiv_v<n50, n25>, n2>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n63>, n1>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n16>, n4>);
    static_assert(is_same<BigUnsignedDiv_v<n15, n1>, n15>);
    static_assert(is_same<BigUnsignedDiv_v<n10, n3>, n3>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n64>, n1>);
    static_assert(is_same<BigUnsignedDiv_v<n30, n7>, n4>);
    static_assert(is_same<BigUnsignedDiv_v<n17, n5>, n3>);
    static_assert(is_same<BigUnsignedDiv_v<n50, n26>, n1>);
    static_assert(is_same<BigUnsignedDiv_v<n50, n24>, n2>);
    static_assert(is_same<BigUnsignedDiv_v<n1, n64>, n0>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n1>, n64>);
    static_assert(is_same<BigUnsignedDiv_v<n10, n20>, n0>);
    static_assert(is_same<BigUnsignedDiv_v<n64, n1>, n64>);
} // namespace unsigned_div_tests

namespace BigUnsignedEQImpl
{
    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedEQ;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedEQ_v = BigUnsignedEQ<LHS, RHS>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedEQ
    {
        using result = IsSame_v<LHS, RHS>;
    };
} // namespace BigUnsignedEQImpl

using BigUnsignedEQImpl::BigUnsignedEQ_v;

namespace unsigned_eq_tests
{
    static_assert(is_same<BigUnsignedEQ_v<n1, n1>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n1, n2>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n5, n5>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n5, n6>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n10, n10>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n10, n11>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n0, n0>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n1, n0>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n64, n64>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n64, n63>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n32, n32>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n32, n33>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n1, n1>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n1, n2>, False>);
    static_assert(is_same<BigUnsignedEQ_v<n10, n10>, True>);
    static_assert(is_same<BigUnsignedEQ_v<n10, n20>, False>);
} // namespace unsigned_eq_tests

namespace unsigned_ge_tests
{
    static_assert(is_same<BigUnsignedGE_v<n1, n2>, False>);
    static_assert(is_same<BigUnsignedGE_v<n1, n1>, True>);
    static_assert(is_same<BigUnsignedGE_v<n2, n1>, True>);
    static_assert(is_same<BigUnsignedGE_v<n10, n20>, False>);
    static_assert(is_same<BigUnsignedGE_v<n10, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n20, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n63, n64>, False>);
    static_assert(is_same<BigUnsignedGE_v<n64, n63>, True>);
    static_assert(is_same<BigUnsignedGE_v<n50, n60>, False>);
    static_assert(is_same<BigUnsignedGE_v<n50, n50>, True>);
    static_assert(is_same<BigUnsignedGE_v<n60, n50>, True>);
    static_assert(is_same<BigUnsignedGE_v<n0, n1>, False>);
    static_assert(is_same<BigUnsignedGE_v<n0, n0>, True>);
    static_assert(is_same<BigUnsignedGE_v<n1, n0>, True>);
    static_assert(is_same<BigUnsignedGE_v<n64, n64>, True>);
    static_assert(is_same<BigUnsignedGE_v<n10, n30>, False>);
    static_assert(is_same<BigUnsignedGE_v<n30, n10>, True>);
    static_assert(is_same<BigUnsignedGE_v<n32, n33>, False>);
    static_assert(is_same<BigUnsignedGE_v<n33, n33>, True>);
    static_assert(is_same<BigUnsignedGE_v<n33, n32>, True>);
} // namespace unsigned_ge_tests

namespace BigUnsignedGTImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedGreaterThanImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedGreaterThanImpl_v =
        BigUnsignedGreaterThanImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedGreaterThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct BigUnsignedGreaterThanImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<SameBit, LRest...>,
                                      List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedGreaterThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedGreaterThanImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = IsSame_v<L0, One>;
    };

    template <List_t LHS, List_t RHS>
    struct GTImplIsRHSLongest;

    template <List_t LHS, List_t RHS>
    using GTImplIsLHSLongest_v = GTImplIsRHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct GTImplIsRHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = GTImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct GTImplIsRHSLongest<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct GTImplIsRHSLongest<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct GTImplIsRHSLongest<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedGT;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedGT_v = BigUnsignedGT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedGT<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            BigUnsignedGreaterThanImpl_v<ListReverse_v<List<LHS...>>,
                                         ListReverse_v<List<RHS...>>>,

            GTImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace BigUnsignedGTImpl

using BigUnsignedGTImpl::BigUnsignedGT_v;

namespace unsigned_gt_tests
{
    static_assert(is_same<BigUnsignedGT_v<n1, n2>, False>);
    static_assert(is_same<BigUnsignedGT_v<n1, n1>, False>);
    static_assert(is_same<BigUnsignedGT_v<n2, n1>, True>);
    static_assert(is_same<BigUnsignedGT_v<n10, n20>, False>);
    static_assert(is_same<BigUnsignedGT_v<n10, n10>, False>);
    static_assert(is_same<BigUnsignedGT_v<n20, n10>, True>);
    static_assert(is_same<BigUnsignedGT_v<n63, n64>, False>);
    static_assert(is_same<BigUnsignedGT_v<n64, n63>, True>);
    static_assert(is_same<BigUnsignedGT_v<n50, n60>, False>);
    static_assert(is_same<BigUnsignedGT_v<n50, n50>, False>);
    static_assert(is_same<BigUnsignedGT_v<n60, n50>, True>);
    static_assert(is_same<BigUnsignedGT_v<n0, n1>, False>);
    static_assert(is_same<BigUnsignedGT_v<n0, n0>, False>);
    static_assert(is_same<BigUnsignedGT_v<n1, n0>, True>);
    static_assert(is_same<BigUnsignedGT_v<n64, n64>, False>);
    static_assert(is_same<BigUnsignedGT_v<n10, n30>, False>);
    static_assert(is_same<BigUnsignedGT_v<n30, n10>, True>);
    static_assert(is_same<BigUnsignedGT_v<n32, n33>, False>);
    static_assert(is_same<BigUnsignedGT_v<n33, n33>, False>);
    static_assert(is_same<BigUnsignedGT_v<n33, n32>, True>);
} // namespace unsigned_gt_tests

namespace unsigned_increment_tests
{
    using N0 = n0;
    using N1 = BigUnsignedInc_v<N0>;
    using N2 = BigUnsignedInc_v<N1>;
    using N3 = BigUnsignedInc_v<N2>;
    using N4 = BigUnsignedInc_v<N3>;
    using N5 = BigUnsignedInc_v<N4>;
    using N6 = BigUnsignedInc_v<N5>;
    using N7 = BigUnsignedInc_v<N6>;
    using N8 = BigUnsignedInc_v<N7>;
    using N9 = BigUnsignedInc_v<N8>;
    using N10 = BigUnsignedInc_v<N9>;
    using N11 = BigUnsignedInc_v<N10>;
    using N12 = BigUnsignedInc_v<N11>;
    using N13 = BigUnsignedInc_v<N12>;
    using N14 = BigUnsignedInc_v<N13>;
    using N15 = BigUnsignedInc_v<N14>;
    using N16 = BigUnsignedInc_v<N15>;
    using N17 = BigUnsignedInc_v<N16>;
    using N18 = BigUnsignedInc_v<N17>;
    using N19 = BigUnsignedInc_v<N18>;
    using N20 = BigUnsignedInc_v<N19>;
    using N21 = BigUnsignedInc_v<N20>;
    using N22 = BigUnsignedInc_v<N21>;
    using N23 = BigUnsignedInc_v<N22>;
    using N24 = BigUnsignedInc_v<N23>;
    using N25 = BigUnsignedInc_v<N24>;
    using N26 = BigUnsignedInc_v<N25>;
    using N27 = BigUnsignedInc_v<N26>;
    using N28 = BigUnsignedInc_v<N27>;
    using N29 = BigUnsignedInc_v<N28>;
    using N30 = BigUnsignedInc_v<N29>;
    using N31 = BigUnsignedInc_v<N30>;
    using N32 = BigUnsignedInc_v<N31>;
    using N33 = BigUnsignedInc_v<N32>;
    using N34 = BigUnsignedInc_v<N33>;
    using N35 = BigUnsignedInc_v<N34>;
    using N36 = BigUnsignedInc_v<N35>;
    using N37 = BigUnsignedInc_v<N36>;
    using N38 = BigUnsignedInc_v<N37>;
    using N39 = BigUnsignedInc_v<N38>;
    using N40 = BigUnsignedInc_v<N39>;
    using N41 = BigUnsignedInc_v<N40>;
    using N42 = BigUnsignedInc_v<N41>;
    using N43 = BigUnsignedInc_v<N42>;
    using N44 = BigUnsignedInc_v<N43>;
    using N45 = BigUnsignedInc_v<N44>;
    using N46 = BigUnsignedInc_v<N45>;
    using N47 = BigUnsignedInc_v<N46>;
    using N48 = BigUnsignedInc_v<N47>;
    using N49 = BigUnsignedInc_v<N48>;
    using N50 = BigUnsignedInc_v<N49>;
    using N51 = BigUnsignedInc_v<N50>;
    using N52 = BigUnsignedInc_v<N51>;
    using N53 = BigUnsignedInc_v<N52>;
    using N54 = BigUnsignedInc_v<N53>;
    using N55 = BigUnsignedInc_v<N54>;
    using N56 = BigUnsignedInc_v<N55>;
    using N57 = BigUnsignedInc_v<N56>;
    using N58 = BigUnsignedInc_v<N57>;
    using N59 = BigUnsignedInc_v<N58>;
    using N60 = BigUnsignedInc_v<N59>;
    using N61 = BigUnsignedInc_v<N60>;
    using N62 = BigUnsignedInc_v<N61>;
    using N63 = BigUnsignedInc_v<N62>;
    using N64 = BigUnsignedInc_v<N63>;

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
} // namespace unsigned_increment_tests

namespace BigUnsignedLEImpl
{
    template <List_t LHS, List_t RHS>
    struct BigUnsignedLowerEqImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedLowerEqImpl_v = BigUnsignedLowerEqImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedLowerEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct BigUnsignedLowerEqImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<SameBit, LRest...>,
                                  List<SameBit, RRest...>>
    {
        using result = BigUnsignedLowerEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedLowerEqImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = IsSame_v<L0, Zero>;
    };

    template <List_t LHS, List_t RHS>
    struct LEImplIsLHSLongest;

    template <List_t LHS, List_t RHS>
    using LEImplIsLHSLongest_v = LEImplIsLHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct LEImplIsLHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = LEImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct LEImplIsLHSLongest<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct LEImplIsLHSLongest<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct LEImplIsLHSLongest<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedLE;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedLE_v = BigUnsignedLE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedLE<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            BigUnsignedLowerEqImpl_v<ListReverse_v<List<LHS...>>,
                                     ListReverse_v<List<RHS...>>>,

            LEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace BigUnsignedLEImpl

using BigUnsignedLEImpl::BigUnsignedLE_v;

namespace unsigned_le_tests
{
    static_assert(is_same<BigUnsignedLE_v<n1, n2>, True>);
    static_assert(is_same<BigUnsignedLE_v<n1, n1>, True>);
    static_assert(is_same<BigUnsignedLE_v<n2, n1>, False>);
    static_assert(is_same<BigUnsignedLE_v<n10, n20>, True>);
    static_assert(is_same<BigUnsignedLE_v<n10, n10>, True>);
    static_assert(is_same<BigUnsignedLE_v<n20, n10>, False>);
    static_assert(is_same<BigUnsignedLE_v<n63, n64>, True>);
    static_assert(is_same<BigUnsignedLE_v<n64, n63>, False>);
    static_assert(is_same<BigUnsignedLE_v<n50, n60>, True>);
    static_assert(is_same<BigUnsignedLE_v<n50, n50>, True>);
    static_assert(is_same<BigUnsignedLE_v<n60, n50>, False>);
    static_assert(is_same<BigUnsignedLE_v<n0, n1>, True>);
    static_assert(is_same<BigUnsignedLE_v<n0, n0>, True>);
    static_assert(is_same<BigUnsignedLE_v<n1, n0>, False>);
    static_assert(is_same<BigUnsignedLE_v<n64, n64>, True>);
    static_assert(is_same<BigUnsignedLE_v<n10, n30>, True>);
    static_assert(is_same<BigUnsignedLE_v<n30, n10>, False>);
    static_assert(is_same<BigUnsignedLE_v<n32, n33>, True>);
    static_assert(is_same<BigUnsignedLE_v<n33, n33>, True>);
    static_assert(is_same<BigUnsignedLE_v<n33, n32>, False>);
} // namespace unsigned_le_tests

namespace unsigned_lshift_tests
{
    static_assert(is_same<BigUnsignedLShift_v<n1, n0>, n1>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n1>, n2>);
    static_assert(is_same<BigUnsignedLShift_v<n2, n2>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n3, n3>, n24>);
    static_assert(is_same<BigUnsignedLShift_v<n4, n1>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n5, n2>, n20>);
    static_assert(is_same<BigUnsignedLShift_v<n6, n1>, n12>);
    static_assert(is_same<BigUnsignedLShift_v<n7, n2>, n28>);
    static_assert(is_same<BigUnsignedLShift_v<n8, n1>, n16>);
    static_assert(is_same<BigUnsignedLShift_v<n9, n2>, n36>);
    static_assert(is_same<BigUnsignedLShift_v<n10, n1>, n20>);
    static_assert(is_same<BigUnsignedLShift_v<n0, n5>, n0>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n3>, n8>);
    static_assert(is_same<BigUnsignedLShift_v<n2, n1>, n4>);
    static_assert(is_same<BigUnsignedLShift_v<n3, n2>, n12>);
    static_assert(is_same<BigUnsignedLShift_v<n4, n3>, n32>);
    static_assert(is_same<BigUnsignedLShift_v<n5, n1>, n10>);
    static_assert(is_same<BigUnsignedLShift_v<n6, n2>, n24>);
    static_assert(is_same<BigUnsignedLShift_v<n7, n1>, n14>);
    static_assert(is_same<BigUnsignedLShift_v<n8, n2>, n32>);
    static_assert(is_same<BigUnsignedLShift_v<n1, n4>, n16>);
} // namespace unsigned_lshift_tests

namespace BigUnsignedLTImpl
{

    template <List_t LHS, List_t RHS>
    struct BigUnsignedLowerThanImpl;

    template <List_t LHS, List_t RHS>
    using BigUnsignedLowerThanImpl_v =
        BigUnsignedLowerThanImpl<LHS, RHS>::result;

    template <>
    struct BigUnsignedLowerThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct BigUnsignedLowerThanImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<SameBit, LRest...>,
                                    List<SameBit, RRest...>>
    {
        using result =
            BigUnsignedLowerThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct BigUnsignedLowerThanImpl<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = IsSame_v<L0, Zero>;
    };

    template <List_t LHS, List_t RHS>
    struct LTImplIsLHSLongest;

    template <List_t LHS, List_t RHS>
    using LTImplIsLHSLongest_v = LTImplIsLHSLongest<LHS, RHS>::result;

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct LTImplIsLHSLongest<List<L0, LRest...>, List<R0, RRest...>>
    {
        using result = LTImplIsLHSLongest_v<List<LRest...>, List<RRest...>>;
    };

    template <>
    struct LTImplIsLHSLongest<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct LTImplIsLHSLongest<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct LTImplIsLHSLongest<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedLT;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedLT_v = BigUnsignedLT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedLT<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            BigUnsignedLowerThanImpl_v<ListReverse_v<List<LHS...>>,
                                       ListReverse_v<List<RHS...>>>,

            LTImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace BigUnsignedLTImpl

using BigUnsignedLTImpl::BigUnsignedLT_v;

namespace unsigned_lt_tests
{
    static_assert(is_same<BigUnsignedLT_v<n1, n2>, True>);
    static_assert(is_same<BigUnsignedLT_v<n1, n1>, False>);
    static_assert(is_same<BigUnsignedLT_v<n2, n1>, False>);
    static_assert(is_same<BigUnsignedLT_v<n10, n20>, True>);
    static_assert(is_same<BigUnsignedLT_v<n10, n10>, False>);
    static_assert(is_same<BigUnsignedLT_v<n20, n10>, False>);
    static_assert(is_same<BigUnsignedLT_v<n63, n64>, True>);
    static_assert(is_same<BigUnsignedLT_v<n64, n63>, False>);
    static_assert(is_same<BigUnsignedLT_v<n50, n60>, True>);
    static_assert(is_same<BigUnsignedLT_v<n50, n50>, False>);
    static_assert(is_same<BigUnsignedLT_v<n60, n50>, False>);
    static_assert(is_same<BigUnsignedLT_v<n0, n1>, True>);
    static_assert(is_same<BigUnsignedLT_v<n0, n0>, False>);
    static_assert(is_same<BigUnsignedLT_v<n1, n0>, False>);
    static_assert(is_same<BigUnsignedLT_v<n64, n64>, False>);
    static_assert(is_same<BigUnsignedLT_v<n10, n30>, True>);
    static_assert(is_same<BigUnsignedLT_v<n30, n10>, False>);
    static_assert(is_same<BigUnsignedLT_v<n32, n33>, True>);
    static_assert(is_same<BigUnsignedLT_v<n33, n33>, False>);
    static_assert(is_same<BigUnsignedLT_v<n33, n32>, False>);
} // namespace unsigned_lt_tests

namespace BigUnsignedModImpl
{
    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedMod_v =
        BigUnsignedDivImpl::BigUnsignedDivModCommon<LHS, RHS>::remainder;
}

using BigUnsignedModImpl::BigUnsignedMod_v;

namespace unsigned_mod_tests
{

    static_assert(is_same<BigUnsignedMod_v<n1, n2>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n5, n5>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n10, n2>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n10, n1>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n0, n5>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n20, n4>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n50, n10>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n64, n2>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n25, n3>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n1>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n50, n25>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n64, n63>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n16>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n15, n16>, n15>);
    static_assert(is_same<BigUnsignedMod_v<n10, n3>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n64>, n0>);
    static_assert(is_same<BigUnsignedMod_v<n30, n7>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n17, n5>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n50, n26>, n24>);
    static_assert(is_same<BigUnsignedMod_v<n50, n24>, n2>);
    static_assert(is_same<BigUnsignedMod_v<n1, n64>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n33, n32>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n10, n9>, n1>);
    static_assert(is_same<BigUnsignedMod_v<n64, n1>, n0>);
} // namespace unsigned_mod_tests

namespace BigUnsignedMulImpl
{
    template <BigUnsigned_t LHS, Bit_t RHS, BigUnsigned_t Shift>
    struct MulByBit;

    template <BigUnsigned_t LHS, Bit_t RHS, BigUnsigned_t Shift>
    using MulByBit_v = MulByBit<LHS, RHS, Shift>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulByBit<LHS, Zero, Shift>
    {
        using result = BigUnsigned<>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct MulByBit<LHS, One, Shift>
    {
        using result = BigUnsignedLShift_v<LHS, Shift>;
    };

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper;

    template <BigUnsigned_t LHS, List_t BList, BigUnsigned_t Shift>
    using BigUnsignedMulHelper_v =
        BigUnsignedMulHelper<LHS, BList, Shift>::result;

    template <BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper<LHS, List<>, Shift>
    {
        using result = BigUnsigned<>;
    };

    template <Bit_t R0, Bit_t... RRest, BigUnsigned_t LHS, BigUnsigned_t Shift>
    struct BigUnsignedMulHelper<LHS, List<R0, RRest...>, Shift>
    {
        using partial = MulByBit_v<LHS, R0, Shift>;
        using rest = BigUnsignedMulHelper_v<LHS, List<RRest...>,
                                            BigUnsignedInc_v<Shift>>;
        using result = BigUnsignedAdd_v<partial, rest>;
    };

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    struct BigUnsignedMul;

    template <BigUnsigned_t LHS, BigUnsigned_t RHS>
    using BigUnsignedMul_v = BigUnsignedMul<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct BigUnsignedMul<BigUnsigned<LHS...>, BigUnsigned<RHS...>>
    {
        using result = BigUnsignedCanonicalize_v<BigUnsignedMulHelper_v<
            BigUnsigned<LHS...>, List<RHS...>, BigUnsigned<>>>;
    };
} // namespace BigUnsignedMulImpl

using BigUnsignedMulImpl::BigUnsignedMul_v;

namespace unsigned_mul_tests
{
    using M0 = BigUnsignedMul_v<n0, n1>;
    using M1 = BigUnsignedMul_v<n1, n1>;
    using M0_1 = BigUnsignedMul_v<n0, n0>;
    using M4 = BigUnsignedMul_v<n2, n2>;
    using M6 = BigUnsignedMul_v<n2, n3>;
    using M8 = BigUnsignedMul_v<n2, n4>;
    using M10 = BigUnsignedMul_v<n2, n5>;
    using M12 = BigUnsignedMul_v<n3, n4>;
    using M14 = BigUnsignedMul_v<n2, n7>;
    using M15 = BigUnsignedMul_v<n3, n5>;
    using M16 = BigUnsignedMul_v<n4, n4>;
    using M18 = BigUnsignedMul_v<n3, n6>;
    using M20 = BigUnsignedMul_v<n4, n5>;
    using M21 = BigUnsignedMul_v<n3, n7>;
    using M24 = BigUnsignedMul_v<n3, n8>;
    using M25 = BigUnsignedMul_v<n5, n5>;
    using M27 = BigUnsignedMul_v<n3, n9>;
    using M28 = BigUnsignedMul_v<n4, n7>;
    using M30 = BigUnsignedMul_v<n5, n6>;
    using M32 = BigUnsignedMul_v<n4, n8>;
    using M35 = BigUnsignedMul_v<n5, n7>;
    using M36 = BigUnsignedMul_v<n4, n9>;
    using M40 = BigUnsignedMul_v<n5, n8>;
    using M42 = BigUnsignedMul_v<n6, n7>;
    using M45 = BigUnsignedMul_v<n5, n9>;
    using M48 = BigUnsignedMul_v<n6, n8>;
    using M49 = BigUnsignedMul_v<n7, n7>;
    using M54 = BigUnsignedMul_v<n6, n9>;
    using M56 = BigUnsignedMul_v<n7, n8>;
    using M63 = BigUnsignedMul_v<n7, n9>;
    using M64 = BigUnsignedMul_v<n8, n8>;

    static_assert(is_same<M0, n0>);
    static_assert(is_same<M1, n1>);
    static_assert(is_same<M0_1, n0>);
    static_assert(is_same<M4, n4>);
    static_assert(is_same<M6, n6>);
    static_assert(is_same<M8, n8>);
    static_assert(is_same<M10, n10>);
    static_assert(is_same<M12, n12>);
    static_assert(is_same<M14, n14>);
    static_assert(is_same<M15, n15>);
    static_assert(is_same<M16, n16>);
    static_assert(is_same<M18, n18>);
    static_assert(is_same<M20, n20>);
    static_assert(is_same<M21, n21>);
    static_assert(is_same<M24, n24>);
    static_assert(is_same<M25, n25>);
    static_assert(is_same<M27, n27>);
    static_assert(is_same<M28, n28>);
    static_assert(is_same<M30, n30>);
    static_assert(is_same<M32, n32>);
    static_assert(is_same<M35, n35>);
    static_assert(is_same<M36, n36>);
    static_assert(is_same<M40, n40>);
    static_assert(is_same<M42, n42>);
    static_assert(is_same<M45, n45>);
    static_assert(is_same<M48, n48>);
    static_assert(is_same<M49, n49>);
    static_assert(is_same<M54, n54>);
    static_assert(is_same<M56, n56>);
    static_assert(is_same<M63, n63>);
    static_assert(is_same<M64, n64>);
} // namespace unsigned_mul_tests

namespace unsigned_sub_tests
{
    using S0_1 = BigUnsignedSub_v<n1, n1>;
    using S1 = BigUnsignedSub_v<n3, n2>;
    using S0 = BigUnsignedSub_v<n8, n8>;
    using S6 = BigUnsignedSub_v<n7, n1>;
    using S7 = BigUnsignedSub_v<n8, n1>;
    using S15 = BigUnsignedSub_v<n15, n0>;
    using S14 = BigUnsignedSub_v<n15, n1>;
    using S5 = BigUnsignedSub_v<n6, n1>;
    using S8 = BigUnsignedSub_v<n10, n2>;
    using S9 = BigUnsignedSub_v<n11, n2>;
    using S10 = BigUnsignedSub_v<n12, n2>;
    using S11 = BigUnsignedSub_v<n13, n2>;
    using S12 = BigUnsignedSub_v<n14, n2>;
    using S13 = BigUnsignedSub_v<n15, n2>;
    using S14_1 = BigUnsignedSub_v<n16, n2>;
    using S15_1 = BigUnsignedSub_v<n17, n2>;
    using S16 = BigUnsignedSub_v<n18, n2>;
    using S17 = BigUnsignedSub_v<n19, n2>;
    using S18 = BigUnsignedSub_v<n20, n2>;
    using S19 = BigUnsignedSub_v<n21, n2>;
    using S20 = BigUnsignedSub_v<n22, n2>;
    using S21 = BigUnsignedSub_v<n23, n2>;
    using S22 = BigUnsignedSub_v<n24, n2>;
    using S23 = BigUnsignedSub_v<n25, n2>;
    using S24 = BigUnsignedSub_v<n26, n2>;
    using S12 = BigUnsignedSub_v<n27, n15>;
    using S26 = BigUnsignedSub_v<n28, n2>;
    using S27 = BigUnsignedSub_v<n29, n2>;
    using S28 = BigUnsignedSub_v<n30, n2>;
    using S29 = BigUnsignedSub_v<n31, n2>;
    using S30 = BigUnsignedSub_v<n32, n2>;
    using S31 = BigUnsignedSub_v<n33, n2>;
    using S32 = BigUnsignedSub_v<n34, n2>;
    using S33 = BigUnsignedSub_v<n35, n2>;
    using S34 = BigUnsignedSub_v<n36, n2>;
    using S35 = BigUnsignedSub_v<n37, n2>;
    using S36 = BigUnsignedSub_v<n38, n2>;
    using S37 = BigUnsignedSub_v<n39, n2>;
    using S38 = BigUnsignedSub_v<n40, n2>;
    using S39 = BigUnsignedSub_v<n41, n2>;
    using S40 = BigUnsignedSub_v<n42, n2>;

    static_assert(is_same<S1, n1>);
    static_assert(is_same<S0, n0>);
    static_assert(is_same<S0_1, n0>);
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
    static_assert(is_same<S12, n12>);
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
} // namespace unsigned_sub_tests

namespace list_append_tests
{
    static_assert(is_same<ListAppend_v<n1, List<>>, List<n1>>);
    static_assert(is_same<ListAppend_v<n2, List<n1>>, List<n1, n2>>);
    static_assert(
        is_same<ListAppend_v<n4, List<n1, n2, n3>>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListAppend_v<n5, List<n2, n4>>, List<n2, n4, n5>>);
    static_assert(is_same<ListAppend_v<n3, List<n1>>, List<n1, n3>>);
    static_assert(is_same<List<n1>, List<n1>>);
    using L6 = ListAppend_v<n3, List<n1, n2>>;
    static_assert(is_same<L6, List<n1, n2, n3>>);
    static_assert(is_same<ListAppend_v<n4, L6>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListAppend_v<n6, List<n1, n2, n3, n4, n5>>,
                          List<n1, n2, n3, n4, n5, n6>>);
    static_assert(
        is_same<ListAppend_v<n2, List<n2, n3, n2>>, List<n2, n3, n2, n2>>);
    static_assert(is_same<ListAppend_v<n4, List<n5>>, List<n5, n4>>);
    static_assert(is_same<List<n5>, List<n5>>);
    static_assert(is_same<ListAppend_v<n6, List<n1, n2>>, List<n1, n2, n6>>);
    static_assert(is_same<List<n1, n2>, List<n1, n2>>);
    static_assert(
        is_same<ListAppend_v<n3, List<n4, n5, n6>>, List<n4, n5, n6, n3>>);
    static_assert(is_same<List<n4, n5, n6>, List<n4, n5, n6>>);
    static_assert(is_same<ListAppend_v<n1, List<n2, n3, n4, n5>>,
                          List<n2, n3, n4, n5, n1>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(is_same<ListAppend_v<n6, List<n1, n2, n3, n4, n5>>,
                          List<n1, n2, n3, n4, n5, n6>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<ListAppend_v<n2, List<n3, n4, n5, n6, n1, n2>>,
                          List<n3, n4, n5, n6, n1, n2, n2>>);
    static_assert(
        is_same<List<n3, n4, n5, n6, n1, n2>, List<n3, n4, n5, n6, n1, n2>>);
    static_assert(is_same<ListAppend_v<n4, List<n5, n6, n1, n2, n3, n4, n5>>,
                          List<n5, n6, n1, n2, n3, n4, n5, n4>>);
    static_assert(is_same<List<n5, n6, n1, n2, n3, n4, n5>,
                          List<n5, n6, n1, n2, n3, n4, n5>>);
} // namespace list_append_tests

namespace list_legth_tests
{
    static_assert(is_same<ListLength_v<List<>>, n0>);
    static_assert(is_same<ListLength_v<List<n1>>, n1>);
    static_assert(is_same<ListLength_v<List<n1, n2>>, n2>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4>>, n4>);
    static_assert(is_same<ListLength_v<List<n2, n3, n2>>, n3>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6>>, n6>);
    static_assert(is_same<ListLength_v<List<n5>>, n1>);
    static_assert(is_same<ListLength_v<List<n1, n2>>, n2>);
    static_assert(is_same<ListLength_v<List<n3, n4, n5>>, n3>);
    static_assert(is_same<ListLength_v<List<n2, n3, n4, n5>>, n4>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5>>, n5>);
    static_assert(is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6>>, n6>);
    static_assert(is_same<ListLength_v<List<n5, n4, n3, n2, n1, n6, n7>>, n7>);
    static_assert(
        is_same<ListLength_v<List<n1, n2, n3, n4, n5, n6, n7, n8>>, n8>);
    static_assert(
        is_same<ListLength_v<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>, n9>);
} // namespace list_legth_tests

namespace list_prepend_tests
{
    static_assert(is_same<ListPrepend_v<n1, List<>>, List<n1>>);
    static_assert(is_same<ListPrepend_v<n1, List<n2>>, List<n1, n2>>);
    static_assert(
        is_same<ListPrepend_v<n1, List<n2, n3, n4>>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListPrepend_v<n5, List<n2, n4>>, List<n5, n2, n4>>);
    static_assert(is_same<ListPrepend_v<n3, List<n1>>, List<n3, n1>>);
    static_assert(is_same<List<n1>, List<n1>>);
    using L6 = ListPrepend_v<n2, List<n3, n4>>;
    static_assert(is_same<L6, List<n2, n3, n4>>);
    static_assert(is_same<ListPrepend_v<n1, L6>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListPrepend_v<n1, List<n2, n3, n4, n5, n6>>,
                          List<n1, n2, n3, n4, n5, n6>>);
    static_assert(
        is_same<ListPrepend_v<n2, List<n2, n3, n2>>, List<n2, n2, n3, n2>>);
    static_assert(is_same<ListPrepend_v<n4, List<n5>>, List<n4, n5>>);
    static_assert(is_same<List<n5>, List<n5>>);
    static_assert(is_same<ListPrepend_v<n6, List<n1, n2>>, List<n6, n1, n2>>);
    static_assert(is_same<List<n1, n2>, List<n1, n2>>);
    static_assert(
        is_same<ListPrepend_v<n3, List<n4, n5, n6>>, List<n3, n4, n5, n6>>);
    static_assert(is_same<List<n4, n5, n6>, List<n4, n5, n6>>);
    static_assert(is_same<ListPrepend_v<n1, List<n2, n3, n4, n5>>,
                          List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(is_same<ListPrepend_v<n6, List<n1, n2, n3, n4, n5>>,
                          List<n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<ListPrepend_v<n2, List<n3, n4, n5, n6, n1, n2>>,
                          List<n2, n3, n4, n5, n6, n1, n2>>);
    static_assert(
        is_same<List<n3, n4, n5, n6, n1, n2>, List<n3, n4, n5, n6, n1, n2>>);
    static_assert(is_same<ListPrepend_v<n4, List<n5, n6, n1, n2, n3, n4, n5>>,
                          List<n4, n5, n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n5, n6, n1, n2, n3, n4, n5>,
                          List<n5, n6, n1, n2, n3, n4, n5>>);
} // namespace list_prepend_tests

namespace list_reverse_tests
{
    static_assert(is_same<ListReverse_v<List<>>, List<>>);
    static_assert(is_same<ListReverse_v<List<n1>>, List<n1>>);
    static_assert(is_same<ListReverse_v<List<n1, n2>>, List<n2, n1>>);
    static_assert(
        is_same<ListReverse_v<List<n1, n2, n3, n4>>, List<n4, n3, n2, n1>>);
    static_assert(is_same<ListReverse_v<List<n2, n3, n2>>, List<n2, n3, n2>>);
    static_assert(is_same<ListReverse_v<List<n1, n2, n3, n4, n5, n6>>,
                          List<n6, n5, n4, n3, n2, n1>>);
    static_assert(is_same<ListReverse_v<List<n5>>, List<n5>>);
    static_assert(is_same<List<n5>, List<n5>>);
    static_assert(is_same<ListReverse_v<List<n1, n2>>, List<n2, n1>>);
    static_assert(is_same<List<n1, n2>, List<n1, n2>>);
    static_assert(is_same<ListReverse_v<List<n3, n4, n5>>, List<n5, n4, n3>>);
    static_assert(is_same<List<n3, n4, n5>, List<n3, n4, n5>>);
    static_assert(
        is_same<ListReverse_v<List<n2, n3, n4, n5>>, List<n5, n4, n3, n2>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(is_same<ListReverse_v<List<n1, n2, n3, n4, n5>>,
                          List<n5, n4, n3, n2, n1>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(is_same<ListReverse_v<List<n1, n2, n3, n4, n5, n6>>,
                          List<n6, n5, n4, n3, n2, n1>>);
    static_assert(
        is_same<List<n1, n2, n3, n4, n5, n6>, List<n1, n2, n3, n4, n5, n6>>);
    static_assert(is_same<ListReverse_v<List<n5, n4, n3, n2, n1, n6, n7>>,
                          List<n7, n6, n1, n2, n3, n4, n5>>);
    static_assert(is_same<List<n5, n4, n3, n2, n1, n6, n7>,
                          List<n5, n4, n3, n2, n1, n6, n7>>);
    static_assert(is_same<ListReverse_v<List<n1, n2, n3, n4, n5, n6, n7, n8>>,
                          List<n8, n7, n6, n5, n4, n3, n2, n1>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5, n6, n7, n8>,
                          List<n1, n2, n3, n4, n5, n6, n7, n8>>);
    static_assert(
        is_same<ListReverse_v<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>,
                List<n1, n2, n3, n4, n5, n6, n7, n8, n9>>);
    static_assert(is_same<List<n9, n8, n7, n6, n5, n4, n3, n2, n1>,
                          List<n9, n8, n7, n6, n5, n4, n3, n2, n1>>);
} // namespace list_reverse_tests

namespace ListSetImpl
{
    template <List_t L, Any_t Elem, BigUnsigned_t Position>
    struct ListSet;

    template <List_t L, Any_t Elem, BigUnsigned_t Position>
    using ListSet_v = typename ListSet<L, Elem, Position>::result;

    template <Any_t Elem, BigUnsigned_t Position>
    struct ListSet<List<>, Elem, Position>
    {
        static_assert(false, "ListSet: index out of bounds");
    };

    template <Any_t Head, Any_t... Tail, Any_t Elem>
    struct ListSet<List<Head, Tail...>, Elem, BigUnsigned<>>
    {
        using result = List<Elem, Tail...>;
    };

    template <Any_t Head, Any_t... Tail, Any_t Elem, BigUnsigned_t Position>
    struct ListSet<List<Head, Tail...>, Elem, Position>
    {
        using result = ListPrepend_v<
            Head,
            ListSet_v<List<Tail...>, Elem,
                      BigUnsignedSub_v<Position, BigUnsigned<One>>>>;
    };
} // namespace ListSetImpl

using ListSetImpl::ListSet_v;

namespace list_set_tests
{

    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n0>, List<n4, n2, n3>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n1>, List<n1, n4, n3>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n2>, List<n1, n2, n4>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n0>, List<n4, n3, n2>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n1>, List<n2, n4, n2>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n2>, n4, n2>, List<n2, n3, n4>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3>, n4, n1>, List<n1, n4, n3>>);
    static_assert(is_same<List<n1, n2, n3>, List<n1, n2, n3>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n2, n3, n4, n5>, n6, n0>, List<n6, n3, n4, n5>>);
    static_assert(is_same<List<n2, n3, n4, n5>, List<n2, n3, n4, n5>>);
    static_assert(
        is_same<ListSet_v<List<n1, n2, n3, n4>, n5, n3>, List<n1, n2, n3, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4>, List<n1, n2, n3, n4>>);
    static_assert(is_same<ListSet_v<List<n1, n2, n3, n4, n5>, n6, n2>,
                          List<n1, n2, n6, n4, n5>>);
    static_assert(is_same<List<n1, n2, n3, n4, n5>, List<n1, n2, n3, n4, n5>>);
} // namespace list_set_tests

int main(void)
{}
