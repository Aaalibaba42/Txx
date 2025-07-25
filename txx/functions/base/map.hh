#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace MapImpl
{
    template <Any_t Func, Any_t Range>
    struct Map;

    template <Any_t Func, Any_t Range>
    using Map_v = Map<Func, Range>::result;

    struct MapFunc
    {
        using is_function = IsFunction;

        template <Any_t Func, Any_t List>
        struct apply
        {
            using result = Map_v<Func, List>;
        };
    };
} // namespace MapImpl

using MapImpl::MapFunc;
using MapImpl::Map_v;
