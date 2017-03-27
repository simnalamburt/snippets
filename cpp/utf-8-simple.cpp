#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
  using namespace std;

  // 컨버터 생성
  wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;

  // 마구 변환해벌임
  string input = "한글! ㅇㅅㅇ >ㅅㅇ";
  u32string converted = converter.from_bytes(input);

  // UTF-32 글자 하나마다 루프 돌아벌임
  for (auto c : converted) {
    // UTF-32 글자를 다시 UTF-8 로 돌려벌임
    string original = converter.to_bytes(u32string { c });

    cout << "글자: '" << original << "'" << endl;
    cout << "글자코드: " << c << endl;
    cout << endl;
  }
}
