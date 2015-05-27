#include <vector>
#include <iostream>

using namespace std;

class A {
public:
  virtual void foo() { cout << "A-"; }
};

class B : public A {
public:
  void foo() { cout << "B-"; }
};

class C : public A {
public:
  void foo() { cout << "C-"; }
};

class Z {
  vector<A*> data;

public:
  void AddA(A& shit) {
    data.push_back(&shit);
  }

  void Foooooo() {
    for (A* elem : data) {
      elem->foo();
    }
  }
};

int main() {
  Z fuckyou;
  B b;
  C c;

  fuckyou.AddA(b);
  fuckyou.AddA(c);
  fuckyou.Foooooo();

  return 0;
}
