// Declaration
template <BigUnsigned_t N>
struct Fibonacci;

// Alias to get return of the function directly
template <BigUnsigned_t N>
using Fibonacci_v = Fibonacci<N>::result;

// Fib(0) = 0
template <>
struct Fibonacci<bu0>
{
    using result = bu0;
};

// Fib(1) = 1
template <>
struct Fibonacci<bu1>
{
    using result = bu1;
};

// Fib(n) = Fib(n-1) + Fib(n-2)
template <BigUnsigned_t N>
struct Fibonacci
{
    using result =
        Add_v<Fibonacci_v<Dec_v<N>>, Fibonacci_v<Sub_v<N, bu2>>>;
};
