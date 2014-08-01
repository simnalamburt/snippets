#include <iostream>
#include <memory>

using namespace std;

struct Base
{
  virtual auto Do() -> void const = 0;
};

struct Derived1 : Base
{
  virtual auto Do() -> void const override
  {
    cout << "신선함!" << endl;
  }
};

struct Derived2 : Base
{
  virtual auto Do() -> void const override
  {
    cout << "힘세고 강한 아침!" << endl;
  }
};


template <typename T>
using ptr = unique_ptr<T>;

auto main() -> int
{
  ptr<Base> p1 = make_unique<Derived1>();
  ptr<Base> p2 = make_unique<Derived2>();

  p1->Do();
  p2->Do();

  return 0;
}
