#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/prepend.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace PrependImpl
{
    template <Any_t Char, Any_t S>
        requires Unsigned8_t<Char> && String_t<S>
    struct Prepend<Char, S>
    {
        using result = ToString_v<Prepend_v<Char, ToList_v<S>>>;
    };
} // namespace PrependImpl

