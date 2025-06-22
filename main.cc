#include "types/numbers/numbers.hh"
#include "types/numbers/ops/inc.hh"

template <typename T1, typename T2>
inline constexpr bool is_same = false;

template <typename T>
inline constexpr bool is_same<T, T> = true;

int main(void)
{
    using N3 = Number<One, One>;
    using N4 = Inc_v<N3>;

    static_assert(is_same<N4, Number<Zero, Zero, One>>);

    using N0 = Number<>;
    using N1 = Inc_v<N0>;

    static_assert(is_same<N1, Number<One>>);
}
