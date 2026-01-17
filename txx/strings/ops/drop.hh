#pragma once

#include "casts/string.hh"
#include "functions/base.hh"
#include "list/ops/drop.hh"
#include "numbers/unsigned/bigunsigned/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace DropImpl
{
    template <Any_t N, Any_t S>
        requires BigUnsigned_t<N> && String_t<S>
    struct Drop<N, S>
    {
        using result = ToString_v<Drop_v<N, ToList_v<S>>>;
    };
} // namespace DropImpl

