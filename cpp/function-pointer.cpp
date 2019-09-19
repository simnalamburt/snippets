// g++ --std=c++11 function-pointer.cpp
#include <cstdio>

//
// 아래 함수 선언들은 모두 같은 의미의 코드를 다르게 작성한것이다.
//

int (*func(int))(int*, int);

// func 자리를 빈칸으로 대체한 후 using 문 사용
using MyFunc = int (*(int))(int*, int);
MyFunc func;

// (*(int)) 자리를 retfunc 로 대체하고
// (*(int)) 는 그대로 MyFunc에 대입
// MyFunc는 이제 retfunc의 포인터를 반환하는 함수이다
int retfunc(int*, int);
using MyFunc = decltype(retfunc) (*(int));
MyFunc func;

// retfunc의 타입도 retfunc 자리를 그대로 빈칸으로 바꾼 뒤 using문으로 풀어씀
using RetFunc = int (int*, int);
using MyFunc = RetFunc (*(int));
MyFunc func;

// 함수의 포인터랑 함수를 반환하는 포인터는 다른데, 기호가 비슷해서 헷갈리므로
// 아래와 같이 풀어씀
//
// bla (*(int))     함수 'int -> bla*' (포인터를 반환하는 함수)
// bla (*)(int)     함수 'int -> bla'에 대한 포인터 (함수의 포인터)
using RetFunc = int (int*, int);
using RetFuncPtr = RetFunc*;
using MyFunc = RetFuncPtr (int);
MyFunc func;

// ret(param1, param2, ...) 이 표기가 헷갈린다면 아래와 같이 다르게 쓸 수 있음
using RetFunc = auto (int*, int) -> int;
using RetFuncPtr = RetFunc*;
using MyFunc = auto (int) -> RetFuncPtr;
MyFunc func;

// 한줄로 쓰면 이렇게 됨
using MyFunc = auto (int) -> auto (*)(int*, int) -> int;
MyFunc func;

// func 사용법
int main() {
  // 함수 func() 를 호출하면 retfunc에 대한 포인터가 나옴
  RetFuncPtr retfuncptr = func(10);

  // 함수포인터 retfuncptr() 을 호출할 수 있음
  int ret = retfuncptr(nullptr, 20);
}

auto func(int num) -> RetFunc* {
  printf("func(%d) 호출됨\n", num);
  return retfunc;
}

int retfunc(int* ptr, int num) {
  printf("retfunc(%p, %d) 호출됨\n", ptr, num);
  return 0;
}
