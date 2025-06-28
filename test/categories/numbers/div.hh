#pragma once

#include "types/numbers/unsigned/ops/div.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

// Fails (as expected)
// static_assert(is_same<UnsignedDiv_v<n10, n0>, n0>);
// static_assert(is_same<UnsignedDiv_v<n0, n0>, n0>);

static_assert(is_same<UnsignedDiv_v<n1, n2>, n0>);
static_assert(is_same<UnsignedDiv_v<n5, n5>, n1>);
static_assert(is_same<UnsignedDiv_v<n10, n2>, n5>);
static_assert(is_same<UnsignedDiv_v<n10, n1>, n10>);
static_assert(is_same<UnsignedDiv_v<n0, n5>, n0>);
static_assert(is_same<UnsignedDiv_v<n20, n4>, n5>);
static_assert(is_same<UnsignedDiv_v<n50, n10>, n5>);
static_assert(is_same<UnsignedDiv_v<n64, n2>, n32>);
static_assert(is_same<UnsignedDiv_v<n25, n3>, n8>);
static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
static_assert(is_same<UnsignedDiv_v<n50, n25>, n2>);
static_assert(is_same<UnsignedDiv_v<n64, n63>, n1>);
static_assert(is_same<UnsignedDiv_v<n64, n16>, n4>);
static_assert(is_same<UnsignedDiv_v<n15, n1>, n15>);
static_assert(is_same<UnsignedDiv_v<n10, n3>, n3>);
static_assert(is_same<UnsignedDiv_v<n64, n64>, n1>);
static_assert(is_same<UnsignedDiv_v<n30, n7>, n4>);
static_assert(is_same<UnsignedDiv_v<n17, n5>, n3>);
static_assert(is_same<UnsignedDiv_v<n50, n26>, n1>);
static_assert(is_same<UnsignedDiv_v<n50, n24>, n2>);
static_assert(is_same<UnsignedDiv_v<n1, n64>, n0>);
static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
static_assert(is_same<UnsignedDiv_v<n10, n20>, n0>);
static_assert(is_same<UnsignedDiv_v<n64, n1>, n64>);
