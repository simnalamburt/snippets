#include <iostream>
#include <random>

using namespace std;

uint64_t random_u64() {
  static thread_local mt19937 prng { random_device { } () };
  uniform_int_distribution<uint64_t> dist;
  return dist(prng);
}

int main() {
  for (size_t i = 0; i < 10; ++i) {
    cout << random_u64() << endl;
  }
}
