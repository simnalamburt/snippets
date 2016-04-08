//
// Read-only field 를 만들기 위해 더미 클래스를 만드는것이 최적화에 악영향을
// 주는지 테스트하기 위해 만들어진 snippet
//
//     clang++ -std=c++1z -O3 -S -DFIELD field.cpp -o field.s.0
//     clang++ -std=c++1z -O3 -S         field.cpp -o field.s.1
//     vimdiff field.s.0 field.s.1
//
// ### 결과
//
//     const auto pos = anime.pos;
//     const auto pos = anime.get();
//
// 두 경우가 정확히 어셈블리 인스트럭션 딱 하나 차이남. 둘 다 값 복사인데,
// 전자의 경우 `movq`로 가져오고, 후자의 경우 `movsd`로 가져옴.
//
// 우려하던 바와 같이 불필요한 메모리 연산이 늘어나거나 하지는 않았음. 차이
// 없는걸으로 결론내림
//

#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>

//
// 쉬운 애니메이션 구현을 위한 클래스입니다.
//
//     Animator ani;        // 2초 주기를 갖는 애니메이터 생성 (기본값)
//     Animator ani { 5 };  // 5초 주기를 갖는 애니메이터 생성
//
//     ani.period = 15.0;   // 애니메이션 주기를 '15s'로 설정
//     ani.speed = 2.0;     // 애니메이션 속도를 '2 period/s'로 설정
//
//     void loop() {
//       ani.onLoop();      // Must be called in every loop
//
//       const auto current = ani.pos; // Get current *pos*
//
//       /* Do your jobs here... */
//     }
//
// 모든 Animator 객체는 [0.0, 1.0) 범위 안에서 변하는 숫자, pos를 갖고있습니다.
// pos는 0.0에서 시작하여 시간이 지남에 따라 조금씩 커지고, 1.0이 되는순간
// 0.0으로 돌아옵니다.
//
// Animator 클래스를 쓰기 위해선 매 프레임마다 일정한 간격으로 `onLoop()`
// 메서드를 호출해줘야합니다.
//
// 예제와 같이 `period` 프로퍼티의 값을 조절하여, pos가 증가하는 속도를
// 조절할 수 있습니다. `period`는 pos가 0.0에서 1.0이 되기까지 걸리는
// 시간(주기)이며, 단위는 초(second) 입니다. 기본 주기는 2초입니다.
//
struct Animator {
  using type = double;

private:
  type _pos = 0.0;
  type _speed; // Should be initialized with `period` field
  decltype(std::chrono::high_resolution_clock::now()) prevMillis = std::chrono::high_resolution_clock::now();

  struct Period {
    type& speed;
    explicit Period(type& ref): speed(ref) { }
    type operator=(type period) { return speed = 1.0/period; }
    operator type() const { return 1.0/speed; }
  };

  struct Speed {
    type& speed;
    explicit Speed(type& ref): speed(ref) { }
    type operator=(type given) { return speed = given; }
    operator type() const { return speed; }
  };

  struct Pos {
    type& pos;
    explicit Pos(type& ref): pos(ref) { }
    operator type() const { return pos; }
  };

public:
  Period period { _speed };
  Speed speed { _speed };
  Pos pos { _pos };

  explicit Animator(type initial_period = 2.0) {
    period = initial_period;
  }

  void onLoop() {
    using namespace std::chrono;

    const auto currentMillis = high_resolution_clock::now();
    const auto delta = duration<double>(currentMillis - prevMillis).count();
    prevMillis = currentMillis;

    _pos += _speed * delta;

    if (_pos >= 1.0) { _pos -= floor(_pos); }
  }

  type get() const { return _pos; }
};

int main() {
  using namespace std;

  Animator ani;

  ani.period = 2.0;

  while (true) {
    ani.onLoop();

#ifdef FIELD
    const auto pos = ani.pos;
#else
    const auto pos = ani.get();
#endif

    cout << "pos : " << pos << endl;

    this_thread::sleep_for(10ms);
  }
}
