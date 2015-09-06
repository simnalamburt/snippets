#include <iostream>
#include <string>

int main() {
  using namespace std;

  string str1, str2;
  char ch;

  cout << "Type something: ";
  cin >> str1 >> ch >> str2;

  cout << endl;
  cout << "String 1 : \"" << str1 << '"' << endl;
  cout << "Char     : '" << ch << '\'' << endl;
  cout << "String 2 : \"" << str2 << '"' << endl;
  cout << endl;

  return 0;
}

// Type something: sadfsd asdfasdf
//
// String 1 : "sadfsd"
// Char     : 'a'
// String 2 : "sdfasdf"
