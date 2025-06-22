#include "txx/types/bits/literals.hh"
#include "txx/types/numbers/unsigned/unsigned.hh"
#include "txx/types/numbers/unsigned/ops/inc.hh"

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using n0 = Unsigned<>;
    using n1 = Unsigned<One>;
    using n2 = Unsigned<Zero, One>;
    using n3 = Unsigned<One, One>;
    using n4 = Unsigned<Zero, Zero, One>;
    using n5 = Unsigned<One, Zero, One>;
    using n6 = Unsigned<Zero, One, One>;
    using n7 = Unsigned<One, One, One>;
    using n8 = Unsigned<Zero, Zero, Zero, One>;
    using n9 = Unsigned<One, Zero, Zero, One>;
    using n10 = Unsigned<Zero, One, Zero, One>;
    using n11 = Unsigned<One, One, Zero, One>;
    using n12 = Unsigned<Zero, Zero, One, One>;
    using n13 = Unsigned<One, Zero, One, One>;
    using n14 = Unsigned<Zero, One, One, One>;
    using n15 = Unsigned<One, One, One, One>;
    using n16 = Unsigned<Zero, Zero, Zero, Zero, One>;

    using N0 = Unsigned<>;
    using N1 = UnsignedInc_v<N0>;
    using N2 = UnsignedInc_v<N1>;
    using N3 = UnsignedInc_v<N2>;
    using N4 = UnsignedInc_v<N3>;
    using N5 = UnsignedInc_v<N4>;
    using N6 = UnsignedInc_v<N5>;
    using N7 = UnsignedInc_v<N6>;
    using N8 = UnsignedInc_v<N7>;
    using N9 = UnsignedInc_v<N8>;
    using N10 = UnsignedInc_v<N9>;
    using N11 = UnsignedInc_v<N10>;
    using N12 = UnsignedInc_v<N11>;
    using N13 = UnsignedInc_v<N12>;
    using N14 = UnsignedInc_v<N13>;
    using N15 = UnsignedInc_v<N14>;
    using N16 = UnsignedInc_v<N15>;

    static_assert(is_same<n0, N0>);
    static_assert(is_same<n1, N1>);
    static_assert(is_same<n2, N2>);
    static_assert(is_same<n3, N3>);
    static_assert(is_same<n4, N4>);
    static_assert(is_same<n5, N5>);
    static_assert(is_same<n6, N6>);
    static_assert(is_same<n7, N7>);
    static_assert(is_same<n8, N8>);
    static_assert(is_same<n9, N9>);
    static_assert(is_same<n10, N10>);
    static_assert(is_same<n11, N11>);
    static_assert(is_same<n12, N12>);
    static_assert(is_same<n13, N13>);
    static_assert(is_same<n14, N14>);
    static_assert(is_same<n15, N15>);
    static_assert(is_same<n16, N16>);
}
