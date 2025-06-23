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
  - [ ] Addition
  - [ ] Soustraction
  - [ ] Multiplication
  - [ ] Division
  - [ ] Comparison
- [ ] Signed Numbers
  - [ ] Incrementation
  - [ ] Addition
  - [ ] Soustraction
  - [ ] Multiplication
  - [ ] Division
  - [ ] Comparison
- [ ] IEEE754
  - [ ] Incrementation
  - [ ] Addition
  - [ ] Soustraction
  - [ ] Multiplication
  - [ ] Division
  - [ ] Comparison

#### Lists

I don't aim to do these unless I need to. These are just ideas of the kind
of things I'd be capable of doing.

- [x] Prepend
- [x] Append
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

Do these even make sens ? I think having side effects is gonna be hard,
a functional language is better, and then having this kind of control structures
seem useless
- [ ] While
- [ ] For
