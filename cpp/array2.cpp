#include <array>
#include <iostream>

using namespace std;

int main() {
  array<char, 16> chars {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
  };

  cout << chars.size() << endl;
}
