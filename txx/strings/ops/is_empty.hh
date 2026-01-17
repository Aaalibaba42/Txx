#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/is_empty.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace IsEmptyImpl
{
    template <Any_t S>
        requires String_t<S>
    struct IsEmpty<S>
    {
        using result = IsEmpty_v<ToList_v<S>>;
    };
} // namespace IsEmptyImpl

