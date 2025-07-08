#pragma once

#include "bools/concept.hh"
#include "bools/literals.hh"
#include "functions/function.hh"
#include "meta/any.hh"

namespace TernaryImpl
{
    template <Bool_t Cond, Any_t Success, Any_t Failure>
    struct Ternary;

    template <Bool_t Cond, Any_t Success, Any_t Failure>
    using Ternary_v = Ternary<Cond, Success, Failure>::result;

    template <Any_t Success, Any_t Failure>
    struct Ternary<True, Success, Failure>
    {
        using result = Success;
    };

    template <Any_t Success, Any_t Failure>
    struct Ternary<False, Success, Failure>
    {
        using result = Failure;
    };

    struct TernaryFunc
    {
        using is_function = IsFunction;

        template <Bool_t Cond, Any_t Success, Any_t Failure>
        struct apply
        {
            using result = Ternary_v<Cond, Success, Failure>;
        };
    };
} // namespace TernaryImpl

using TernaryImpl::TernaryFunc;
using TernaryImpl::Ternary_v;
