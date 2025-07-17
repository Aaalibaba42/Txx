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

Entry point: the main thing would be doing a -D_TXX_INPUT=<input>, but then the
`input` must be formatted in the same way as the rest of the program. That might
be cheating, but since a compiler can't really wait for stdin, nor can I pass
raw strings, I guess I need to do this.

You can see an example of this in the `main.hh`.

It's not ideal, I'd like to be able to do a `main.txx` in which I write the
thing that would go *inside* `struct Main`. Preprocessor macro that would
"statically" include `main.txx` should work, but then the entry point is always
the file `main.txx` which sucks a bit. I don't think there is a way to do a
`#include FILENAME` and compile with `-DFILENAME='myfile.txx'`, but ultimately
that's what I would have liked to do. Something to ponder upon.

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
- [ ] Curry
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
