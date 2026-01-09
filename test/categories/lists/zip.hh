#pragma once

#include "functions/base/add.hh"
#include "list/list.hh"
#include "list/ops/zip.hh"
#include "list/ops/zip_with.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"
#include "numbers/unsigned/bigunsigned/ops/add.hh"

namespace list_zip_tests
{
    // Zip tests
    using _t0 = AssertEq<Zip_v<List<>, List<>>, List<>>::result;
    using _t1 = AssertEq<Zip_v<List<bu1>, List<>>, List<>>::result;
    using _t2 = AssertEq<Zip_v<List<>, List<bu1>>, List<>>::result;
    using _t3 =
        AssertEq<Zip_v<List<bu1>, List<bu2>>, List<List<bu1, bu2>>>::result;
    using _t4 = AssertEq<Zip_v<List<bu1, bu2>, List<bu3, bu4>>,
                         List<List<bu1, bu3>, List<bu2, bu4>>>::result;
    using _t5 = AssertEq<Zip_v<List<bu1, bu2, bu3>, List<bu4, bu5>>,
                         List<List<bu1, bu4>, List<bu2, bu5>>>::result;

    // ZipWith tests using Add
    using _t6 = AssertEq<ZipWith_v<AddFunc, List<>, List<>>, List<>>::result;
    using _t7 = AssertEq<ZipWith_v<AddFunc, List<bu1>, List<>>, List<>>::result;
    using _t8 = AssertEq<ZipWith_v<AddFunc, List<>, List<bu1>>, List<>>::result;
    using _t9 =
        AssertEq<ZipWith_v<AddFunc, List<bu1>, List<bu2>>, List<bu3>>::result;
    using _t10 = AssertEq<ZipWith_v<AddFunc, List<bu1, bu2>, List<bu3, bu4>>,
                          List<bu4, bu6>>::result;
    using _t11 = AssertEq<ZipWith_v<AddFunc, List<bu10, bu20>, List<bu1, bu2>>,
                          List<bu11, bu22>>::result;
} // namespace list_zip_tests
