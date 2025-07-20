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

### Entry point

You have 2 things for an entry point, a `prelude.txx`, and a `body.txx` file.
The prelude is functions you may need before the body of your main function,
it's like the context of your program. The body is the *content* of the `struct
Main` implementation. It is akin to the body of a main function in other
languages.

You ought to change the paths to files in `main.hh` to your paths to
`prelude.txx` and `body.txx`.

> Note: These files can be named anything really, just include them accordingly
in `main.hh`.

For example, the [factorial](./samples/factorial) sample can be compiled with the following command:
```sh
42sh$ # -std=c++23 -pedantic: c++ standard to use, pendantic to not use language
42sh$ #                       extension (you can also activate most warnings)
42sh$ # -D_TXX_SKIP_TESTS: Tests take (at the time I write this) about 1.5s to
42sh$ #                    run, better skipping them if you don't need them
42sh$ # -D_TXX_MAIN: Enable Main function, those last 2 flags might have their
42sh$ #              defaults flipped later on, but whilst I'm still in
42sh$ #              development phase, I'd rather have those defaults
42sh$ # -D_TXX_INPUT: the value of the `Input` type in `body.txx`
42sh$ # -Itxx: Include path
42sh$ g++ -std=c++23 -pedantic -D_TXX_SKIP_TESTS -D_TXX_MAIN -D_TXX_INPUT="bu10" -Itxx main.cc
```

### Booleans:

<details>
<summary>Boolean Operation</summary>

- [x] Literals
- [x] And
- [x] Not
- [x] Or
- [x] Xor

</details>

### Numbers

Since we are doing a whole new language from scratch, numeric types and
arithmetic doesn't exist, we ought to recreate it.

<details>
<summary>Unsigned Numbers</summary>

<details>
<summary>BigUnsigned</summary>

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
- [ ] NEQ

</details>

<details>
<summary>Unsigned8 Numbers</summary>

- [x] Incrementation
- [x] Decrementation
- [x] Addition
- [x] Subtraction
- [x] LeftShift
- [x] RightShift
- [x] Multiplication
- [x] Division
- [x] Mod
- [x] LT
- [x] LE
- [x] GT
- [x] GE
- [x] EQ
- [ ] NEQ

</details>

<details>
<summary>Unsigned32 Numbers</summary>

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
- [ ] NEQ

</details>

</details>

<details>
<summary>Signed Numbers</summary>

<details>
<summary>Signed8 Numbers</summary>

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
- [ ] NEQ

</details>

<details>
<summary>Signed32 Numbers</summary>

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
- [ ] NEQ

</details>

</details>

<details>
<summary>Floating Point numbers</summary>

If I want to support more usecases, I *should* support floating point numbers,
or rather, IEEE754 binary single and double precision numbers.

binary16 is practicly useless, representation space is narrow and approximations
are big, and decimal floating point is for non computer people (who - in all
likelyhood - won't use this).

<details>
<summary>Single Precision</summary>

<details>
<summary>Constants</summary>

- [ ] +Zero
- [ ] -Zero
- [ ] +Inf
- [ ] -Inf
- [ ] Epsilon

</details>

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
- [ ] NEQ

</details>

<details>
<summary>Double Precision</summary>

<details>
<summary>Constants</summary>

- [ ] +Zero
- [ ] -Zero
- [ ] +Inf
- [ ] -Inf
- [ ] Epsilon

</details>

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
- [ ] NEQ

</details>
</details>

Maybe I'll investigate also doing a Dedekind–Peano Natural Number Type.

### Strings

Char can be aliased to u8, but with different literals, then strings would be
a variadic char list.

Many strings functions will be shared with the `List` type so either c/c, or
convertion into call into conversion. C/C would be shallower, but conversion
would be more explicit.

### Lists

List of values (types). A list doesn't need to have a single type of value
inside of it.

<details>
<summary>List operations</summary>

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

</details>

### Functions

Functions ought to be first order citizen, and they are, through trickery.

With the way they are architectured, I should be able to do most of what every
respectable functional language does like monads, curry, stuff like that.

<details>
<summary>Functions utilities and tools</summary>

- [x] Functions
- [x] Apply
- [x] Ternary
- [ ] Combine
- [x] Curry
- [ ] Uncurry

</details>

### Others

Structures that would be nice to have natively:
- [ ] Sets
- [ ] Maps
- [ ] Graphs

- Tuples: since the list I have has many types already, they kinda are tuples,
  but formalizing a tuple type would allow for some practicle things, like
  wrapping a result type in a tuple that can be converted back to a parameter
  pack and vice-versa (since we can't do `using result = ParameterPack...;`)
