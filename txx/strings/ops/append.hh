#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/append.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace AppendImpl
{
    template <Any_t Char, Any_t S>
        requires Unsigned8_t<Char> && String_t<S>
    struct Append<Char, S>
    {
        using result = ToString_v<Append_v<Char, ToList_v<S>>>;
    };
} // namespace AppendImpl

