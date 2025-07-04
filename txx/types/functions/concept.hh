#pragma once

#include "types/functions/function.hh"

// The initial plan was to have functions just be templated structure that
// exposes a `result` typealias to the result of the function. So the concept
// would have been like this:
#if 0
template <typename T>
concept Function_t = requires { T::result; };
#endif
//
// The issue is that this representation would have required passing Non-fully
// specialized templates as template parameter, a template of template if you
// will, in order to have first order functions. For instance consider the
// Combine function who takes 2 functions and calls one with the result of the
// other:
#if 0
template <Function_t F, Function_t G, Any_t... Args>
struct Combine
{
    using result = F<typename G<Args...>::result>::result;
};
#endif
//
// Here, F and G are not yet fully specialized, and Args is used to specialize
// them, which is a big no-no in C++.
//
// The solution is to have function have an `apply` nested templated structure
// who takes the argument and exposes the result.
#if 0
struct Combine
{
    template <Function_t F, Function_t G, Any_t... Args>
    struct apply
    {
        using result = F::template apply<
            typename G::template apply<Args...>::result>::result;
    };
};
#endif
//
// It's not exactly easy on the eyes, but it has the strong advantage to work.
//
// Then there is the issue at hand, defining a concept to keep a sens of strong
// typing. The 2 main solutions would be a dummy probe structure that I use to
// try and instantiate the apply nested struct of the given function like this:
#if 0
struct DummyArg {};

template <typename Foo>
concept Function_t = requires {
    Foo::template apply<DummyArg>::result;
};
#endif
// But that would require *every concept* and *every arity* to accept our dummy
// arg, which is impracticle, and a bad design imho.
//
// The other solution is to have a "tag", so a basic type alias with a special
// name that would indicate that what we are dealing with is a function. Thus a
// our Combine function looks like so:
#if 0
struct Combine
{
    template <Function_t F, Function_t G, Any_t... Args>
    struct apply
    {
        using is_function = IsFunction;
        
        using result = F::template apply<
            typename G::template apply<Args...>::result>::result;
    };
};
#endif
//
// And our concept is just:

namespace FunctionConceptImpl
{
    void function_tag_t_stub(IsFunction);
    template <typename FuncTag>
    concept FunctionTag_t = requires(FuncTag tag) { function_tag_t_stub(tag); };

    template <typename Foo>
    concept Function_t = requires { typename Foo::is_function; }
        && FunctionTag_t<typename Foo::is_function>;
} // namespace FunctionConceptImpl

using FunctionConceptImpl::FunctionTag_t;
using FunctionConceptImpl::Function_t;
