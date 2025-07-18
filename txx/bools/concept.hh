#pragma once

#include "literals/bools.hh"

namespace BoolTImpl
{
    void bool_t_stub(True);
    void bool_t_stub(False);

    template <typename T>
    concept Bool_t = requires(T b) {
        { bool_t_stub(b) };
    };
} // namespace BoolTImpl

using BoolTImpl::Bool_t;
