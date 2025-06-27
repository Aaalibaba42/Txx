#pragma once

#include "types/numbers/unsigned/ops/eq.hh"

#include "../../utils/is_same.hh"
#include "../../utils/numbers.hh"

static_assert(is_same<UnsignedEq_v<n1, n1>, True>);
static_assert(is_same<UnsignedEq_v<n1, n2>, False>);
static_assert(is_same<UnsignedEq_v<n5, n5>, True>);
static_assert(is_same<UnsignedEq_v<n5, n6>, False>);
static_assert(is_same<UnsignedEq_v<n10, n10>, True>);
static_assert(is_same<UnsignedEq_v<n10, n11>, False>);
static_assert(is_same<UnsignedEq_v<n0, n0>, True>);
static_assert(is_same<UnsignedEq_v<n1, n0>, False>);
static_assert(is_same<UnsignedEq_v<n64, n64>, True>);
static_assert(is_same<UnsignedEq_v<n64, n63>, False>);
static_assert(is_same<UnsignedEq_v<n32, n32>, True>);
static_assert(is_same<UnsignedEq_v<n32, n33>, False>);
static_assert(is_same<UnsignedEq_v<n1, n1>, True>);
static_assert(is_same<UnsignedEq_v<n1, n2>, False>);
static_assert(is_same<UnsignedEq_v<n10, n10>, True>);
static_assert(is_same<UnsignedEq_v<n10, n20>, False>);
