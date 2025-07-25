#pragma once

#include "functions/concept.hh"
#include "meta/any.hh"

namespace AppendImpl
{
    template <Any_t Elem, Any_t List>
    struct Append;

    template <Any_t Elem, Any_t List>
    using Append_v = Append<Elem, List>::result;

    struct AppendFunc
    {
        using is_function = IsFunction;

        template <Any_t Elem, Any_t List>
        struct apply
        {
            using result = Append_v<Elem, List>;
        };
    };
} // namespace AppendImpl

using AppendImpl::AppendFunc;
using AppendImpl::Append_v;
