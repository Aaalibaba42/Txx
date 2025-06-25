#pragma once

#include "types/numbers/unsigned/ops/add.hh"

#include "../utils/is_same.hh"
#include "../utils/numbers.hh"

using A5 = UnsignedAdd_v<n3, n2>;
using A16 = UnsignedAdd_v<n8, n8>;
using A8 = UnsignedAdd_v<n7, n1>;
using A1 = UnsignedAdd_v<n0, n1>;
using A0 = UnsignedAdd_v<n0, n0>;
using A15_1 = UnsignedAdd_v<n15, n0>;
using A15_2 = UnsignedAdd_v<n0, n15>;
using A16_1 = UnsignedAdd_v<n15, n1>;
using A16_2 = UnsignedAdd_v<n1, n15>;
using A6 = UnsignedAdd_v<n2, n4>;
using A9 = UnsignedAdd_v<n5, n4>;
using A11 = UnsignedAdd_v<n3, n8>;
using A14 = UnsignedAdd_v<n6, n8>;
using A15 = UnsignedAdd_v<n7, n8>;
using A10 = UnsignedAdd_v<n4, n6>;
using A13 = UnsignedAdd_v<n5, n8>;
using A17 = UnsignedAdd_v<n9, n8>;
using A19 = UnsignedAdd_v<n11, n8>;
using A22 = UnsignedAdd_v<n14, n8>;
using A25 = UnsignedAdd_v<n16, n9>;
using A28 = UnsignedAdd_v<n19, n9>;
using A30 = UnsignedAdd_v<n20, n10>;
using A33 = UnsignedAdd_v<n22, n11>;
using A35 = UnsignedAdd_v<n24, n11>;
using A38 = UnsignedAdd_v<n27, n11>;
using A40 = UnsignedAdd_v<n30, n10>;
using A42 = UnsignedAdd_v<n33, n9>;
using A45 = UnsignedAdd_v<n36, n9>;
using A48 = UnsignedAdd_v<n39, n9>;
using A50 = UnsignedAdd_v<n41, n9>;

static_assert(is_same<A6, n6>);
static_assert(is_same<A9, n9>);
static_assert(is_same<A11, n11>);
static_assert(is_same<A14, n14>);
static_assert(is_same<A15, n15>);
static_assert(is_same<A10, n10>);
static_assert(is_same<A13, n13>);
static_assert(is_same<A17, n17>);
static_assert(is_same<A19, n19>);
static_assert(is_same<A22, n22>);
static_assert(is_same<A25, n25>);
static_assert(is_same<A28, n28>);
static_assert(is_same<A30, n30>);
static_assert(is_same<A33, n33>);
static_assert(is_same<A35, n35>);
static_assert(is_same<A38, n38>);
static_assert(is_same<A40, n40>);
static_assert(is_same<A42, n42>);
static_assert(is_same<A45, n45>);
static_assert(is_same<A48, n48>);
static_assert(is_same<A50, n50>);
static_assert(is_same<A5, n5>);
static_assert(is_same<A16, n16>);
static_assert(is_same<A8, n8>);
static_assert(is_same<A1, n1>);
static_assert(is_same<A0, n0>);
static_assert(is_same<A15_1, n15>);
static_assert(is_same<A15_2, n15>);
static_assert(is_same<A16_1, n16>);
static_assert(is_same<A16_2, n16>);
