// This is for testing features during development

template <Any_t N1, Any_t N2>
struct Ge
{};

template <Any_t buN1, Any_t buN2>
    requires BigUnsigned_t<buN1> && BigUnsigned_t<buN2>
struct Ge<buN1, buN2>
{
    using result = BigUnsignedGE_v<buN1, buN2>;
};

template <Any_t u8N1, Any_t u8N2>
    requires Unsigned8_t<u8N1> && Unsigned8_t<u8N2>
struct Ge<u8N1, u8N2>
{
    using result = Unsigned8GE_v<u8N1, u8N2>;
};

template <Any_t N1, Any_t N2>
using Ge_v = Ge<N1, N2>::result;
