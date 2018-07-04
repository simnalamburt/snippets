#include <array>
#include <string>
#include <random>
#include <iostream>

using namespace std;

int main() {
  random_device device;
  mt19937_64 prng { device() };
  array<char, 16> chars {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
  };
  uniform_int_distribution<size_t> dist { 0, chars.size() - 1 };
  string result;
  generate_n(back_inserter(result), 32, [&] { return chars[dist(prng)]; });

  cout << result;
}
