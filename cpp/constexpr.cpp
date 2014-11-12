#include <iostream>

constexpr auto hipass(int input) -> int
{
  return input;
}

auto main() -> int
{
  using namespace std;

  cout << "비밀번호를 입력해보렴 : " << flush;
  int a;
  cin >> a;
  int b = hipass(a);
  cout << "비밀번호 : " << b << endl;

  return 0;
}
