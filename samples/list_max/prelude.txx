struct ChooseFunc
{
    using is_function = IsFunction;

    template <Function_t Cmp, BigUnsigned_t A, BigUnsigned_t B>
    struct apply
    {
        using result = Ternary_v<Apply_v<Cmp, A, B>, A, B>;
    };
};

template <Function_t Cmp, BigUnsigned_t A, BigUnsigned_t B>
using Choose_v = Apply_v<ChooseFunc, Cmp, A, B>;

template <BigUnsigned_t A, BigUnsigned_t B>
using Max_v = Choose_v<GeFunc, A, B>;

template <BigUnsigned_t A, BigUnsigned_t B>
using Min_v = Choose_v<LeFunc, A, B>;

// Find extremum using FoldL with curried comparator
template <Function_t Cmp, List_t L>
struct ListExtremum;

template <Function_t Cmp, List_t L>
using ListExtremum_v = ListExtremum<Cmp, L>::result;

template <Function_t Cmp, BigUnsigned_t Head, BigUnsigned_t... Tail>
struct ListExtremum<Cmp, List<Head, Tail...>>
{
    using CmpFunc = Curry_v<ChooseFunc, Cmp>;
    using result = FoldL_v<CmpFunc, Head, List<Tail...>>;
};

template <List_t L>
using ListMax_v = ListExtremum_v<GeFunc, L>;

template <List_t L>
using ListMin_v = ListExtremum_v<LeFunc, L>;

template <List_t L>
using Sum_v = FoldL_v<AddFunc, bu0, L>;

// Generic reduce is just an alias for FoldL
template <Function_t Op, Any_t Init, List_t L>
using Reduce_v = FoldL_v<Op, Init, L>;
