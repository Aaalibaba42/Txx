#pragma once

#include "list/ops/map.hh"
#include "list/list.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

#include "../../utils/is_same.hh"
#include "literals/bigunsigned.hh"

namespace list_map_tests
{

    static_assert(
        is_same<Apply_v<ListMapFunc, BigUnsignedIncFunc, List<bu1, bu2>>,
                List<bu2, bu3>>);
} // namespace list_map_tests
