#include <ctime>
#include <iostream>
#include "date.h" // https://github.com/HowardHinnant/date

using namespace std;
using namespace std::chrono;
using namespace date;

int main() {
  cout << time(nullptr) << endl;
  cout << std::chrono::seconds(std::time(NULL)).count() << endl;

  cout << format("%FT%T", floor<seconds>(system_clock::now())) << endl;
  cout << format("%FT%T", sys_seconds { seconds { time(nullptr) } }) << endl;
}
