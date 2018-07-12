#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  const auto getenv_or = [](auto env_var, auto default_value) {
    const auto env = getenv(env_var);
    return env != nullptr ? env : default_value;
  };


  cout << getenv_or("HOME", "Not found") << endl;
  cout << getenv_or("HOMEE", "Not found") << endl;
}
