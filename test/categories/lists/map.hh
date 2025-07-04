#pragma once

#include "types/list/ops/map.hh"
#include "types/list/list.hh"
#include "types/numbers/unsigned/bigunsigned/ops/inc.hh"

#include "../../utils/is_same.hh"
#include "../numbers/unsigned/bigunsigned/literals.hh"

namespace list_map_tests
{

    static_assert(
        is_same<Apply_v<ListMapFunc, BigUnsignedIncFunc, List<bu1, bu2>>,
                List<bu2, bu3>>);
} // namespace list_map_tests
