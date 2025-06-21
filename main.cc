#include "types/numbers/numbers.hh"
#include "types/numbers/ops/inc.hh"

int main(void)
{
    using N3 = Number<One, One, Zero>;
    using N4 = Inc_v<N3>;

    static_assert(is_same_v<N4, Number<Zero, Zero, One>>);
}
