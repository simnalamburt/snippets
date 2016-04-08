//
// C 스타일 배열을 템플릿 인자로 쓸 수 있습니다.
//
//     clang++ -std=c++1z -O3 array-template.cpp
//

#include <iostream>

template<typename T, size_t N>
constexpr size_t length(T (&array)[N]) { return N; }

int main() {
  using namespace std;

  int arr1[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int arr2[] { 1, 2, 3, 4, 5 };
  const char *arr3[] { "cat", "mother", "dog", "john" };

  cout <<
    "length(arr1) = " << length(arr1) << "\n"
    "length(arr2) = " << length(arr2) << "\n"
    "length(arr3) = " << length(arr3) << endl;
}
