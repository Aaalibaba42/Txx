#pragma once

#include "types/list/list.hh"

template <typename... Elems>
void list_t_stub(List<Elems...>);

template <typename T>
concept List_t = requires(T list) {
    { list_t_stub(list) };
};
