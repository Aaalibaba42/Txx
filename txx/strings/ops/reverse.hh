#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/reverse.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace ReverseImpl
{
    template <Any_t S>
        requires String_t<S>
    struct Reverse<S>
    {
        using result = ToString_v<Reverse_v<ToList_v<S>>>;
    };
} // namespace ReverseImpl

