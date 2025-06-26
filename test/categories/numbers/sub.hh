#pragma once

#include "types/numbers/unsigned/ops/sub.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

namespace unsigned_sub_tests
{
    using S0_1 = UnsignedSub_v<n1, n1>;
    using S1 = UnsignedSub_v<n3, n2>;
    using S0 = UnsignedSub_v<n8, n8>;
    using S6 = UnsignedSub_v<n7, n1>;
    using S7 = UnsignedSub_v<n8, n1>;
    using S15 = UnsignedSub_v<n15, n0>;
    using S14 = UnsignedSub_v<n15, n1>;
    using S5 = UnsignedSub_v<n6, n1>;
    using S8 = UnsignedSub_v<n10, n2>;
    using S9 = UnsignedSub_v<n11, n2>;
    using S10 = UnsignedSub_v<n12, n2>;
    using S11 = UnsignedSub_v<n13, n2>;
    using S12 = UnsignedSub_v<n14, n2>;
    using S13 = UnsignedSub_v<n15, n2>;
    using S14_1 = UnsignedSub_v<n16, n2>;
    using S15_1 = UnsignedSub_v<n17, n2>;
    using S16 = UnsignedSub_v<n18, n2>;
    using S17 = UnsignedSub_v<n19, n2>;
    using S18 = UnsignedSub_v<n20, n2>;
    using S19 = UnsignedSub_v<n21, n2>;
    using S20 = UnsignedSub_v<n22, n2>;
    using S21 = UnsignedSub_v<n23, n2>;
    using S22 = UnsignedSub_v<n24, n2>;
    using S23 = UnsignedSub_v<n25, n2>;
    using S24 = UnsignedSub_v<n26, n2>;
    using S12 = UnsignedSub_v<n27, n15>;
    using S26 = UnsignedSub_v<n28, n2>;
    using S27 = UnsignedSub_v<n29, n2>;
    using S28 = UnsignedSub_v<n30, n2>;
    using S29 = UnsignedSub_v<n31, n2>;
    using S30 = UnsignedSub_v<n32, n2>;
    using S31 = UnsignedSub_v<n33, n2>;
    using S32 = UnsignedSub_v<n34, n2>;
    using S33 = UnsignedSub_v<n35, n2>;
    using S34 = UnsignedSub_v<n36, n2>;
    using S35 = UnsignedSub_v<n37, n2>;
    using S36 = UnsignedSub_v<n38, n2>;
    using S37 = UnsignedSub_v<n39, n2>;
    using S38 = UnsignedSub_v<n40, n2>;
    using S39 = UnsignedSub_v<n41, n2>;
    using S40 = UnsignedSub_v<n42, n2>;

    static_assert(is_same<S1, n1>);
    static_assert(is_same<S0, n0>);
    static_assert(is_same<S0_1, n0>);
    static_assert(is_same<S6, n6>);
    static_assert(is_same<S7, n7>);
    static_assert(is_same<S15, n15>);
    static_assert(is_same<S14, n14>);
    static_assert(is_same<S5, n5>);
    static_assert(is_same<S8, n8>);
    static_assert(is_same<S9, n9>);
    static_assert(is_same<S10, n10>);
    static_assert(is_same<S11, n11>);
    static_assert(is_same<S12, n12>);
    static_assert(is_same<S13, n13>);
    static_assert(is_same<S14_1, n14>);
    static_assert(is_same<S15_1, n15>);
    static_assert(is_same<S16, n16>);
    static_assert(is_same<S17, n17>);
    static_assert(is_same<S18, n18>);
    static_assert(is_same<S19, n19>);
    static_assert(is_same<S20, n20>);
    static_assert(is_same<S21, n21>);
    static_assert(is_same<S22, n22>);
    static_assert(is_same<S23, n23>);
    static_assert(is_same<S24, n24>);
    static_assert(is_same<S12, n12>);
    static_assert(is_same<S26, n26>);
    static_assert(is_same<S27, n27>);
    static_assert(is_same<S28, n28>);
    static_assert(is_same<S29, n29>);
    static_assert(is_same<S30, n30>);
    static_assert(is_same<S31, n31>);
    static_assert(is_same<S32, n32>);
    static_assert(is_same<S33, n33>);
    static_assert(is_same<S34, n34>);
    static_assert(is_same<S35, n35>);
    static_assert(is_same<S36, n36>);
    static_assert(is_same<S37, n37>);
    static_assert(is_same<S38, n38>);
    static_assert(is_same<S39, n39>);
    static_assert(is_same<S40, n40>);
} // namespace unsigned_sub_tests
