namespace FactorialImpl
{
    template <BigUnsigned_t Input>
    struct Factorial;

    template <BigUnsigned_t Input>
    using Factorial_v = Factorial<Input>::result;

    template <>
    struct Factorial<bu0>
    {
        using result = bu1;
    };

    template <BigUnsigned_t Num>
    struct Factorial
    {
        using result =
            BigUnsignedMul_v<Num, Factorial_v<BigUnsignedSub_v<Num, bu1>>>;
    };

    struct FactorialFunc
    {
        template <BigUnsigned_t Input>
        struct apply
        {
            using result = Factorial_v<Input>;
        };
    };
} // namespace FactorialImpl

using FactorialImpl::Factorial_v;
