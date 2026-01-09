using max2_t1 = AssertEq<Max_v<bu5, bu3>, bu5>::result;
using max2_t2 = AssertEq<Max_v<bu3, bu5>, bu5>::result;
using max2_t3 = AssertEq<Max_v<bu7, bu7>, bu7>::result;

using min2_t1 = AssertEq<Min_v<bu5, bu3>, bu3>::result;
using min2_t2 = AssertEq<Min_v<bu3, bu5>, bu3>::result;
using min2_t3 = AssertEq<Min_v<bu7, bu7>, bu7>::result;

using ext_t1 = AssertEq<Choose_v<GeFunc, bu5, bu3>, bu5>::result;
using ext_t2 = AssertEq<Choose_v<LeFunc, bu5, bu3>, bu3>::result;

using lmax_t1 = AssertEq<ListMax_v<List<bu42>>, bu42>::result;
using lmax_t2 = AssertEq<ListMax_v<List<bu3, bu7>>, bu7>::result;
using lmax_t3 = AssertEq<ListMax_v<List<bu9, bu4>>, bu9>::result;
using lmax_t4 = AssertEq<ListMax_v<List<bu1, bu5, bu3, bu2>>, bu5>::result;
using lmax_t5 = AssertEq<ListMax_v<List<bu10, bu5, bu3, bu2>>, bu10>::result;
using lmax_t6 = AssertEq<ListMax_v<List<bu1, bu5, bu3, bu20>>, bu20>::result;

using lmin_t1 = AssertEq<ListMin_v<List<bu42>>, bu42>::result;
using lmin_t2 = AssertEq<ListMin_v<List<bu3, bu7>>, bu3>::result;
using lmin_t3 = AssertEq<ListMin_v<List<bu9, bu4>>, bu4>::result;
using lmin_t4 = AssertEq<ListMin_v<List<bu5, bu1, bu3, bu2>>, bu1>::result;
using lmin_t5 = AssertEq<ListMin_v<List<bu1, bu5, bu3, bu2>>, bu1>::result;
using lmin_t6 = AssertEq<ListMin_v<List<bu10, bu5, bu3, bu2>>, bu2>::result;

using lext_t1 =
    AssertEq<ListExtremum_v<GeFunc, List<bu1, bu5, bu3>>, bu5>::result;
using lext_t2 =
    AssertEq<ListExtremum_v<LeFunc, List<bu1, bu5, bu3>>, bu1>::result;

using sum_t1 = AssertEq<Sum_v<List<>>, bu0>::result;
using sum_t2 = AssertEq<Sum_v<List<bu5>>, bu5>::result;
using sum_t3 = AssertEq<Sum_v<List<bu1, bu2, bu3>>, bu6>::result;
using sum_t4 = AssertEq<Sum_v<List<bu10, bu20, bu30>>, bu60>::result;

using red_t1 =
    AssertEq<Reduce_v<MulFunc, bu1, List<bu2, bu3, bu4>>, bu24>::result;

using result = Unit;
