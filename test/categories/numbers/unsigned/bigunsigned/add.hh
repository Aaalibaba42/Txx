#pragma once

#include "../../../../utils/is_same.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"

namespace bigunsigned_add_tests
{
    using A5 = Add_v<bu3, bu2>;
    using A16 = Add_v<bu8, bu8>;
    using A8 = Add_v<bu7, bu1>;
    using A1 = Add_v<bu0, bu1>;
    using A0 = Add_v<bu0, bu0>;
    using A15_1 = Add_v<bu15, bu0>;
    using A15_2 = Add_v<bu0, bu15>;
    using A16_1 = Add_v<bu15, bu1>;
    using A16_2 = Add_v<bu1, bu15>;
    using A6 = Add_v<bu2, bu4>;
    using A9 = Add_v<bu5, bu4>;
    using A11 = Add_v<bu3, bu8>;
    using A14 = Add_v<bu6, bu8>;
    using A15 = Add_v<bu7, bu8>;
    using A10 = Add_v<bu4, bu6>;
    using A13 = Add_v<bu5, bu8>;
    using A17 = Add_v<bu9, bu8>;
    using A19 = Add_v<bu11, bu8>;
    using A22 = Add_v<bu14, bu8>;
    using A25 = Add_v<bu16, bu9>;
    using A28 = Add_v<bu19, bu9>;
    using A30 = Add_v<bu20, bu10>;
    using A33 = Add_v<bu22, bu11>;
    using A35 = Add_v<bu24, bu11>;
    using A38 = Add_v<bu27, bu11>;
    using A40 = Add_v<bu30, bu10>;
    using A42 = Add_v<bu33, bu9>;
    using A45 = Add_v<bu36, bu9>;
    using A48 = Add_v<bu39, bu9>;
    using A50 = Add_v<bu41, bu9>;

    static_assert(is_same<A6, bu6>);
    static_assert(is_same<A9, bu9>);
    static_assert(is_same<A11, bu11>);
    static_assert(is_same<A14, bu14>);
    static_assert(is_same<A15, bu15>);
    static_assert(is_same<A10, bu10>);
    static_assert(is_same<A13, bu13>);
    static_assert(is_same<A17, bu17>);
    static_assert(is_same<A19, bu19>);
    static_assert(is_same<A22, bu22>);
    static_assert(is_same<A25, bu25>);
    static_assert(is_same<A28, bu28>);
    static_assert(is_same<A30, bu30>);
    static_assert(is_same<A33, bu33>);
    static_assert(is_same<A35, bu35>);
    static_assert(is_same<A38, bu38>);
    static_assert(is_same<A40, bu40>);
    static_assert(is_same<A42, bu42>);
    static_assert(is_same<A45, bu45>);
    static_assert(is_same<A48, bu48>);
    static_assert(is_same<A50, bu50>);
    static_assert(is_same<A5, bu5>);
    static_assert(is_same<A16, bu16>);
    static_assert(is_same<A8, bu8>);
    static_assert(is_same<A1, bu1>);
    static_assert(is_same<A0, bu0>);
    static_assert(is_same<A15_1, bu15>);
    static_assert(is_same<A15_2, bu15>);
    static_assert(is_same<A16_1, bu16>);
    static_assert(is_same<A16_2, bu16>);
} // namespace bigunsigned_add_tests
