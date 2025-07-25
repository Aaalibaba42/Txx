// Declaration
template <BigUnsigned_t Input>
struct Factorial;

// Alias to get return of the function directly
template <BigUnsigned_t Input>
using Factorial_v = Factorial<Input>::result;

// At 0, result is 1
template <>
struct Factorial<bu0>
{
    using result = bu1;
};

// Otherwise, result is current multiplied with decremented Num
template <BigUnsigned_t Num>
struct Factorial
{
    using result = Mul_v<Num, Factorial_v<Sub_v<Num, bu1>>>;
};
