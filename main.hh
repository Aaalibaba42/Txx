#pragma once

#include "txx.hh"

#include "samples/factorial.hh"

namespace MainImpl
{
    template <Any_t Input>
    struct Main;

    template <Any_t Input>
    using Main_v = Main<Input>::result;

    template <Any_t Input>
    struct Main
    {
        // Called with input: `Factorial_v<bu5>`
        using result = AssertEq<Input, bu125>::result;
    };
} // namespace MainImpl

using MainImpl::Main_v;
