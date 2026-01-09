using t0 = AssertEq<InsertionSort_v<List<>>, List<>>::result;
using t1 = AssertEq<InsertionSort_v<List<bu5>>, List<bu5>>::result;
using t2 = AssertEq<InsertionSort_v<List<bu1, bu2>>, List<bu1, bu2>>::result;
using t3 = AssertEq<InsertionSort_v<List<bu5, bu3>>, List<bu3, bu5>>::result;
using t4 =
    AssertEq<InsertionSort_v<List<bu3, bu1, bu2>>, List<bu1, bu2, bu3>>::result;
using t5 =
    AssertEq<InsertionSort_v<List<bu3, bu2, bu1>>, List<bu1, bu2, bu3>>::result;
using t6 = AssertEq<InsertionSort_v<List<bu5, bu2, bu8, bu1, bu9, bu3>>,
                    List<bu1, bu2, bu3, bu5, bu8, bu9>>::result;
using t7 = AssertEq<InsertionSort_v<List<bu3, bu1, bu3, bu2, bu1>>,
                    List<bu1, bu1, bu2, bu3, bu3>>::result;

// Explicit LeFunc comparator - ascending order
using t8 = AssertEq<InsertionSortWith_v<LeFunc, List<bu3, bu1, bu2>>,
                    List<bu1, bu2, bu3>>::result;

// GeFunc comparator - descending order
using t9 = AssertEq<InsertionSortWith_v<GeFunc, List<bu3, bu1, bu2>>,
                    List<bu3, bu2, bu1>>::result;
using t10 =
    AssertEq<InsertionSortWith_v<GeFunc, List<bu5, bu2, bu8, bu1, bu9, bu3>>,
             List<bu9, bu8, bu5, bu3, bu2, bu1>>::result;

using result = Unit;
