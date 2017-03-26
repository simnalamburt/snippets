// utf-8.cpp
// ========
//
// Note: <codecvt> is deprecated.
//
// ###### Reference
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0618r0.html

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
  using namespace std;

  cout << "문자열을 입력해보아요: " << flush;

  string input;
  getline(cin, input);

  // Convert UTF-8 string into UTF-32 (UCS-4)
  wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
  auto utf32string = conv.from_bytes(input);

  cout << endl;
  for (auto c : utf32string) {
    char32_t temp[1] = { c };
    auto ch = conv.to_bytes(temp, temp + 1);

    cout << "'" << ch << "' U+" << hex << uppercase << c;
    if (U'가' <= c && c <= U'힣') {
      cout << " (Hangul syllable)";
    }
    cout << endl;
  }
}
