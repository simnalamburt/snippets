#include <iostream>
#include <sstream>

using namespace std;

int main() {
  stringstream buf { "This string will be overwritten." };

  buf << "0x" << hex << 12345 << " (ㅇㅅㅇ)";

  cout << buf.str() << endl;
}
