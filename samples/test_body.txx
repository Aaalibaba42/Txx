// This is for testing features during development

using Double = Curry_v<Unsigned8MulFunc, u8_2>;
using IncThenDouble = Combine_v<Unsigned8IncFunc, Double>;

using r1 = AssertEq<Apply_v<IncThenDouble, u8_0>, u8_2>::result;
using r2 = AssertEq<Apply_v<IncThenDouble, u8_1>, u8_4>::result;
using r3 = AssertEq<Apply_v<IncThenDouble, u8_2>, u8_6>::result;
using r4 = AssertEq<Apply_v<IncThenDouble, u8_3>, u8_8>::result;
