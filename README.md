Txx
===

I was very much inspired my former colleague's
[funxx](https://github.com/VokunGahrotLaas/funxx), but wanted to go even
further.


Basicly the goal is to create a functional language using only the C++
typesystem. No literals, No standard library, no constexpr, just the Typesystem.

The goal would be to be able to solve a few [Advent of
Code](https://adventofcode.com/) exercises using only this.

Features
--------

### Types

#### Booleans:

- [x] Literals
- [x] And
- [x] Not
- [x] Or
- [x] Xor


#### Numbers

- [x] Unsigned Numbers:
  - [x] Incrementation
  - [x] Addition
  - [x] Subtraction
  - [x] LeftShift
  - [ ] RightShift
  - [x] Multiplication
  - [ ] Division
  - [ ] LT
  - [ ] LE
  - [ ] GT
  - [ ] GE
  - [ ] EQ
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

#### Lists

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

#### Functions

Functions ought to be first class objects. I guess a function is "just" a
structure which takes template parameters and has a Result of a certain type.

#### Others

Structures that would be nice to have natively:
- [ ] Sets
- [ ] Maps
- [ ] Graphs

### Control Flow

- [x] Ternary
