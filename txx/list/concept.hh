#pragma once

#include "list/list.hh"
#include "meta/any.hh"

namespace ListTImpl
{
    template <Any_t... Elems>
    void list_t_stub(List<Elems...>);

    template <typename L>
    concept List_t = requires(L list) {
        { list_t_stub(list) };
    };
} // namespace ListTImpl

using ListTImpl::List_t;
