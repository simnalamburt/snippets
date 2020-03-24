struct A {
  auto& operator++() { return *this; }
  auto& operator++(int) { return *this; }
  auto& operator+() { return *this; }
  auto& operator+(const A&) { return *this; }
};

int main() {
  A a;

  ++a++;
  ++++++++++++a++++++++++++;
  +a+++a+++++a+a+++++++++++++a+++++++++++a++;
}
