#pragma once

#include "bools/concept.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace AssertsImpl
{
    template <Bool_t Cond>
    struct Assert;

    // Assert<False>
    template <Bool_t Cond>
    struct Assert
    {
        static_assert(false);
    };

    template <>
    struct Assert<True>
    {
        using result = True;
    };

    template <Any_t E1, Any_t E2>
    struct AssertEq;

    template <Any_t E1, Any_t E2>
    struct AssertEq
    {
        static_assert(false);
    };

    template <Any_t T>
    struct AssertEq<T, T>
    {
        using result = True;
    };

    template <Any_t E1, Any_t E2>
    struct AssertNeq;

    template <Any_t E1, Any_t E2>
    struct AssertNeq
    {
        using result = True;
    };

    template <Any_t T>
    struct AssertNeq<T, T>
    {
        static_assert(false);
    };
} // namespace AssertsImpl

using AssertsImpl::Assert;
using AssertsImpl::AssertEq;
using AssertsImpl::AssertNeq;
