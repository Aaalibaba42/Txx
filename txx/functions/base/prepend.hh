#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace PrependImpl
{
    template <Any_t Elem, Any_t Range>
    struct Prepend;

    template <Any_t Elem, Any_t Range>
    using Prepend_v = Prepend<Elem, Range>::result;

    struct PrependFunc
    {
        using is_function = IsFunction;

        template <Any_t Elem, Any_t L>
        struct apply
        {
            using result = Prepend_v<Elem, L>;
        };
    };
} // namespace PrependImpl

using PrependImpl::PrependFunc;
using PrependImpl::Prepend_v;
