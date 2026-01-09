#pragma once

// To achieve Polymorphism we need to declare the functions we want to exist
// in the system as taking parameters of type Any_t, then we can overload for
// each of our types the same function but which would accept parameters of
// type Any_t + MyType_t. This way, there is inclusion in the concepts, and the
// compiler can have order relation of specificity of the overloads, and thus
// can choose the most specific one for each instantiation of the template. Thus
// we automagically have a polymorphism that selects the most specific version
// of our function for the template parameters we are using.
//
// For example:
#if 0

// -- In functions/base/ge.hh --

// Declaration of this structure existing in our system
template <Any_t N1, Any_t N2>
struct Ge
{
    // If reached, it means polymorphism failed to find valid overload
    static_assert(false);
};

// These binding can be left unchanged
template <Any_t N1, Any_t N2>
using Ge_v = Ge<N1, N2>::result;


struct GeFunc
{
    using is_function = IsFunction;

    template <Any_t N1, Any_t N2>
    struct apply
    {
        using result = Ge<N1, N2>::result;
    };
};

// -- in numbers/unsigned/bigunsigned/ops/ge.hh --
 
// Declare overload for this structure with BigUnsigned arguments
//
// Since there is an inclusion relation between the concept of the template, the
// compiler deduces that this overload is *more* specific than the one above,
// thus it will choose it before the other one.
template <Any_t buN1, Any_t buN2>
    requires BigUnsigned_t<buN1> && BigUnsigned_t<buN2>
struct Ge<buN1, buN2>
{
    // Ge impl for BigUnsigned
};

// -- in numbers/unsigned/unsigned8/ops/ge.hh --

// Exact same thing, but overloads with Unsigned8 instead
template <Any_t u8N1, Any_t u8N2>
    requires Unsigned8_t<u8N1> && Unsigned8_t<u8N2>
struct Ge<u8N1, u8N2>
{
    // Ge impl for Unsigned8
};

// -- in path/to/body.txx --

// Our single Ge function thing can be used with arguments of different types,
// and the correct one will be selected
using r1 = AssertEq<Apply_t<GeFunc, u8_30, u8_50>,
                    Apply_t<GeFunc, bu30, bu50>>::result;
using r2 = AssertEq<Ge_v<u8_1, u8_2>, Ge_v<bu1, bu2>>::result;

#endif

// These are the declaration of the functions that exist in the system:
#include "functions/base/add.hh"
#include "functions/base/and.hh"
#include "functions/base/append.hh"
#include "functions/base/apply.hh"
#include "functions/base/canonicalize.hh"
#include "functions/base/combine.hh"
#include "functions/base/curry.hh"
#include "functions/base/dec.hh"
#include "functions/base/div.hh"
#include "functions/base/eq.hh"
#include "functions/base/foldl.hh"
#include "functions/base/foldr.hh"
#include "functions/base/ge.hh"
#include "functions/base/gt.hh"
#include "functions/base/head.hh"
#include "functions/base/inc.hh"
#include "functions/base/is_empty.hh"
#include "functions/base/is_same.hh"
#include "functions/base/le.hh"
#include "functions/base/left_shift.hh"
#include "functions/base/length.hh"
#include "functions/base/lt.hh"
#include "functions/base/map.hh"
#include "functions/base/mod.hh"
#include "functions/base/mul.hh"
#include "functions/base/not.hh"
#include "functions/base/nth.hh"
#include "functions/base/or.hh"
#include "functions/base/prepend.hh"
#include "functions/base/reverse.hh"
#include "functions/base/right_shift.hh"
#include "functions/base/set.hh"
#include "functions/base/sub.hh"
#include "functions/base/tail.hh"
#include "functions/base/ternary.hh"
#include "functions/base/to_bigunsigned.hh"
#include "functions/base/to_list.hh"
#include "functions/base/to_unsigned8.hh"
#include "functions/base/xor.hh"
