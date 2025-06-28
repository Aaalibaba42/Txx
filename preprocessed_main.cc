

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
struct Unsigned
{};

template <Bit_t... bits>
void unsigned_t_stub(Unsigned<bits...>);

template <typename T>
concept Unsigned_t = requires(T us) {
    { unsigned_t_stub(us) };
};

namespace ToUnsignedImpl
{
    template <List_t List>
    struct ToUnsigned;

    template <List_t List>
    using ToUnsigned_v = ToUnsigned<List>::result;

    template <Bit_t... Bits>
    struct ToUnsigned<List<Bits...>>
    {
        using result = Unsigned<Bits...>;
    };
} // namespace ToUnsignedImpl

using ToUnsignedImpl::ToUnsigned_v;

namespace UnsignedAddImpl
{
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
        using tail =
            AddUnsignedCarry_v<List<LRest...>, List<>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddUnsignedCarry<List<>, List<R0, RRest...>, Carry>
    {
        using FA = FullAdder<R0, Carry>;
        using tail =
            AddUnsignedCarry_v<List<>, List<RRest...>, typename FA::Carry>;
        using result = ListPrepend_v<typename FA::Sum, tail>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Carry>
    struct AddUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Carry>
    {
        using FA1 = FullAdder<L0, R0>;
        using FA2 = FullAdder<typename FA1::Sum, Carry>;

        using result_carry = FA1::Carry;
        using result_sum = FA2::Sum;
        using next_carry =
            FullAdder<typename FA1::Carry, typename FA2::Carry>::Sum;

        using tail =
            AddUnsignedCarry_v<List<LRest...>, List<RRest...>, next_carry>;
        using result = ListPrepend_v<result_sum, tail>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedAdd;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedAdd_v = UnsignedAdd<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedAdd<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using result =
            ToUnsigned_v<AddUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>;
    };
} // namespace UnsignedAddImpl

using UnsignedAddImpl::UnsignedAdd_v;

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

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

namespace unsigned_add_tests
{
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

namespace UnsignedIncImpl
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

    template <Unsigned_t Num>
    struct UnsignedInc;

    template <Unsigned_t Num>
    using UnsignedInc_v = UnsignedInc<Num>::result;

    template <Bit_t... Bits>
    struct UnsignedInc<Unsigned<Bits...>>
    {
        using result = ToUnsigned_v<AddCarry_v<List<Bits...>, One>>;
    };
} // namespace UnsignedIncImpl

using UnsignedIncImpl::UnsignedInc_v;

namespace ListLengthImpl
{
    template <List_t L>
    struct ListLength;

    template <List_t L>
    using ListLength_v = typename ListLength<L>::result;

    template <>
    struct ListLength<List<>>
    {
        using result = Unsigned<>;
    };

    template <Any_t Head, Any_t... Tail>
    struct ListLength<List<Head, Tail...>>
    {
        using result = UnsignedInc_v<ListLength_v<List<Tail...>>>;
    };
} // namespace ListLengthImpl

using ListLengthImpl::ListLength_v;

namespace UnsignedGEImpl
{
    template <List_t LHS, List_t RHS>
    struct UnsignedGreaterEqImpl;

    template <List_t LHS, List_t RHS>
    using UnsignedGreaterEqImpl_v = UnsignedGreaterEqImpl<LHS, RHS>::result;

    template <>
    struct UnsignedGreaterEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct UnsignedGreaterEqImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<SameBit, LRest...>,
                                 List<SameBit, RRest...>>
    {
        using result = UnsignedGreaterEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct UnsignedGreaterEqImpl<List<L0, LRest...>, List<R0, RRest...>>
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

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedGE;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedGE_v = UnsignedGE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedGE<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            UnsignedGreaterEqImpl_v<ListReverse_v<List<LHS...>>,
                                    ListReverse_v<List<RHS...>>>,

            GEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace UnsignedGEImpl

using UnsignedGEImpl::UnsignedGE_v;

namespace ToListImpl
{
    template <Unsigned_t T>
    struct ToList;

    template <Unsigned_t T>
    using ToList_v = ToList<T>::result;

    template <Bit_t... Bits>
    struct ToList<Unsigned<Bits...>>
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

    template <Unsigned_t Number>
    struct Canonicalize;

    template <Unsigned_t Number>
    using Canonicalize_v = Canonicalize<Number>::result;

    template <Unsigned_t Number>
    struct Canonicalize;

    template <Bit_t... Bits>
    struct Canonicalize<Unsigned<Bits...>>
    {
        using rev = ListReverse_v<List<Bits...>>;
        using stripped = DropLeadingZeros_v<rev>;
        using result_list = ListReverse_v<stripped>;
        using result = ToUnsigned_v<result_list>;
    };
} // namespace CanonicalizeImpl

using CanonicalizeImpl::Canonicalize_v;

namespace UnsignedSubImpl
{
    template <List_t LHS, List_t RHS, Bit_t Borrow>
    struct SubUnsignedCarry;

    template <List_t LHS, List_t RHS, Bit_t Borrow>
    using SubUnsignedCarry_v = SubUnsignedCarry<LHS, RHS, Borrow>::result;

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
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubUnsignedCarry<List<>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<Zero, R0, Borrow>;
        using tail =
            SubUnsignedCarry_v<List<>, List<RRest...>, typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };
    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest, Bit_t Borrow>
    struct SubUnsignedCarry<List<L0, LRest...>, List<R0, RRest...>, Borrow>
    {
        using FS = FullSubtractor<L0, R0, Borrow>;
        using tail = SubUnsignedCarry_v<List<LRest...>, List<RRest...>,
                                        typename FS::Borrow>;
        using result = ListPrepend_v<typename FS::Diff, tail>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedSub;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedSub_v = UnsignedSub<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedSub<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using result = Canonicalize_v<
            ToUnsigned_v<SubUnsignedCarry_v<List<LHS...>, List<RHS...>, Zero>>>;
    };
} // namespace UnsignedSubImpl

using UnsignedSubImpl::UnsignedSub_v;

namespace UnsignedLShiftImpl
{
    template <Unsigned_t Value, Unsigned_t Amount>
    struct UnsignedLShift;

    template <Unsigned_t Value, Unsigned_t Amount>
    using UnsignedLShift_v = UnsignedLShift<Value, Amount>::result;

    template <Unsigned_t Value>
    struct UnsignedLShift<Value, Unsigned<>>
    {
        using result = Value;
    };

    template <Unsigned_t Value, Bit_t... AmountBits>
    struct UnsignedLShift<Value, Unsigned<AmountBits...>>
    {
        using NewBits = ListPrepend_v<Zero, ToList_v<Value>>;
        using ShiftedOnce = ToUnsigned_v<NewBits>;

        using Decrement = UnsignedSub_v<Unsigned<AmountBits...>, Unsigned<One>>;
        using result = Canonicalize_v<UnsignedLShift_v<ShiftedOnce, Decrement>>;
    };
} // namespace UnsignedLShiftImpl

using UnsignedLShiftImpl::UnsignedLShift_v;

namespace UnsignedDivImpl
{
    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    struct UnsignedDivStep;

    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    using UnsignedDivStep_quot =
        UnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::quotient;

    template <List_t BitsMSB, Unsigned_t Divisor, Unsigned_t Remainder,
              List_t QuotientMSB>
    using UnsignedDivStep_rem =
        UnsignedDivStep<BitsMSB, Divisor, Remainder, QuotientMSB>::remainder;

    template <Unsigned_t Divisor, Unsigned_t Remainder, List_t QuotientMSB>
    struct UnsignedDivStep<List<>, Divisor, Remainder, QuotientMSB>
    {
        using quotient = QuotientMSB;
        using remainder = Remainder;
    };

    template <Bit_t B0, Bit_t... BRest, Unsigned_t Divisor,
              Unsigned_t Remainder, List_t QuotientMSB>
    struct UnsignedDivStep<List<B0, BRest...>, Divisor, Remainder, QuotientMSB>
    {
        using Shifted = UnsignedLShift_v<Remainder, Unsigned<One>>;
        using NewRem = UnsignedAdd_v<Shifted, Unsigned<B0>>;

        using UpdatedRem = Ternary_v<UnsignedGE_v<NewRem, Divisor>,
                                     UnsignedSub_v<NewRem, Divisor>, NewRem>;

        using NewQuot =
            ListAppend_v<Ternary_v<UnsignedGE_v<NewRem, Divisor>, One, Zero>,
                         QuotientMSB>;

        using Rec =
            UnsignedDivStep<List<BRest...>, Divisor, UpdatedRem, NewQuot>;

        using quotient = Rec::quotient;
        using remainder = Rec::remainder;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedDivModCommon;

    template <Bit_t... LHSBits>
    struct UnsignedDivModCommon<Unsigned<LHSBits...>, Unsigned<>>
    {
        static_assert(false, "UnsignedModDivCommon: Division by 0");
    };

    template <Bit_t... LHSBits, Bit_t... RHSBits>
    struct UnsignedDivModCommon<Unsigned<LHSBits...>, Unsigned<RHSBits...>>
    {
        using LHSList = List<LHSBits...>;
        using RHSNum = Unsigned<RHSBits...>;
        using LHSBitsMSB = ListReverse_v<LHSList>;

        using Quotient = ListReverse_v<
            UnsignedDivStep_quot<LHSBitsMSB, RHSNum, Unsigned<>, List<>>>;

        using DivStep = UnsignedDivStep<LHSBitsMSB, RHSNum, Unsigned<>, List<>>;

        using remainder = Canonicalize_v<typename DivStep::remainder>;
        using quotient = Canonicalize_v<
            ToUnsigned_v<ListReverse_v<typename DivStep::quotient>>>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedDiv_v = UnsignedDivModCommon<LHS, RHS>::quotient;
} // namespace UnsignedDivImpl

using UnsignedDivImpl::UnsignedDiv_v;

namespace unsigned_div_tests
{

    static_assert(is_same<UnsignedDiv_v<n1, n2>, n0>);
    static_assert(is_same<UnsignedDiv_v<n5, n5>, n1>);
    static_assert(is_same<UnsignedDiv_v<n10, n2>, n5>);
    static_assert(is_same<UnsignedDiv_v<n10, n1>, n10>);
    static_assert(is_same<UnsignedDiv_v<n0, n5>, n0>);
    static_assert(is_same<UnsignedDiv_v<n20, n4>, n5>);
    static_assert(is_same<UnsignedDiv_v<n50, n10>, n5>);
    static_assert(is_same<UnsignedDiv_v<n64, n2>, n32>);
    static_assert(is_same<UnsignedDiv_v<n25, n3>, n8>);
    static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
    static_assert(is_same<UnsignedDiv_v<n50, n25>, n2>);
    static_assert(is_same<UnsignedDiv_v<n64, n63>, n1>);
    static_assert(is_same<UnsignedDiv_v<n64, n16>, n4>);
    static_assert(is_same<UnsignedDiv_v<n15, n1>, n15>);
    static_assert(is_same<UnsignedDiv_v<n10, n3>, n3>);
    static_assert(is_same<UnsignedDiv_v<n64, n64>, n1>);
    static_assert(is_same<UnsignedDiv_v<n30, n7>, n4>);
    static_assert(is_same<UnsignedDiv_v<n17, n5>, n3>);
    static_assert(is_same<UnsignedDiv_v<n50, n26>, n1>);
    static_assert(is_same<UnsignedDiv_v<n50, n24>, n2>);
    static_assert(is_same<UnsignedDiv_v<n1, n64>, n0>);
    static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
    static_assert(is_same<UnsignedDiv_v<n10, n20>, n0>);
    static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
} // namespace unsigned_div_tests

namespace UnsignedEQImpl
{
    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedEQ;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedEQ_v = UnsignedEQ<LHS, RHS>::result;

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedEQ
    {
        using result = IsSame_v<LHS, RHS>;
    };
} // namespace UnsignedEQImpl

using UnsignedEQImpl::UnsignedEQ_v;

namespace unsigned_eq_tests
{
    static_assert(is_same<UnsignedEQ_v<n1, n1>, True>);
    static_assert(is_same<UnsignedEQ_v<n1, n2>, False>);
    static_assert(is_same<UnsignedEQ_v<n5, n5>, True>);
    static_assert(is_same<UnsignedEQ_v<n5, n6>, False>);
    static_assert(is_same<UnsignedEQ_v<n10, n10>, True>);
    static_assert(is_same<UnsignedEQ_v<n10, n11>, False>);
    static_assert(is_same<UnsignedEQ_v<n0, n0>, True>);
    static_assert(is_same<UnsignedEQ_v<n1, n0>, False>);
    static_assert(is_same<UnsignedEQ_v<n64, n64>, True>);
    static_assert(is_same<UnsignedEQ_v<n64, n63>, False>);
    static_assert(is_same<UnsignedEQ_v<n32, n32>, True>);
    static_assert(is_same<UnsignedEQ_v<n32, n33>, False>);
    static_assert(is_same<UnsignedEQ_v<n1, n1>, True>);
    static_assert(is_same<UnsignedEQ_v<n1, n2>, False>);
    static_assert(is_same<UnsignedEQ_v<n10, n10>, True>);
    static_assert(is_same<UnsignedEQ_v<n10, n20>, False>);
} // namespace unsigned_eq_tests

namespace unsigned_ge_tests
{
    static_assert(is_same<UnsignedGE_v<n1, n2>, False>);
    static_assert(is_same<UnsignedGE_v<n1, n1>, True>);
    static_assert(is_same<UnsignedGE_v<n2, n1>, True>);
    static_assert(is_same<UnsignedGE_v<n10, n20>, False>);
    static_assert(is_same<UnsignedGE_v<n10, n10>, True>);
    static_assert(is_same<UnsignedGE_v<n20, n10>, True>);
    static_assert(is_same<UnsignedGE_v<n63, n64>, False>);
    static_assert(is_same<UnsignedGE_v<n64, n63>, True>);
    static_assert(is_same<UnsignedGE_v<n50, n60>, False>);
    static_assert(is_same<UnsignedGE_v<n50, n50>, True>);
    static_assert(is_same<UnsignedGE_v<n60, n50>, True>);
    static_assert(is_same<UnsignedGE_v<n0, n1>, False>);
    static_assert(is_same<UnsignedGE_v<n0, n0>, True>);
    static_assert(is_same<UnsignedGE_v<n1, n0>, True>);
    static_assert(is_same<UnsignedGE_v<n64, n64>, True>);
    static_assert(is_same<UnsignedGE_v<n10, n30>, False>);
    static_assert(is_same<UnsignedGE_v<n30, n10>, True>);
    static_assert(is_same<UnsignedGE_v<n32, n33>, False>);
    static_assert(is_same<UnsignedGE_v<n33, n33>, True>);
    static_assert(is_same<UnsignedGE_v<n33, n32>, True>);
} // namespace unsigned_ge_tests

namespace UnsignedGTImpl
{
    template <List_t LHS, List_t RHS>
    struct UnsignedGreaterThanImpl;

    template <List_t LHS, List_t RHS>
    using UnsignedGreaterThanImpl_v = UnsignedGreaterThanImpl<LHS, RHS>::result;

    template <>
    struct UnsignedGreaterThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct UnsignedGreaterThanImpl<List<>, List<RRest...>>
    {
        using result = False;
    };

    template <Bit_t... LRest>
    struct UnsignedGreaterThanImpl<List<LRest...>, List<>>
    {
        using result = True;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct UnsignedGreaterThanImpl<List<SameBit, LRest...>,
                                   List<SameBit, RRest...>>
    {
        using result =
            UnsignedGreaterThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct UnsignedGreaterThanImpl<List<L0, LRest...>, List<R0, RRest...>>
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

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedGT;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedGT_v = UnsignedGT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedGT<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            UnsignedGreaterThanImpl_v<ListReverse_v<List<LHS...>>,
                                      ListReverse_v<List<RHS...>>>,

            GTImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace UnsignedGTImpl

using UnsignedGTImpl::UnsignedGT_v;

namespace unsigned_gt_tests
{
    static_assert(is_same<UnsignedGT_v<n1, n2>, False>);
    static_assert(is_same<UnsignedGT_v<n1, n1>, False>);
    static_assert(is_same<UnsignedGT_v<n2, n1>, True>);
    static_assert(is_same<UnsignedGT_v<n10, n20>, False>);
    static_assert(is_same<UnsignedGT_v<n10, n10>, False>);
    static_assert(is_same<UnsignedGT_v<n20, n10>, True>);
    static_assert(is_same<UnsignedGT_v<n63, n64>, False>);
    static_assert(is_same<UnsignedGT_v<n64, n63>, True>);
    static_assert(is_same<UnsignedGT_v<n50, n60>, False>);
    static_assert(is_same<UnsignedGT_v<n50, n50>, False>);
    static_assert(is_same<UnsignedGT_v<n60, n50>, True>);
    static_assert(is_same<UnsignedGT_v<n0, n1>, False>);
    static_assert(is_same<UnsignedGT_v<n0, n0>, False>);
    static_assert(is_same<UnsignedGT_v<n1, n0>, True>);
    static_assert(is_same<UnsignedGT_v<n64, n64>, False>);
    static_assert(is_same<UnsignedGT_v<n10, n30>, False>);
    static_assert(is_same<UnsignedGT_v<n30, n10>, True>);
    static_assert(is_same<UnsignedGT_v<n32, n33>, False>);
    static_assert(is_same<UnsignedGT_v<n33, n33>, False>);
    static_assert(is_same<UnsignedGT_v<n33, n32>, True>);
} // namespace unsigned_gt_tests

namespace unsigned_increment_tests
{
    using N0 = n0;
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
} // namespace unsigned_increment_tests

namespace UnsignedLEImpl
{
    template <List_t LHS, List_t RHS>
    struct UnsignedLowerEqImpl;

    template <List_t LHS, List_t RHS>
    using UnsignedLowerEqImpl_v = UnsignedLowerEqImpl<LHS, RHS>::result;

    template <>
    struct UnsignedLowerEqImpl<List<>, List<>>
    {
        using result = True;
    };

    template <Bit_t... RRest>
    struct UnsignedLowerEqImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct UnsignedLowerEqImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct UnsignedLowerEqImpl<List<SameBit, LRest...>, List<SameBit, RRest...>>
    {
        using result = UnsignedLowerEqImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct UnsignedLowerEqImpl<List<L0, LRest...>, List<R0, RRest...>>
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

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedLE;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedLE_v = UnsignedLE<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedLE<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            UnsignedLowerEqImpl_v<ListReverse_v<List<LHS...>>,
                                  ListReverse_v<List<RHS...>>>,

            LEImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace UnsignedLEImpl

using UnsignedLEImpl::UnsignedLE_v;

namespace unsigned_le_tests
{
    static_assert(is_same<UnsignedLE_v<n1, n2>, True>);
    static_assert(is_same<UnsignedLE_v<n1, n1>, True>);
    static_assert(is_same<UnsignedLE_v<n2, n1>, False>);
    static_assert(is_same<UnsignedLE_v<n10, n20>, True>);
    static_assert(is_same<UnsignedLE_v<n10, n10>, True>);
    static_assert(is_same<UnsignedLE_v<n20, n10>, False>);
    static_assert(is_same<UnsignedLE_v<n63, n64>, True>);
    static_assert(is_same<UnsignedLE_v<n64, n63>, False>);
    static_assert(is_same<UnsignedLE_v<n50, n60>, True>);
    static_assert(is_same<UnsignedLE_v<n50, n50>, True>);
    static_assert(is_same<UnsignedLE_v<n60, n50>, False>);
    static_assert(is_same<UnsignedLE_v<n0, n1>, True>);
    static_assert(is_same<UnsignedLE_v<n0, n0>, True>);
    static_assert(is_same<UnsignedLE_v<n1, n0>, False>);
    static_assert(is_same<UnsignedLE_v<n64, n64>, True>);
    static_assert(is_same<UnsignedLE_v<n10, n30>, True>);
    static_assert(is_same<UnsignedLE_v<n30, n10>, False>);
    static_assert(is_same<UnsignedLE_v<n32, n33>, True>);
    static_assert(is_same<UnsignedLE_v<n33, n33>, True>);
    static_assert(is_same<UnsignedLE_v<n33, n32>, False>);
} // namespace unsigned_le_tests

namespace unsigned_lshift_tests
{
    static_assert(is_same<UnsignedLShift_v<n1, n0>, n1>);
    static_assert(is_same<UnsignedLShift_v<n1, n1>, n2>);
    static_assert(is_same<UnsignedLShift_v<n2, n2>, n8>);
    static_assert(is_same<UnsignedLShift_v<n3, n3>, n24>);
    static_assert(is_same<UnsignedLShift_v<n4, n1>, n8>);
    static_assert(is_same<UnsignedLShift_v<n5, n2>, n20>);
    static_assert(is_same<UnsignedLShift_v<n6, n1>, n12>);
    static_assert(is_same<UnsignedLShift_v<n7, n2>, n28>);
    static_assert(is_same<UnsignedLShift_v<n8, n1>, n16>);
    static_assert(is_same<UnsignedLShift_v<n9, n2>, n36>);
    static_assert(is_same<UnsignedLShift_v<n10, n1>, n20>);
    static_assert(is_same<UnsignedLShift_v<n0, n5>, n0>);
    static_assert(is_same<UnsignedLShift_v<n1, n3>, n8>);
    static_assert(is_same<UnsignedLShift_v<n2, n1>, n4>);
    static_assert(is_same<UnsignedLShift_v<n3, n2>, n12>);
    static_assert(is_same<UnsignedLShift_v<n4, n3>, n32>);
    static_assert(is_same<UnsignedLShift_v<n5, n1>, n10>);
    static_assert(is_same<UnsignedLShift_v<n6, n2>, n24>);
    static_assert(is_same<UnsignedLShift_v<n7, n1>, n14>);
    static_assert(is_same<UnsignedLShift_v<n8, n2>, n32>);
    static_assert(is_same<UnsignedLShift_v<n1, n4>, n16>);
} // namespace unsigned_lshift_tests

namespace UnsignedLTImpl
{

    template <List_t LHS, List_t RHS>
    struct UnsignedLowerThanImpl;

    template <List_t LHS, List_t RHS>
    using UnsignedLowerThanImpl_v = UnsignedLowerThanImpl<LHS, RHS>::result;

    template <>
    struct UnsignedLowerThanImpl<List<>, List<>>
    {
        using result = False;
    };

    template <Bit_t... RRest>
    struct UnsignedLowerThanImpl<List<>, List<RRest...>>
    {
        using result = True;
    };

    template <Bit_t... LRest>
    struct UnsignedLowerThanImpl<List<LRest...>, List<>>
    {
        using result = False;
    };

    template <Bit_t SameBit, Bit_t... LRest, Bit_t... RRest>
    struct UnsignedLowerThanImpl<List<SameBit, LRest...>,
                                 List<SameBit, RRest...>>
    {
        using result = UnsignedLowerThanImpl_v<List<LRest...>, List<RRest...>>;
    };

    template <Bit_t L0, Bit_t... LRest, Bit_t R0, Bit_t... RRest>
    struct UnsignedLowerThanImpl<List<L0, LRest...>, List<R0, RRest...>>
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

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedLT;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedLT_v = UnsignedLT<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedLT<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using LList = List<LHS...>;
        using RList = List<RHS...>;
        using result = Ternary_v<

            IsSame_v<ListLength_v<LList>, ListLength_v<RList>>,

            UnsignedLowerThanImpl_v<ListReverse_v<List<LHS...>>,
                                    ListReverse_v<List<RHS...>>>,

            LTImplIsLHSLongest_v<LList, RList>>;
    };
} // namespace UnsignedLTImpl

using UnsignedLTImpl::UnsignedLT_v;

namespace unsigned_lt_tests
{
    static_assert(is_same<UnsignedLT_v<n1, n2>, True>);
    static_assert(is_same<UnsignedLT_v<n1, n1>, False>);
    static_assert(is_same<UnsignedLT_v<n2, n1>, False>);
    static_assert(is_same<UnsignedLT_v<n10, n20>, True>);
    static_assert(is_same<UnsignedLT_v<n10, n10>, False>);
    static_assert(is_same<UnsignedLT_v<n20, n10>, False>);
    static_assert(is_same<UnsignedLT_v<n63, n64>, True>);
    static_assert(is_same<UnsignedLT_v<n64, n63>, False>);
    static_assert(is_same<UnsignedLT_v<n50, n60>, True>);
    static_assert(is_same<UnsignedLT_v<n50, n50>, False>);
    static_assert(is_same<UnsignedLT_v<n60, n50>, False>);
    static_assert(is_same<UnsignedLT_v<n0, n1>, True>);
    static_assert(is_same<UnsignedLT_v<n0, n0>, False>);
    static_assert(is_same<UnsignedLT_v<n1, n0>, False>);
    static_assert(is_same<UnsignedLT_v<n64, n64>, False>);
    static_assert(is_same<UnsignedLT_v<n10, n30>, True>);
    static_assert(is_same<UnsignedLT_v<n30, n10>, False>);
    static_assert(is_same<UnsignedLT_v<n32, n33>, True>);
    static_assert(is_same<UnsignedLT_v<n33, n33>, False>);
    static_assert(is_same<UnsignedLT_v<n33, n32>, False>);
} // namespace unsigned_lt_tests

namespace UnsignedModImpl
{
    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedMod_v =
        UnsignedDivImpl::UnsignedDivModCommon<LHS, RHS>::remainder;
}

using UnsignedModImpl::UnsignedMod_v;

namespace unsigned_mod_tests
{

    static_assert(is_same<UnsignedMod_v<n1, n2>, n1>);
    static_assert(is_same<UnsignedMod_v<n5, n5>, n0>);
    static_assert(is_same<UnsignedMod_v<n10, n2>, n0>);
    static_assert(is_same<UnsignedMod_v<n10, n1>, n0>);
    static_assert(is_same<UnsignedMod_v<n0, n5>, n0>);
    static_assert(is_same<UnsignedMod_v<n20, n4>, n0>);
    static_assert(is_same<UnsignedMod_v<n50, n10>, n0>);
    static_assert(is_same<UnsignedMod_v<n64, n2>, n0>);
    static_assert(is_same<UnsignedMod_v<n25, n3>, n1>);
    static_assert(is_same<UnsignedMod_v<n64, n1>, n0>);
    static_assert(is_same<UnsignedMod_v<n50, n25>, n0>);
    static_assert(is_same<UnsignedMod_v<n64, n63>, n1>);
    static_assert(is_same<UnsignedMod_v<n64, n16>, n0>);
    static_assert(is_same<UnsignedMod_v<n15, n16>, n15>);
    static_assert(is_same<UnsignedMod_v<n10, n3>, n1>);
    static_assert(is_same<UnsignedMod_v<n64, n64>, n0>);
    static_assert(is_same<UnsignedMod_v<n30, n7>, n2>);
    static_assert(is_same<UnsignedMod_v<n17, n5>, n2>);
    static_assert(is_same<UnsignedMod_v<n50, n26>, n24>);
    static_assert(is_same<UnsignedMod_v<n50, n24>, n2>);
    static_assert(is_same<UnsignedMod_v<n1, n64>, n1>);
    static_assert(is_same<UnsignedMod_v<n33, n32>, n1>);
    static_assert(is_same<UnsignedMod_v<n10, n9>, n1>);
    static_assert(is_same<UnsignedMod_v<n64, n1>, n0>);
} // namespace unsigned_mod_tests

namespace UnsignedMulImpl
{
    template <Unsigned_t LHS, Bit_t RHS, Unsigned_t Shift>
    struct MulByBit;

    template <Unsigned_t LHS, Bit_t RHS, Unsigned_t Shift>
    using MulByBit_v = MulByBit<LHS, RHS, Shift>::result;

    template <Unsigned_t LHS, Unsigned_t Shift>
    struct MulByBit<LHS, Zero, Shift>
    {
        using result = Unsigned<>;
    };

    template <Unsigned_t LHS, Unsigned_t Shift>
    struct MulByBit<LHS, One, Shift>
    {
        using result = UnsignedLShift_v<LHS, Shift>;
    };

    template <Unsigned_t LHS, List_t BList, Unsigned_t Shift>
    struct UnsignedMulHelper;

    template <Unsigned_t LHS, List_t BList, Unsigned_t Shift>
    using UnsignedMulHelper_v = UnsignedMulHelper<LHS, BList, Shift>::result;

    template <Unsigned_t LHS, Unsigned_t Shift>
    struct UnsignedMulHelper<LHS, List<>, Shift>
    {
        using result = Unsigned<>;
    };

    template <Bit_t R0, Bit_t... RRest, Unsigned_t LHS, Unsigned_t Shift>
    struct UnsignedMulHelper<LHS, List<R0, RRest...>, Shift>
    {
        using partial = MulByBit_v<LHS, R0, Shift>;
        using rest =
            UnsignedMulHelper_v<LHS, List<RRest...>, UnsignedInc_v<Shift>>;
        using result = UnsignedAdd_v<partial, rest>;
    };

    template <Unsigned_t LHS, Unsigned_t RHS>
    struct UnsignedMul;

    template <Unsigned_t LHS, Unsigned_t RHS>
    using UnsignedMul_v = UnsignedMul<LHS, RHS>::result;

    template <Bit_t... LHS, Bit_t... RHS>
    struct UnsignedMul<Unsigned<LHS...>, Unsigned<RHS...>>
    {
        using result = Canonicalize_v<
            UnsignedMulHelper_v<Unsigned<LHS...>, List<RHS...>, Unsigned<>>>;
    };
} // namespace UnsignedMulImpl

using UnsignedMulImpl::UnsignedMul_v;

namespace unsigned_mul_tests
{
    using M0 = UnsignedMul_v<n0, n1>;
    using M1 = UnsignedMul_v<n1, n1>;
    using M0_1 = UnsignedMul_v<n0, n0>;
    using M4 = UnsignedMul_v<n2, n2>;
    using M6 = UnsignedMul_v<n2, n3>;
    using M8 = UnsignedMul_v<n2, n4>;
    using M10 = UnsignedMul_v<n2, n5>;
    using M12 = UnsignedMul_v<n3, n4>;
    using M14 = UnsignedMul_v<n2, n7>;
    using M15 = UnsignedMul_v<n3, n5>;
    using M16 = UnsignedMul_v<n4, n4>;
    using M18 = UnsignedMul_v<n3, n6>;
    using M20 = UnsignedMul_v<n4, n5>;
    using M21 = UnsignedMul_v<n3, n7>;
    using M24 = UnsignedMul_v<n3, n8>;
    using M25 = UnsignedMul_v<n5, n5>;
    using M27 = UnsignedMul_v<n3, n9>;
    using M28 = UnsignedMul_v<n4, n7>;
    using M30 = UnsignedMul_v<n5, n6>;
    using M32 = UnsignedMul_v<n4, n8>;
    using M35 = UnsignedMul_v<n5, n7>;
    using M36 = UnsignedMul_v<n4, n9>;
    using M40 = UnsignedMul_v<n5, n8>;
    using M42 = UnsignedMul_v<n6, n7>;
    using M45 = UnsignedMul_v<n5, n9>;
    using M48 = UnsignedMul_v<n6, n8>;
    using M49 = UnsignedMul_v<n7, n7>;
    using M54 = UnsignedMul_v<n6, n9>;
    using M56 = UnsignedMul_v<n7, n8>;
    using M63 = UnsignedMul_v<n7, n9>;
    using M64 = UnsignedMul_v<n8, n8>;

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
    using S0_1 = UnsignedSub_v<n1, n1>;
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
    using S12 = UnsignedSub_v<n27, n15>;
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
    template <List_t L, Any_t Elem, Unsigned_t Position>
    struct ListSet;

    template <List_t L, Any_t Elem, Unsigned_t Position>
    using ListSet_v = typename ListSet<L, Elem, Position>::result;

    template <Any_t Elem, Unsigned_t Position>
    struct ListSet<List<>, Elem, Position>
    {
        static_assert(false, "ListSet: index out of bounds");
    };

    template <Any_t Head, Any_t... Tail, Any_t Elem>
    struct ListSet<List<Head, Tail...>, Elem, Unsigned<>>
    {
        using result = List<Elem, Tail...>;
    };

    template <Any_t Head, Any_t... Tail, Any_t Elem, Unsigned_t Position>
    struct ListSet<List<Head, Tail...>, Elem, Position>
    {
        using result =
            ListPrepend_v<Head,
                          ListSet_v<List<Tail...>, Elem,
                                    UnsignedSub_v<Position, Unsigned<One>>>>;
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
