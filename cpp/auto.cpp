//
// $ g++ -std=c++14 auto.cpp
// $ ./a.out
// void (*)(int, int)
//
// $ clang++ -std=c++14 auto.cpp
// $ ./a.out
// void (*)(int, int)
//

#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;


//
// Compile-time typename
//
struct slice {
  const char* const data;
  const long size;
};

ostream& operator<<(ostream& o, const slice &s) { return o.write(s.data, s.size); }

template<class T>
constexpr slice type_name() {
  auto begin = __PRETTY_FUNCTION__;

  while (*begin != '=') { ++begin; };
  ++begin;
  while (*begin == ' ') { ++begin; };

  auto end = begin;
  for (size_t count = 1; count > 0; ++end) {
    switch (*end) {
    case '[': ++count; break;
    case ']': --count; break;
    }
  }

  return { begin, end - begin - 1 };
}


//
// Entry point
//
void foo(int a, int b) { }
int main() {
  auto boo = foo;

  boo(3, 5);
  cout << type_name<decltype(boo)>() << endl;
}
