#pragma once

#include "functions/concept.hh"
#include "functions/function.hh"
#include "meta/any.hh"

// Bootstrapping applying 1st class functions

namespace FunctionApplyImpl
{
    struct Apply
    {
        using is_function = IsFunction;

        template <Function_t Foo, Any_t... Args>
        struct apply
        {
            using result = Foo::template apply<Args...>::result;
        };
    };

    template <Function_t Foo, Any_t... Args>
    using Apply_v = Apply::template apply<Foo, Args...>::result;

} // namespace FunctionApplyImpl

using ApplyFunc = FunctionApplyImpl::Apply;
using FunctionApplyImpl::Apply_v;
