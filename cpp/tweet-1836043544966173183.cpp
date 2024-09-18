#include <iostream>

template<typename T>
void test() {
    static_assert(false, "Why?");
}

template<>
void test<int>() {
    std::cout << "int" << '\n';
}

int main()
{
    //test();
    test<int>();

    return 0;
}
