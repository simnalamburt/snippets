#include <iostream>

constexpr auto hipass(int input) -> int
{
  return input;
}

auto main() -> int
{
  using namespace std;

  constexpr const auto constant { "숫자를 입력해보세요 : " };

  cout << constant << flush;
  int a;
  cin >> a;
  int b = hipass(a);
  cout << "비밀번호 : " << b << endl;

  return 0;
}
