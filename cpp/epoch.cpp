#include <ctime>
#include <iostream>

using namespace std;

int main() {
  {
    auto epoch = time(nullptr);
    cout << epoch << endl;
  }

  {
    auto epoch = std::chrono::seconds(std::time(NULL)).count();
    cout << epoch << endl;
  }
}
