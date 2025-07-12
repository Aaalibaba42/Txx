#include "main.hh"

#ifndef _TXX_SKIP_TESTS
#    pragma message("Launching Tests, define `-D_TXX_SKIP_TESTS` to disable")
#    include "test/tests.hh"
#endif

#ifndef _TXX_INPUT
#    pragma message("No input were provided")
using Input = Unit;
#else
using Input = _TXX_INPUT;
#endif

// Your code needs to go in MainImpl::Main structure
using result = Main_v<Input>;

// This is just a symbol so that the program compiles
int main(void)
{}
