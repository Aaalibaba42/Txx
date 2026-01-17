#pragma once

#include "literals/ordering.hh"

namespace OrderingTImpl
{
    void ordering_t_stub(LT);
    void ordering_t_stub(EQ);
    void ordering_t_stub(GT);

    template <typename T>
    concept Ordering_t = requires(T o) {
        { ordering_t_stub(o) };
    };
} // namespace OrderingTImpl

using OrderingTImpl::Ordering_t;

