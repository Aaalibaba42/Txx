#pragma once

#include "../../utils/is_same.hh"
#include "list/list.hh"
#include "list/ops/map.hh"
#include "literals/bigunsigned.hh"
#include "numbers/unsigned/bigunsigned/ops/inc.hh"

namespace list_map_tests
{

    static_assert(
        is_same<ListMap_v<BigUnsignedIncFunc, List<bu1, bu2>>, List<bu2, bu3>>);

    // TODO write more tests

} // namespace list_map_tests
