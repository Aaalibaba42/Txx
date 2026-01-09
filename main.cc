#ifndef _TXX_SKIP_TESTS
#    pragma message("Launching Tests, define `-D_TXX_SKIP_TESTS` to disable.")
#    include "test/tests.hh"
#endif

#ifdef _TXX_MAIN
#    include "main.hh"

#    ifndef _TXX_INPUT
#        pragma message("No input were provided.")
using Input = Unit;
#    else
using Input = _TXX_INPUT;
#    endif

using result = Main_v<Input>;
#else
#    pragma message("Skipping main function, use -D_TXX_MAIN to enable.")
#endif

// This is just a symbol so that the program compiles, you ought to use the
// `prelude.txx` and `body.txx` files included in the `main.hh` file for your
// program
int main(void)
{}
