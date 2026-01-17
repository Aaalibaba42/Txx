#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "numbers/unsigned/unsigned8/concept.hh"
#include "strings/concept.hh"
#include "strings/strings.hh"

namespace ToListImpl
{
    template <Any_t V>
        requires String_t<V>
    struct ToList<V>;

    template <Unsigned8_t... Chars>
    struct ToList<String<Chars...>>
    {
        using result = List<Chars...>;
    };
} // namespace ToListImpl

namespace ToStringImpl
{
    template <Any_t V>
        requires List_t<V>
    struct ToString<V>;

    template <Unsigned8_t... Chars>
    struct ToString<List<Chars...>>
    {
        using result = String<Chars...>;
    };
} // namespace ToStringImpl

