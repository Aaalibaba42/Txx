#pragma once

#include "utils.hh"

struct Zero
{};
struct One
{};

template <typename... Bits>
struct Number
{};

template <typename Numerical, Numerical num>
struct ToNumber
{
    static_assert();
    static_assert(num > 0);
};
