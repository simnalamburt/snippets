#include <vector>
#include <iostream>

using namespace std;

void foo(const vector<int> &list = { 1, 2, 3 }) {
  for (auto elem : list) {
    cout << elem << ' ';
  }
  cout << endl;
}

void bar(int a = []{ cout << "bar 호출됨" << endl; return 42; } ()) { }

int main() {
  foo();
  bar();
  bar();
  bar();
  bar(10);
  bar(100);
}
