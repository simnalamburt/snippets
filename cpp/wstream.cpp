#include <iostream>
#include <fstream>

using namespace std;

int main() {
  wifstream file("cout.cpp");
  wstring line;
  getline(file, line);
  wcout << line << endl;
}
