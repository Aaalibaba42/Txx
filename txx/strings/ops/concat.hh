#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/concat.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace ConcatImpl
{
    template <Any_t S1, Any_t S2>
        requires String_t<S1> && String_t<S2>
    struct Concat<S1, S2>
    {
        using result = ToString_v<Concat_v<ToList_v<S1>, ToList_v<S2>>>;
    };
} // namespace ConcatImpl

