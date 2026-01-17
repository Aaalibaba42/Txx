#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/length.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace LengthImpl
{
    template <Any_t S>
        requires String_t<S>
    struct Length<S>
    {
        using result = Length_v<ToList_v<S>>;
    };
} // namespace LengthImpl

