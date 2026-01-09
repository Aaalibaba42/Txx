using f0 = AssertEq<Fibonacci_v<bu0>, bu0>::result;
using f1 = AssertEq<Fibonacci_v<bu1>, bu1>::result;
using f2 = AssertEq<Fibonacci_v<bu2>, bu1>::result;
using f3 = AssertEq<Fibonacci_v<bu3>, bu2>::result;
using f4 = AssertEq<Fibonacci_v<bu4>, bu3>::result;
using f5 = AssertEq<Fibonacci_v<bu5>, bu5>::result;
using f6 = AssertEq<Fibonacci_v<bu6>, bu8>::result;
using f7 = AssertEq<Fibonacci_v<bu7>, bu13>::result;
using f8 = AssertEq<Fibonacci_v<bu8>, bu21>::result;
using f9 = AssertEq<Fibonacci_v<bu9>, bu34>::result;
using f10 = AssertEq<Fibonacci_v<bu10>, bu55>::result;
using f11 = AssertEq<Fibonacci_v<bu11>, bu89>::result;

using result = Fibonacci_v<Input>;
