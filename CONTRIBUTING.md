# Contributing to Txx

> **Note**: This document was AI-generated. While reviewed for accuracy, some
details may need refinement.

---

## Table of Contents

1. [Understanding Txx](#understanding-txx)
2. [Architecture Overview](#architecture-overview)
3. [The Polymorphism Pattern](#the-polymorphism-pattern)
4. [First-Class Functions](#first-class-functions)
5. [Adding a New List Operation](#adding-a-new-list-operation)
6. [Adding a New Combinator](#adding-a-new-combinator)
7. [Writing Tests](#writing-tests)
8. [Common Pitfalls](#common-pitfalls)
9. [Performance Considerations](#performance-considerations)
10. [Debugging Tips](#debugging-tips)

---

## Understanding Txx

Txx is a **functional programming language implemented entirely within C++'s
type system**. There are (almost) zero runtime values, everything is a type.

Key concepts:
- **"Values" are types**: `bu42` (BigUnsigned 42) is not the integer 42, it's
  the type `BigUnsigned<Zero, One, Zero, One, Zero, One>`
- **"Functions" are templates**: A function computes a `result` type alias from
  input types
- **"Execution" is compilation**: Running your program means compiling it

```cpp
// This is a "value" (it's a type)
using x = bu5;

// This is a "function call" (it's template instantiation)
using y = Add_v<bu3, bu2>;  // y is bu5

// This is an "assertion" (it's a static_assert(false) if template
// specialization fails)
using _check = AssertEq<y, bu5>::result;  // Verified at compile time
```

---

## Architecture Overview

```
txx/
├── bits/           # Bit type and operations (Zero, One, FullAdder)
├── bools/          # Boolean types (True, False) and operations
├── casts/          # Type conversions (List ↔ BigUnsigned)
├── functions/
│   ├── base/       # Forward declarations + Func wrappers
│   ├── base.hh     # Aggregates all base declarations
│   ├── concept.hh  # Function_t concept definition
│   └── function.hh # IsFunction tag
├── list/
│   ├── ops/        # List operation specializations
│   ├── concept.hh  # List_t concept
│   └── list.hh     # List<...> definition
├── literals/       # Convenient aliases (bu0, bu1, ..., bu255)
├── meta/           # Any_t concept, assertions
├── numbers/
│   └── unsigned/
│       ├── bigunsigned/  # Arbitrary-precision unsigned integers
│       └── unsigned8/    # 8-bit unsigned integers
└── txx.hh          # Main include file
```

### The Two-File Pattern

Every operation follows a **two-file pattern**:

1. **`functions/base/foo.hh`**: Forward declaration + function wrapper
2. **`<domain>/ops/foo.hh`**: Actual implementation via template specialization

This enables **polymorphism** — the same `Foo_v<X>` works for different types.

---

## The Polymorphism Pattern

This is the core pattern that makes Txx extensible:

### Step 1: Forward Declaration (`functions/base/add.hh`)

```cpp
namespace AddImpl
{
    // Forward declaration — no implementation yet
    template <Any_t LHS, Any_t RHS>
    struct Add;

    // Convenience alias
    template <Any_t LHS, Any_t RHS>
    using Add_v = Add<LHS, RHS>::result;

    // First-class function wrapper
    struct AddFunc
    {
        using is_function = IsFunction;

        template <Any_t LHS, Any_t RHS>
        struct apply
        {
            using result = Add_v<LHS, RHS>;
        };
    };
} // namespace AddImpl

using AddImpl::AddFunc;
using AddImpl::Add_v;
```

### Step 2: Specialization (`numbers/unsigned/bigunsigned/ops/add.hh`)

```cpp
namespace AddImpl // Notice it's in the same namespace
{
    // Specialization for BigUnsigned
    template <Any_t LHS, Any_t RHS>
        requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>
    struct Add<LHS, RHS>
    {
        // Actual implementation
        using result = /* ... */;
    };
} // namespace AddImpl
```

### Why This Works

C++ chooses the **most specific** template specialization. When you write
Add_v<bu3, bu5>`:

1. Compiler finds `Add<Any_t, Any_t>` (base declaration)
2. Compiler finds `Add<LHS, RHS> requires BigUnsigned_t<LHS> && BigUnsigned_t<RHS>`
3. The constrained version is more specific → it wins

This means you can add `Add` for new types without modifying existing code!

---

## First-Class Functions

Functions are first-class citizens via a struct-with-`apply` pattern:

```cpp
struct AddFunc
{
    using is_function = IsFunction;  // Tag for Function_t concept

    template <Any_t LHS, Any_t RHS>
    struct apply
    {
        using result = Add_v<LHS, RHS>;
    };
};
```

### Using First-Class Functions

```cpp
// Direct call
using r1 = Add_v<bu3, bu5>;  // bu8

// Via Apply
using r2 = Apply_v<AddFunc, bu3, bu5>;  // bu8

// Currying (partial application)
using Add3 = Curry_v<AddFunc, bu3>;     // A function that adds 3
using r3 = Apply_v<Add3, bu5>;          // bu8

// Composition
using Add3 = Curry_v<MulFunc, bu2>;
using AddThenDouble = Combine_v<AddFunc, DoubleFunc>;

// As argument to higher-order functions
using sums = ZipWith_v<AddFunc, List<bu1, bu2>, List<bu3, bu4>>;  // List<bu4, bu6>
```

### The `Function_t` Concept

A type is a function if it has `using is_function = IsFunction;`:

```cpp
template <typename Foo>
concept Function_t = requires { typename Foo::is_function; }
    && /* is_function is actually the IsFunction tag */;
```

---

## Adding a New List Operation

Let's walk through adding `Last` (get the last element of a list):

### 1. Create `functions/base/last.hh`

```cpp
#pragma once

#include "functions/function.hh"
#include "meta/any.hh"

namespace LastImpl
{
    template <Any_t L>
    struct Last;

    template <Any_t L>
    using Last_v = Last<L>::result;

    struct LastFunc
    {
        using is_function = IsFunction;

        template <Any_t L>
        struct apply
        {
            using result = Last_v<L>;
        };
    };
} // namespace LastImpl

using LastImpl::LastFunc;
using LastImpl::Last_v;
```

### 2. Create `list/ops/last.hh`

```cpp
#pragma once

#include "functions/base.hh"
#include "list/concept.hh"
#include "list/list.hh"
#include "meta/any.hh"

namespace LastImpl
{
    template <Any_t L>
        requires List_t<L>
    struct Last<L>;

    // Base case: single element
    template <Any_t Elem>
    struct Last<List<Elem>>
    {
        using result = Elem;
    };

    // Recursive case: skip head, recurse on tail
    template <Any_t Head, Any_t Second, Any_t... Rest>
    struct Last<List<Head, Second, Rest...>>
    {
        using result = Last_v<List<Second, Rest...>>;
    };
} // namespace LastImpl
```

### 3. Add includes

In `functions/base.hh`:
```cpp
#include "functions/base/last.hh"
```

In `txx/txx.hh`:
```cpp
#include "functions/base/last.hh"
#include "list/ops/last.hh"
```

### 4. Add tests (see [Writing Tests](#writing-tests))

---

## Adding a New Combinator

Combinators are functions that operate on other functions. Here's how to add
`On`:

```
(f `on` g) x y = f (g x) (g y)
```

### Implementation

```cpp
// functions/base/on.hh
#pragma once

#include "functions/base/apply.hh"
#include "functions/concept.hh"
#include "functions/function.hh"
#include "meta/any.hh"

namespace OnImpl
{
    template <Function_t F, Function_t G>
    struct OnFunc
    {
        using is_function = IsFunction;

        template <Any_t X, Any_t Y>
        struct apply
        {
            using gx = Apply_v<G, X>;
            using gy = Apply_v<G, Y>;
            using result = Apply_v<F, gx, gy>;
        };
    };

    struct OnCombinator
    {
        using is_function = IsFunction;

        template <Function_t F, Function_t G>
        struct apply
        {
            using result = OnFunc<F, G>;
        };
    };

    template <Function_t F, Function_t G>
    using On_v = OnFunc<F, G>;
} // namespace OnImpl

using OnImpl::OnCombinator;
using OnImpl::On_v;
```

---

## Writing Tests

Tests live in `test/categories/` and use `AssertEq` from `meta/assert.hh`:

### Test File Structure

```cpp
// test/categories/lists/last.hh
#pragma once

#include "list/list.hh"
#include "list/ops/last.hh"
#include "literals/bigunsigned.hh"
#include "meta/assert.hh"

namespace list_last_tests
{
    using _t0 = AssertEq<Last_v<List<bu1>>, bu1>::result;
    using _t1 = AssertEq<Last_v<List<bu1, bu2>>, bu2>::result;
    using _t2 = AssertEq<Last_v<List<bu1, bu2, bu3>>, bu3>::result;
    using _t3 = AssertEq<Last_v<List<bu5, bu10, bu15, bu20>>, bu20>::result;
} // namespace list_last_tests
```

### Registering Tests

Add to `test/categories/lists/lists.hh`:
```cpp
#include "last.hh"
```

### Running Tests

```bash
g++ -std=c++23 -pedantic -Itxx main.cc -o /dev/null
```

If it compiles, all tests pass!

---

## Common Pitfalls

### 1. Template Specialization Ambiguity

**Problem**: Multiple specializations match with equal specificity.

```cpp
// These are ambiguous for Take<bu0, List<>>:
template <Any_t... Elems>
struct Take<BigUnsigned<>, List<Elems...>>;  // N=0, any list

template <BigUnsigned_t N>
struct Take<N, List<>>;  // Any N, empty list
```

**Solution**: Add explicit most-specific case:

```cpp
template <>
struct Take<BigUnsigned<>, List<>>  // N=0, empty list
{
    using result = List<>;
};
```

### 2. Include Order Matters

**Problem**: Polymorphism fails because specialization isn't loaded yet.

```cpp
// This fails if casts/big_unsigned.hh isn't included
using x = Sub_v<bu5, bu3>;  // "Polymorphism failed to find a valid type"
```

**Solution**: Include dependencies explicitly in your test files, or ensure
txx.hh` is included first.

### 3. `static_assert(false)` in Templates

In C++23, `static_assert(false)` in a template is **only evaluated when
instantiated**, as long as the template still has template parameters. This is
why the codebase uses patterns like:

```cpp
template <Any_t E1, Any_t E2>
struct AssertEq
{
    static_assert(false);  // Only fires when instantiated (no specialization matched)
};

template <Any_t T>
struct AssertEq<T, T>
{
    using result = True;  // This wins when types are equal
};
```

**Caveat**: This does *not* work for **full specializations** (`template <>`),
which have no remaining template parameters and are evaluated immediately:

```cpp
template <>
struct Head<List<>>
{
    static_assert(false, "Head: empty list");  // Would always fire!
};
```

The codebase avoids this by always keeping at least one template parameter in
specializations that need to fail.

### 4. Variadic `And_v`/`Or_v` Need At Least One Argument

**Problem**: `And_v<>` or `Or_v<>` with empty pack triggers static assert.

```cpp
// This fails
using result = And_v<head_ok, tail_ok>;  // If tail_ok comes from empty list...
```

**Solution**: Use `Ternary_v` for short-circuit evaluation:

```cpp
// Instead of And_v
using result = Ternary_v<head_ok, tail_ok, False>;
```

### 5. Recursive Functions Need Explicit Structs

**Problem**: You can't write inline recursive lambdas.

**Reality**: Every recursive computation needs a full struct with base case and
recursive case specializations. There's no way around this.

---

## Performance Considerations

Performance was *very obviously* not the point of this project. That said, even
though it was never a priority, things turn out to be surprisingly usable in
practice.

The C++ compiler effectively "memoizes" template instantiations: once a
particular `Foo<Bar, Baz>` has been computed, subsequent uses reuse that result
rather than recomputing it. This means that many recursive patterns—like
`Fibonacci_v<bu30>`—don't cause exponential blowup despite the naive recursive
definition.

However, if your computation generates a large number of *unique* instantiations
that cannot be shared, you will hit combinatory explosions. The compiler's
template cache can't help when every intermediate result is distinct.

---

## Debugging Tips

### 1. Read Error Messages Bottom-Up

Template errors show the instantiation stack. The actual error is often at the
top, but the cause is in the "requested here" chain.

### 2. Use Type Aliases to Inspect

```cpp
// Add this to see what type you're getting
using debug = YourExpression;
// Then trigger an error to see it:
static_assert(sizeof(debug) == 0);
```

### 3. Simplify First

If something fails, test with the simplest possible inputs:

```cpp
// Instead of debugging Filter on a complex predicate:
using _debug = AssertEq<Filter_v<IdentityPred, List<True>>, List<True>>::result;
```

### 4. Check Include Order

If you get "polymorphism failed", check that all required specializations are
included before the point of use.

---

## Checklist for New Features

- [ ] Create `functions/base/foo.hh` with forward declaration
- [ ] Create `<domain>/ops/foo.hh` with specializations
- [ ] Add include to `functions/base.hh`
- [ ] Add includes to `txx/txx.hh`
- [ ] Create test file in `test/categories/`
- [ ] Register test in appropriate `*.hh` aggregator
- [ ] Run full test suite: `g++ -std=c++23 -pedantic -Itxx main.cc`
- [ ] Test edge cases (empty list, zero, etc.)
