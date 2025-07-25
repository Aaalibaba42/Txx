#pragma once

#include "bools/concept.hh"
#include "functions/function.hh"
#include "literals/bools.hh"
#include "meta/any.hh"

namespace TernaryImpl
{
    template <Any_t Cond, Any_t Success, Any_t Failure>
    struct Ternary;

    template <Any_t Cond, Any_t Success, Any_t Failure>
    using Ternary_v = Ternary<Cond, Success, Failure>::result;

    struct TernaryFunc
    {
        using is_function = IsFunction;

        template <Any_t Cond, Any_t Success, Any_t Failure>
        struct apply
        {
            using result = Ternary_v<Cond, Success, Failure>;
        };
    };

    // This is technically useless, but this explicitate that Bool_t can
    // instantiate Ternary, that way if we want to have some types be "Truthy"
    // or "Falsy", it can be explicitated like this
    template <Any_t Cond, Any_t Success, Any_t Failure>
        requires Bool_t<Cond>
    struct Ternary<Cond, Success, Failure>
    {
        static_assert(false, "Unreachable");
    };

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

} // namespace TernaryImpl

using TernaryImpl::TernaryFunc;
using TernaryImpl::Ternary_v;
