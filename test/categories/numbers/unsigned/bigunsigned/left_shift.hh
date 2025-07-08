#pragma once

#include "numbers/unsigned/bigunsigned/ops/left_shift.hh"

#include "../../../../utils/is_same.hh"
#include "literals.hh"

namespace bigunsigned_lshift_tests
{
    static_assert(is_same<BigUnsignedLShift_v<bu1, bu0>, bu1>);
    static_assert(is_same<BigUnsignedLShift_v<bu1, bu1>, bu2>);
    static_assert(is_same<BigUnsignedLShift_v<bu2, bu2>, bu8>);
    static_assert(is_same<BigUnsignedLShift_v<bu3, bu3>, bu24>);
    static_assert(is_same<BigUnsignedLShift_v<bu4, bu1>, bu8>);
    static_assert(is_same<BigUnsignedLShift_v<bu5, bu2>, bu20>);
    static_assert(is_same<BigUnsignedLShift_v<bu6, bu1>, bu12>);
    static_assert(is_same<BigUnsignedLShift_v<bu7, bu2>, bu28>);
    static_assert(is_same<BigUnsignedLShift_v<bu8, bu1>, bu16>);
    static_assert(is_same<BigUnsignedLShift_v<bu9, bu2>, bu36>);
    static_assert(is_same<BigUnsignedLShift_v<bu10, bu1>, bu20>);
    static_assert(is_same<BigUnsignedLShift_v<bu0, bu5>, bu0>);
    static_assert(is_same<BigUnsignedLShift_v<bu1, bu3>, bu8>);
    static_assert(is_same<BigUnsignedLShift_v<bu2, bu1>, bu4>);
    static_assert(is_same<BigUnsignedLShift_v<bu3, bu2>, bu12>);
    static_assert(is_same<BigUnsignedLShift_v<bu4, bu3>, bu32>);
    static_assert(is_same<BigUnsignedLShift_v<bu5, bu1>, bu10>);
    static_assert(is_same<BigUnsignedLShift_v<bu6, bu2>, bu24>);
    static_assert(is_same<BigUnsignedLShift_v<bu7, bu1>, bu14>);
    static_assert(is_same<BigUnsignedLShift_v<bu8, bu2>, bu32>);
    static_assert(is_same<BigUnsignedLShift_v<bu1, bu4>, bu16>);
} // namespace bigunsigned_lshift_tests
