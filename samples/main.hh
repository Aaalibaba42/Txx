#pragma once

#include "txx.hh"

#include "factorial.hh"

namespace MainImpl
{
    template <Any_t Input>
    struct Main;

    template <Any_t Input>
    using Main_v = Main<Input>::result;

    template <Any_t Input>
    struct Main
    {
        // Write your code HERE
        using result = Factorial_v<Input>;
    };
} // namespace MainImpl

using MainImpl::Main_v;
