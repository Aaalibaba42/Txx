#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/take.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace TakeImpl
{
    template <Any_t N, Any_t S>
        requires BigUnsigned_t<N> && String_t<S>
    struct Take<N, S>
    {
        using result = ToString_v<Take_v<N, ToList_v<S>>>;
    };
} // namespace TakeImpl

