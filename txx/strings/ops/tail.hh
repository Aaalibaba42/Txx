#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/tail.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace TailImpl
{
    template <Any_t S>
        requires String_t<S>
    struct Tail<S>
    {
        using result = ToString_v<Tail_v<ToList_v<S>>>;
    };
} // namespace TailImpl

