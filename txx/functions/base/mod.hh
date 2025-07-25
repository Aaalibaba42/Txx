#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace ModImpl
{
    template <Any_t LHS, Any_t RHS>
    struct Mod;

    template <Any_t LHS, Any_t RHS>
    using Mod_v = Mod<LHS, RHS>::result;

    struct ModFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Mod_v<LHS, RHS>;
        };
    };
} // namespace ModImpl
