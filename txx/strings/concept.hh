#pragma once

#include "numbers/unsigned/unsigned8/concept.hh"
#include "strings/strings.hh"

namespace StringTImpl
{
    template <Unsigned8_t... Chars>
    void string_t_stub(String<Chars...>);

    template <typename T>
    concept String_t = requires(T str) {
        { string_t_stub(str) };
    };
} // namespace StringTImpl

using StringTImpl::String_t;

