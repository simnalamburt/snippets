#include <iostream>
#include <array>
using namespace std;

int main()
{
  array<int, 10> List;
  //     │    └ 배열의 길이 
  //     │   
  //     └ int<- 배열 각 원소의 자료형
  //
  // C++ : array<double, 10> Baeyoul;
  //  C  : double[10] Baeyoul;
  // 위의 두개가 같음
  
  cout << "숫자를 열개정도 던져보아라" << endl;
  for (int i=0; i<10; ++i)
  {
    cin >> List[i];
  }

  cout << "List *= 2" << endl;
  for (int i=0; i<10; ++i)
  {
    List[i] = List[i] * 2;
  }

  cout << "List = { ";
  for (int i=0; i<10; ++i)
  {
    cout << List[i] << " ";
  }
  cout << "};" << endl;
}
