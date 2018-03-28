// C++11
#include <unordered_set>
#include <vector>
#include <random>
#include <string>
#include <iostream>

constexpr int64_t ipow(int64_t base, int exp, int64_t result = 1) {
    return exp < 1 ? result : ipow(base*base, exp/2, (exp % 2) ? result*base : result);
}

int main() {
    using namespace std;

    constexpr size_t desired_count = 1000000;
    constexpr size_t code_digit_count = 6;

    constexpr size_t upper_bound = ipow(16, code_digit_count);

    random_device device;
    default_random_engine gen(device());
    uniform_int_distribution<uint32_t> dist(0, upper_bound - 1); // [0, upper_bound - 1]

    unordered_set<uint32_t> selected;

    for (size_t i = 0; i < desired_count; ++i) {
        uint32_t int_code;
        do {
            int_code = dist(gen);
        } while (selected.find(int_code) != selected.cend());
        selected.insert(int_code);
    }

    vector<string> codes;
    codes.reserve(desired_count);
    for (const auto int_code : selected) {
        char buffer[7];
        sprintf(buffer, "%06x", int_code);
        codes.emplace_back(buffer);
    }

    for (const auto code : codes) {
        cout << code << '\n';
    }
}
