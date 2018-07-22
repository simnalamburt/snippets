// utf-8.cpp
// ========
//
// Note: <codecvt> is deprecated.
//
// ###### Reference
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0618r0.html

#include <cstdio>
#include <locale>
#include <codecvt>

int main() {
  using namespace std;

  const auto input = "한글! ㅇㅅㅇ >ㅅㅇ"s;

  // Convert UTF-8 string into UCS-4 (UTF-32)
  wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
  const auto ucs4string = converter.from_bytes(input);

  // Loop over each character of UCS-4 string
  for (auto codepoint : ucs4string) {
    // Convert single UCS-4 character into UTF-8 character
    const auto ch = converter.to_bytes(u32string { codepoint });

    printf("'%s'\tU+%X\n", ch.c_str(), codepoint);
  }
}
