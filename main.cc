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

#ifdef _TXX_MAIN
// Your code needs to go in MainImpl::Main structure
using result = Main_v<Input>;
#else
#    pragma message("Skipping main function")
#endif

// This is just a symbol so that the program compiles, use the Main class for
// the real entry point
int main(void)
{}
