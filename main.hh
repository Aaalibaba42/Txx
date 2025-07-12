#pragma once

#include "txx.hh"

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
        using result = Unit;
    };
} // namespace MainImpl

using MainImpl::Main_v;
