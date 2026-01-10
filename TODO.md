# Txx Feature Roadmap

This file tracks implemented features and planned work.

---

## Booleans

- [x] Literals (`True`, `False`)
- [x] And
- [x] Not
- [x] Or
- [x] Xor
- [ ] Nand
- [ ] Nor
- [ ] Implication

---

## Numbers

### BigUnsigned (arbitrary precision)

- [x] Literals (`bu0` - `bu255`)
- [x] Increment
- [x] Decrement
- [x] Addition
- [x] Subtraction
- [x] Multiplication
- [x] Division
- [x] Mod
- [x] LeftShift
- [ ] RightShift
- [x] LT / LE / GT / GE / EQ
- [ ] NEQ
- [ ] Min / Max
- [ ] Abs
- [ ] Power / Exponentiation
- [ ] GCD / LCM
- [ ] IsEven / IsOdd
- [ ] Bitwise And / Or / Xor / Not

### Unsigned8 (8-bit)

- [x] Literals (`u8_0` - `u8_255`)
- [x] Increment
- [x] Decrement
- [x] Addition
- [x] Subtraction
- [x] Multiplication
- [x] Division
- [x] Mod
- [x] LeftShift
- [x] RightShift
- [x] LT / LE / GT / GE / EQ
- [ ] NEQ
- [ ] Min / Max
- [ ] IsEven / IsOdd
- [ ] Bitwise And / Or / Xor / Not

### Unsigned16 (16-bit)

- [ ] Type definition
- [ ] All arithmetic operations
- [ ] All comparison operations

### Unsigned32 (32-bit)

- [ ] Type definition
- [ ] All arithmetic operations
- [ ] All comparison operations

### Signed8 (8-bit signed, two's complement)

- [ ] Type definition
- [ ] Literals
- [ ] Negation
- [ ] Increment / Decrement
- [ ] Addition / Subtraction
- [ ] Multiplication / Division / Mod
- [ ] Comparisons
- [ ] Abs / Sign

### Signed32 (32-bit signed)

- [ ] Type definition
- [ ] All operations

### Floating Point (IEEE 754)

Low priority, complex to implement correctly.

#### Single Precision (32-bit)

- [ ] Type definition
- [ ] Constants (+Zero, -Zero, +Inf, -Inf, NaN, Epsilon)
- [ ] Addition / Subtraction
- [ ] Multiplication / Division
- [ ] Comparisons
- [ ] Conversions to/from integers

#### Double Precision (64-bit)

- [ ] Type definition
- [ ] All operations

### Peano Numbers

- [ ] Peano naturals (unary representation)
- [ ] All operations

---

## Lists

- [x] Type definition (`List<...>`)
- [x] Prepend
- [x] Append
- [x] Concat
- [x] Head
- [x] Tail
- [x] Nth
- [x] Set (set nth element)
- [x] Length
- [x] IsEmpty
- [x] Reverse
- [x] Take
- [x] Drop
- [x] Map
- [x] Filter
- [x] FoldL
- [x] FoldR
- [x] All (all elements satisfy predicate)
- [x] Any (any element satisfies predicate)
- [x] Zip
- [x] ZipWith
- [ ] NoneOf (negation of Any)
- [ ] Find (first element matching predicate)
- [ ] FindIndex
- [ ] Elem / Contains
- [ ] Maximum / Minimum
- [ ] Sort
- [ ] Unique / RemoveDuplicates
- [ ] SplitAt
- [ ] Span
- [ ] TakeWhile / DropWhile
- [ ] Partition
- [ ] Replicate
- [ ] Flatten (for nested lists)
- [ ] GroupBy
- [ ] Subsequences
- [ ] Permutations

---

## Functions & Combinators

- [x] Apply
- [x] Ternary (if-then-else)
- [x] Combine (composition: `f . g`) (TODO Rename `Combine` to `Atop`)
- [x] Curry (partial application)
- [x] Flip (swap arguments)
- [x] Const (always return first arg)
- [x] Id (identity)
- [x] On ((f `on` g) x y = f (g x) (g y)) (TODO Rename `On` to `Over`)
- [ ] Before (f `before` g) x y = g (f x) y
- [ ] After (f `after` g) x y = g x (f y)
- [ ] Uncurry
- [ ] Fix (fixed-point combinator for recursion)

---

## Tuples & Pairs

- [ ] Pair type (`Pair<A, B>`)
- [ ] First / Second
- [ ] Swap
- [ ] Tuple type (`Tuple<...>`)
- [ ] Nth for tuples
- [ ] Conversion to/from List

---

## Maybe / Optional

- [ ] Maybe type (`Just<T>` / `Nothing`)
- [ ] IsJust / IsNothing
- [ ] FromMaybe (with default)
- [ ] Maybe map / bind

---

## Strings

Strings as `List<Char>` where `Char` is aliased to `Unsigned8`.

- [ ] Char type alias
- [ ] String literals
- [ ] Char comparison
- [ ] IsDigit / IsAlpha / IsSpace / etc.
- [ ] ToUpper / ToLower
- [ ] String concatenation
- [ ] String split
- [ ] String parsing

---

## Data Structures

### Set

- [ ] Set type (sorted list? tree?)
- [ ] Insert / Remove
- [ ] Contains
- [ ] Union / Intersection / Difference
- [ ] IsSubset

### Map / Dictionary

- [ ] Map type (list of pairs? tree?)
- [ ] Insert / Remove / Update
- [ ] Lookup
- [ ] Keys / Values
- [ ] FromList / ToList

### Tree

- [ ] Binary tree type
- [ ] Insert / Search
- [ ] Traversals (inorder, preorder, postorder)
- [ ] Balanced trees

### Graph

- [ ] Graph representation (adj list?)
- [ ] BFS / DFS
- [ ] Shortest path
- [ ] Topological sort

---

## Type Conversions

I won't enumerate all of them but I can't really make them automagic either.

---

## Utility

- [x] Assert / AssertEq / AssertNeq
- [x] IsSame (type equality)
- [ ] Print / Debug output (Is it even possible ?)

---

## Ideas & Experiments

- [ ] Monads (Maybe monad, List monad, etc.)
- [ ] Applicative functors
- [ ] Church encoding alternatives
- [ ] Lambda calculus primitives

---

## Meta / Tooling

- [ ] Figure out I/O
- [ ] Better error messages (constrained static_assert)
- [ ] Compile time measurement/profiling
- [ ] Documentation generator
- [ ] More samples/examples

