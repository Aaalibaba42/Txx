#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/nth.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace NthImpl
{
    template <Any_t S, Any_t Idx>
        requires String_t<S> && BigUnsigned_t<Idx>
    struct Nth<S, Idx>
    {
        using result = Nth_v<ToList_v<S>, Idx>;
    };
} // namespace NthImpl

