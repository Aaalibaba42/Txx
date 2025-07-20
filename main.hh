#pragma once

#include "txx.hh"

// Change this to your path/to/prelude.txx
#include "samples/test_prelude.txx"

namespace MainImpl
{
    template <Any_t Input>
    struct Main;

    template <Any_t Input>
    using Main_v = Main<Input>::result;

    template <Any_t Input>
    struct Main
    {
// Change this to your path/to/body.txx
#include "samples/test_body.txx"
    };
} // namespace MainImpl

using MainImpl::Main_v;
