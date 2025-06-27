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

- [x] Unsigned Numbers:
  - [x] Incrementation
  - [x] Addition
  - [x] Subtraction
  - [x] LeftShift
  - [ ] RightShift
  - [x] Multiplication
  - [ ] Division
  - [x] LT
  - [x] LE
  - [x] GT
  - [x] GE
  - [x] EQ
- [ ] Signed Numbers
  - [ ] Incrementation
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
- [ ] IEEE754
  - Constants:
    - [ ] +Zero
    - [ ] -Zero
    - [ ] +Inf
    - [ ] -Inf
    - [ ] Epsilon
  - [ ] Incrementation
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

I don't aim to do these unless I need to. These are just ideas of the kind
of things I'd be capable of doing.

- [x] Prepend
- [x] Append
- [x] Reverse
- [ ] Set i-th
- [ ] AllOf
- [ ] NoneOf
- [ ] Map
- [ ] Reduce
- [ ] FoldL
- [ ] FoldR
- [ ] i-th
- [ ] Concat

### Functions

Functions ought to be first class objects. I guess a function is "just" a
structure which takes template parameters and has a Result of a certain type.

### Others

Structures that would be nice to have natively:
- [ ] Sets
- [ ] Maps
- [ ] Graphs

### Control Flow

- [x] Ternary

This is a function really, it takes an input and returns an output, it will be
moved and formalized as a function once 1st order functions are implemented.
