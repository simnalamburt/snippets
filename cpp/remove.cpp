#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool even(int input) { return input % 2 == 0; };

void print(const vector<int> &vec) {
  for (const auto& i: vec) { cout << i << ' '; }
  cout << endl;
}

template <typename ForwardIt>
void print(ForwardIt begin, ForwardIt end) {
  while (begin != end) {
    cout << (*begin) << ' ';
    ++begin;
  }
  cout << endl;
}

int main() {
  vector<int> list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  print(list);
  auto first = remove_if(list.begin(), list.end(), even);
  print(list);
  list.erase(first, list.end());
  print(list);
}
