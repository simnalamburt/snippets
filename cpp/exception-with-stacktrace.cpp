// How to build:
//
//     # nlohmann/json.hpp and backward.hpp should be located at './includes/' directory
//     # See https://github.com/bombela/backward-cpp for further details
//
//     sudo apt-get install bintuils-dev
//     g++ -DBACKWARD_HAS_BFD=1 -std=c++11 -g -I./includes -o main.o -c main.cpp
//     g++ -g main.o -lbfd -ldl
//     ./a.out

//
// Override try/catch statments of nlohmann/json
//
template <typename T> struct wrapped_exception_impl;
#define JSON_THROW_USER(exception) throw wrapped_exception_impl<decltype(exception)>(exception)
#define JSON_TRY_USER try
#define JSON_INTERNAL_CATCH_USER(exception) catch(wrapped_exception_impl<std::remove_reference<exception>::type> &)

#include <type_traits>
#include <nlohmann/json.hpp>
#include <backward.hpp>

//
// Adding stacktrace information to the ordinary C++ exceptions
//
struct wrapped_exception : std::exception {
  backward::StackTrace stacktrace { [] {
    backward::StackTrace st;
    st.load_here(32);
    return st;
  } () };

  virtual ~wrapped_exception() = default;
  virtual const std::exception& get() const = 0;
  virtual const char* what() const noexcept final override { return get().what(); }
};

template <typename T>
struct wrapped_exception_impl : wrapped_exception {
  T exception;

  wrapped_exception_impl(const T &e) : exception(e) { }
  virtual ~wrapped_exception_impl() = default;
  virtual const std::exception& get() const override { return exception; }
};

//
// Program entry point
//
int main() try {
  const nlohmann::json obj {
    {"key1", "value1"},
    {"key2", "value2"},
  };

  obj.value("key2", 0);
  // NOTE: nlohmann/json will throw a wrapped exception at this point

} catch (wrapped_exception &exp) {

  //
  // You can see the stacktrace information at the time the exception occurred.
  //

  backward::Printer p;
  p.address = true;
  p.snippet = false;
  p.print(exp.stacktrace, stderr);

  fprintf(stderr, "\n\n\n%s\n", exp.what());

  return EXIT_FAILURE;
}
