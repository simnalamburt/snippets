#include <iostream>

using namespace std;

int main() {
    auto f = [](auto...x) {
        [](...){}((cout << x << endl, 0)...);
    };

    f("Very", "Inconvenient", "To", "Iterate");

    return 0;
}
