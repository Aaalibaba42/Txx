#pragma once

#include "types/bools/concept.hh"
#include "types/bools/literals.hh"
#include "types/meta/any.hh"

/* WARNING:
    The ternary is **not** lazy. Boths sides will always be evaluated.

    Meaning you **cannot** stop a recursion using this structure.
*/

namespace TernaryImpl
{
    template <Bool_t Cond, Any_t Success, Any_t Failure>
    struct Ternary;

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

template <Bool_t Cond, Any_t Success, Any_t Failure>
using Ternary_v = TernaryImpl::Ternary<Cond, Success, Failure>::result;
