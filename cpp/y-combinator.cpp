#include <iostream>

int main() {
  using std::cout;
  using std::endl;
  using u64 = unsigned long long;

  auto y = [](auto&& f0) {
    return [f0=std::forward<decltype(f0)>(f0)](auto&&...args) {
      return f0(f0, std::forward<decltype(args)>(args)...);
    };
  };

  auto a = [](const auto& f, u64 n) -> u64 {
    return n == 0 ? 1 : n * f(f, n - 1);
  };

  auto b = y(a);

  cout << "fact(15) = " << b(15) << endl;
  return 0;
}
