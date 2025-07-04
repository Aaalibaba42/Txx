#pragma once

#include "types/list/list.hh"
#include "types/meta/any.hh"

template <Any_t... Elems>
void list_t_stub(List<Elems...>);

template <typename L>
concept List_t = requires(L list) {
    { list_t_stub(list) };
};
