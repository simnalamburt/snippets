#include <array>
#include <iostream>

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
  array<char, 16> chars {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
  };

  cout << "chars.size()       : " << chars.size() << endl;
  cout << endl;
  cout << "type of &chars     : " << type_name<decltype(&chars)>() << endl;
  cout << "type of &chars[0]  : " << type_name<decltype(&chars[0])>() << endl;
  cout << endl;
  cout << "value of &chars    : " << &chars << endl;
  cout << "value of &chars[0] : " << static_cast<void*>(&chars[0]) << endl;
}
