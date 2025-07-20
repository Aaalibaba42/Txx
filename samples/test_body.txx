// This is for testing features during development

using Add2 = Curry_v<Unsigned8AddFunc, u8_2>;
using maybe6 = Apply_v<Add2, u8_4>;

using result = AssertEq<maybe6, u8_6>::result;
