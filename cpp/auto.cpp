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

int main() {
  //
  // 아래 위치에 타입을 알고싶은 표현식을 쓰시면 됩니다
  //                          vvvvvvvv
  cout << type_name<decltype( 2 / 3    )>() << endl;
  cout << type_name<decltype( 2 / 3.0f )>() << endl;
  cout << type_name<decltype( 1 + 2i   )>() << endl;
}
