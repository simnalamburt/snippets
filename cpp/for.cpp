#include <iostream>
#include <vector>

int main() {
  using namespace std;

  vector<int> arr = { 1, 2, 3, 4, 5 };
  for (int elem : arr) {
    cout << elem << ' ';
  }
  cout << endl;

  arr.push_back(10);
  arr.push_back(12);
  arr.push_back(14);
  for (int elem : arr) {
    cout << elem << ' ';
  }
  cout << endl;

  arr.pop_back();
  arr.pop_back();
  arr.pop_back();
  arr.pop_back();
  arr.pop_back();
  for (int elem : arr) {
    cout << elem << ' ';
  }
  cout << endl;
}
