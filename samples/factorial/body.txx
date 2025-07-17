// Don't forget there in the Input value that exist, since this included in the
// main function

using r0 = AssertEq<Factorial_v<bu0>, bu1>::result;
using r1 = AssertEq<Factorial_v<bu1>, bu1>::result;
using r2 = AssertEq<Factorial_v<bu2>, bu2>::result;
using r3 = AssertEq<Factorial_v<bu3>, bu6>::result;
using r4 = AssertEq<Factorial_v<bu4>, bu24>::result;
using r5 = AssertEq<Factorial_v<bu5>, bu120>::result;

using r6 = Assert<BigUnsignedGE_v<Factorial_v<Input>, bu120>>::result;

using result = Unit;
