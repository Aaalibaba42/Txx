#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/head.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace HeadImpl
{
    template <Any_t S>
        requires String_t<S>
    struct Head<S>
    {
        using result = Head_v<ToList_v<S>>;
    };
} // namespace HeadImpl

