#include "txx/types/bits/literals.hh"
#include "txx/types/numbers/unsigned/unsigned.hh"
#include "txx/types/numbers/unsigned/ops/inc.hh"

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using N3 = Unsigned<One, One>;
    using N4 = UnsignedInc_v<N3>;

    static_assert(is_same<N4, Unsigned<Zero, Zero, One>>);

    using N0 = Unsigned<>;
    using N1 = UnsignedInc_v<N0>;

    static_assert(is_same<N1, Unsigned<One>>);
}
