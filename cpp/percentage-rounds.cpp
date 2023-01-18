#include <string_view>
#include <algorithm>
#include <cmath>

std::string_view getPercentageRounds(double percentage) {
  auto blue = percentage < 0 ? 10 : std::min<size_t>(std::ceil(percentage*10), 10);
  return { &"🔵🔵🔵🔵🔵🔵🔵🔵🔵🔵⚪⚪⚪⚪⚪⚪⚪⚪⚪⚪"[40 - 4*blue], 30 + blue };
}

#include <iostream>
int main() {
  double p;
  std::cin >> p;
  std::cout << getPercentageRounds(p) << std::endl;
}
