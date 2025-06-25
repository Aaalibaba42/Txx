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
  - [x] Multiplication
  - [ ] Division
  - [ ] Comparison
- [ ] Signed Numbers
  - [ ] Incrementation
  - [ ] Addition
  - [ ] Subtraction
  - [ ] Multiplication
  - [ ] Division
  - [ ] Comparison
- [ ] IEEE754
  - [ ] Incrementation
  - [ ] Addition
  - [ ] Subtraction
  - [ ] Multiplication
  - [ ] Division
  - [ ] Comparison

#### Lists

I don't aim to do these unless I need to. These are just ideas of the kind
of things I'd be capable of doing.

- [x] Prepend
- [x] Append
- [x] Reverse
- [ ] AllOf
- [ ] NoneOf
- [ ] Map
- [ ] Reduce
- [ ] FoldL
- [ ] FoldR
- [ ] i-th
- [ ] Concat

#### Others

Structures that would be nice to have natively:
- [ ] Sets
- [ ] Maps
- [ ] Graphs

### Control Flow

- [x] Ternary
