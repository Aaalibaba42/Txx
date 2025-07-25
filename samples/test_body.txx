// This is for testing features during development

using r1 = AssertEq<Apply_t<GeFunc, u8_30, u8_50>,
                    Apply_t<GeFunc, bu30, bu50>>::result;
using r2 = AssertEq<Ge_v<u8_1, u8_2>, Ge_v<bu1, bu2>>::result;

using result = Unit;
