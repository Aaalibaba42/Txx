typesystem_aoc
==============

I was very much inspired my former colleague's
[funxx](https://github.com/VokunGahrotLaas/funxx), but wanted to go even
further.


Basicly the goal is to create a functional language using only the C++
typesystem.

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

These are not working yet, I've got a fulladder that should work but honestly
it's guess work at this point

#### Lists

There is a typelist, it takes any type indiscreminately, has a (curr :: rest)
architecture

### Control Flow

- [x] If
- [ ] While
- [ ] For
