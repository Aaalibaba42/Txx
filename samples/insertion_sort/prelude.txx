// Insert an element into a sorted list at the correct position
template <Function_t Cmp, BigUnsigned_t Elem, List_t SortedList>
struct Insert;

template <Function_t Cmp, BigUnsigned_t Elem, List_t SortedList>
using Insert_v = Insert<Cmp, Elem, SortedList>::result;

template <Function_t Cmp, BigUnsigned_t Elem>
struct Insert<Cmp, Elem, List<>>
{
    using result = List<Elem>;
};

template <Function_t Cmp, BigUnsigned_t Elem, BigUnsigned_t Head, BigUnsigned_t... Tail>
struct Insert<Cmp, Elem, List<Head, Tail...>>
{
    using later = Prepend_v<Head, Insert_v<Cmp, Elem, List<Tail...>>>;
    using result = Ternary_v<
    // if
        Apply_v<Cmp, Elem, Head>,
    // then
        List<Elem, Head, Tail...>,
    // else
        later
    >;
};

// Sort back-to-front, inserting the element of the head-list to the correct
// position in the (sorted) back-list each iteration
template <Function_t Cmp, List_t L>
struct InsertionSortWith;

template <Function_t Cmp, List_t L>
using InsertionSortWith_v = InsertionSortWith<Cmp, L>::result;

template <Function_t Cmp>
struct InsertionSortWith<Cmp, List<>>
{
    using result = List<>;
};

template <Function_t Cmp, BigUnsigned_t Head, BigUnsigned_t... Tail>
struct InsertionSortWith<Cmp, List<Head, Tail...>>
{
    // This recurses all the way down to empty list, so recursion-tail is
    // sorted back-list and insert at the correct place 1-by-1 back up
    using sorted_tail = InsertionSortWith_v<Cmp, List<Tail...>>;
    using result = Insert_v<Cmp, Head, sorted_tail>;
};

// Default version using LeFunc
template <List_t L>
using InsertionSort_v = InsertionSortWith_v<LeFunc, L>;
