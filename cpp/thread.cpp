// g++ -std=c++11 thread.cpp

#include <array>
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

size_t counter = 0;
mutex counter_mutex;

int main() {
  cout << "메인 함수 실행됨\n";

  auto callback = []{
    lock_guard<mutex> lock(counter_mutex);

    // 상호배제 안쪽이라 이렇게 해도 안전함
    counter += 1;

    cout << "스레드 실행됨, counter = " << counter << endl;
  };

  // 같은 일 하는 스레드 네개 생성
  array<thread, 4> threads {
    thread { callback },
    thread { callback },
    thread { callback },
    thread { callback },
  };

  // 스레드 네개가 모두 종료될 때 까지 대기
  for (auto&& thrd : threads) { thrd.join(); }

  cout << "\ncounter = " << counter << endl;
}
