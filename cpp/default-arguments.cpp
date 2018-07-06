#include <vector>
#include <iostream>

using namespace std;

void foo(const vector<int> &list = { 1, 2, 3 }) {
  for (auto elem : list) {
    cout << elem << ' ';
  }
  cout << endl;
}

int main() {
  foo();
}
