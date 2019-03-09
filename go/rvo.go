// Go 컴파일러가 RVO 어떻게 하는지 궁금해서 만들었음.
//
//   go build -gcflags '-m' rvo-1.go
//   go build -gcflags '-m -m' rvo-1.go
//
// 위 커맨드로 최적화랑 Escape Analysis 어떻게 이뤄지는지 보고, 그리고
// https://godbolt.org 에 소스코드 복붙해서 코드젠 어떻게 되는지 보면 됨.
//
// 직접 해본 결과, go1.11.5 darwin/amd64 기준으로는 작은 구조체에 대해선 매번
// 복사하는게 맞고, RVO 안한다. 근데 구조체 크기가 조금만 커지면 걍 자동으로
// 힙에 할당해버린다음 포인터 넘겨서 RVO가 필요없기 때문에 아예 구현 안한것같다.
//
// 여담으로 Go pseudo assembly 기괴하게 생겨서 읽기 힘들었음.

package main

import (
	"fmt"
	"time"
)

type BigType struct {
	// I am so big
	a0, a1, a2, a3 uint64
	b0, b1, b2, b3 float64

	// 아래 두 라인 모두 주석 처리 했을 때에는 그냥 movups를 여러번 호출한다

	// data [10]int
	// 위 라인만 주석해제해서 길이 10짜리 int 배열을 넣으면 duffcopy를
	// 호출한다. duffcopy는 AMD64에선 그냥 movups를 여러번 쓴거다
	// Reference: https://golang.org/src/runtime/mkduff.go#L79

	// data [1000]int
	// 위 라인을 주석해제해서 정말 크게 만들경우 이 객체는 무조건 힙에
	// 할당된다
}

func make() (result BigType) {
	x := uint64(time.Now().Second())

	// Preventing const eval
	result.a0 = x * 10000000
	result.a1 = x * 20000000
	result.a2 = x * 30000000
	result.a3 = x * 40000000
	result.b0 = float64(x) / 2.0
	result.b1 = float64(x) / 3.0
	result.b2 = float64(x) / 4.0
	result.b3 = float64(x) / 5.0
	return
}

func take(p BigType) {
	fmt.Printf("BigType { %d %d %d %d %f %f %f %f }\n",
		p.a0, p.a1, p.a2, p.a3, p.b0, p.b1, p.b2, p.b3)
}

func take_mutate(p BigType) {
	x := uint64(time.Now().Second())

	// Preventing const eval
	p.a0 += x
	p.a1 += x
	p.a2 += x
	p.a3 += x

	fmt.Printf("BigType { %d %d %d %d %f %f %f %f }\n",
		p.a0, p.a1, p.a2, p.a3, p.b0, p.b1, p.b2, p.b3)
}

func case1() {
	foo := make()

	// Do whatever
	fmt.Printf("%d\n", foo.a0)
}

func case2() {
	take(make())
}

func case3() {
	take_mutate(make())
}

func main() {
	case1()
	case2()
	case3()
}
