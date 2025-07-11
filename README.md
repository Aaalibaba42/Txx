Txx
===

Basicly the goal is to create a functional language using only the C++ Type
System. No literals, No standard library, no constexpr, just the Typesystem.
In other words, there are 0 (zero) *values* in the code, just Types.

The goal would be to be able to solve a few [Advent of
Code](https://adventofcode.com/) exercises using only this.

I was very much inspired by my former colleague's
[funxx](https://github.com/VokunGahrotLaas/funxx), but wanted to go even
further.

Features
--------

### Booleans:

- [x] Literals
- [x] And
- [x] Not
- [x] Or
- [x] Xor

### Numbers

- [ ] Unsigned Numbers:
  - [x] BigUnsigned (Unbounded unsigned):
    - [x] Incrementation
    - [ ] Decrementation
    - [x] Addition
    - [x] Subtraction
    - [x] LeftShift
    - [ ] RightShift
    - [x] Multiplication
    - [x] Division
    - [x] Mod
    - [x] LT
    - [x] LE
    - [x] GT
    - [x] GE
    - [x] EQ
  - [x] Unsigned8:
    - [x] Incrementation
    - [x] Decrementation
    - [x] Addition
    - [x] Subtraction
    - [x] LeftShift
    - [x] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] Mod
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ
  - [ ] Unsigned32:
    - [ ] Incrementation
    - [ ] Decrementation
    - [ ] Addition
    - [ ] Subtraction
    - [ ] LeftShift
    - [ ] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] Mod
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ
- [ ] Signed Numbers
  - [ ] Signed8:
    - [ ] Incrementation
    - [ ] Decrementation
    - [ ] Addition
    - [ ] Subtraction
    - [ ] LeftShift
    - [ ] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ
  - [ ] Signed32:
    - [ ] Incrementation
    - [ ] Decrementation
    - [ ] Addition
    - [ ] Subtraction
    - [ ] LeftShift
    - [ ] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ
- [ ] IEEE754:
  - Float32:
    - Constants:
      - [ ] +Zero
      - [ ] -Zero
      - [ ] +Inf
      - [ ] -Inf
      - [ ] Epsilon
    - [ ] Incrementation
    - [ ] Decrementation
    - [ ] Addition
    - [ ] Subtraction
    - [ ] LeftShift
    - [ ] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ
  - Float64:
    - Constants:
      - [ ] +Zero
      - [ ] -Zero
      - [ ] +Inf
      - [ ] -Inf
      - [ ] Epsilon
    - [ ] Incrementation
    - [ ] Decrementation
    - [ ] Addition
    - [ ] Subtraction
    - [ ] LeftShift
    - [ ] RightShift
    - [ ] Multiplication
    - [ ] Division
    - [ ] LT
    - [ ] LE
    - [ ] GT
    - [ ] GE
    - [ ] EQ

Maybe I'll investigate also doing a Dedekind–Peano Natural Number Type.

### Lists

- [x] Prepend
- [x] Append
- [x] Reverse
- [ ] Set i-th
- [ ] AllOf
- [ ] NoneOf
- [x] Map
- [x] FoldL
- [x] FoldR
- [ ] i-th
- [ ] Concat

### Functions

- [x] Functions
- [x] Apply
- [x] Ternary
- [ ] Combine
- [ ] Curry
- [ ] Uncurry

### Others

Structures that would be nice to have natively:
- [ ] Sets
- [ ] Maps
- [ ] Graphs

- Tuples: since the list I have has many types already, they kinda are tuples,
  but formalizing a tuple type would allow for some practicle things, like
  wrapping a result type in a tuple that can be converted back to a parameter
  pack and vice-versa (since we can't do `using result = ParameterPack...;`)
