#include <iostream>

using namespace std;

class Data {
  int a, b;

public:
  Data() : a(100), b(200) { }

  int getA() const { return a; }
};

void print(const Data &object) {
  cout << object.getA() << endl;
}

int main() {
  Data object;

  print(object);
  print(object);
  print(object);
}
