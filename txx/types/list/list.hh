#pragma once

#include "types/meta/any.hh"

template <Any_t... Elems>
struct List;

template <Any_t Curr, Any_t... Rest>
struct List<Curr, Rest...>
{};

template <Any_t Curr>
struct List<Curr>
{};

template <>
struct List<>
{};
