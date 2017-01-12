// My little constexpr experiment
//
//     g++ -std=c++14 switch.cpp
//     ./a.out

#include <iostream>
#include "vendor/cx_md5.h"

constexpr auto h(const char* input) {
  auto &&hash = cx::md5(input);
  constexpr size_t len = 4;

  static_assert(std::is_same<decltype(hash.h), uint32_t[len]>::value);
  __uint128_t ret = 0;
  for (size_t i = 0; i < len; ++i) {
    ret += static_cast<__uint128_t>(hash.h[i]) << (32*i);
  }
  return ret;
}
auto h(const std::string &input) { return h(input.c_str()); }

auto main() -> int {
  using namespace std;

  cout << "PPAP : " << flush;

  string input;
  cin >> input;

  switch(h(input)) {
  case h("pen"):    cout << "I have a pen" << endl; break;
  case h("apple"):  cout << "I have an apple" << endl; break;
  default:          cout << "Ugh (" << input << ")" << endl;
  }
}


//
// These functions are not used. Defined for debug purpose.
//
/*
#include <iomanip>

namespace unused {
  using namespace std;

  //
  // Print `__uint128_t` type values.
  //
  ostream &operator<<(ostream &os, const __uint128_t& value) {
    // Get baseflag to restore it later
    auto &&baseflag = os.flags() & ios_base::basefield;
    auto &&fillchar = os.fill();

    // Override baseflag
    os.setf(ios_base::hex, ios_base::basefield);
    os.fill('0');

    os << "0x" <<
      setw(16) << static_cast<uint64_t>(value >> 64) <<
      setw(16) << static_cast<uint64_t>(value);

    // Restore baseflag
    os.setf(baseflag, ios_base::basefield);
    os.fill(fillchar);

    return os;
  }


  //
  // Print `md5sum` type values.
  //
  ostream &operator<<(ostream &target, const cx::md5sum &hash) {
    ostringstream buffer;
    buffer << hex << setfill('0');

    buffer << '"';
    static_assert(is_same<decltype(hash.h[0]), const uint32_t&>::value);
    for (uint32_t bytes : hash.h) {
      buffer
        << setw(2) << (bytes & 0x000000ff) / 0x00000001
        << setw(2) << (bytes & 0x0000ff00) / 0x00000100
        << setw(2) << (bytes & 0x00ff0000) / 0x00010000
        << setw(2) << (bytes & 0xff000000) / 0x01000000;
    }
    buffer << '"';

    return target << buffer.str();
  }
}

*/
