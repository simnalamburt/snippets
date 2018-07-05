#include <string>
#include <iostream>
#include <cxxabi.h>

using namespace std;

int main() {
  try {
    // throws length_error
    string("abc").substr(10);
  } catch(const exception& e) {
    int stat;
    const auto name = abi::__cxa_demangle(typeid(e).name(), nullptr, nullptr, &stat);
    if (stat != 0) { return 1; }

    cout << name << endl;

    free(name);
  }
}
