package main

import (
	"fmt"

	"github.com/simnalamburt/snippets/go/enum/lib"
)

// iota 방식의 enum은 무효한 값을 만들 수 있어서 타입세이프하지 않다
func getInvalidOldEnum() lib.OldEnum {
	// 아래와 같이 무효한 값을 만들 수 있음
	var r lib.OldEnum = 123
	return r
}

func main() {
	// 아무것도 안쓰면 internal 이 0 일때의 값인 SortPropertyStarted 로 초기화됨
	// 좀 열받지만 go 언어 한계상 어쩔 수 없음
	var p lib.SortProperty
	fmt.Println(p)
	p = lib.SortPropertyStarted()
	fmt.Println(p)
	p = lib.SortPropertyUpdated()
	fmt.Println(p)
	p = lib.SortPropertyPaid()
	fmt.Println(p)
	// 기존에 const ~ iota 쓰던 enum과 달리, 유효하지 않은 값을 임의로 탄생시킬
	// 수 없음. 그래서 더 typesafe 함
	//p = lib.SortProperty{internal: 123}

	// 패턴매칭 잘 됨
	switch p {
	case lib.SortPropertyStarted():
		fmt.Println("Started")
	case lib.SortPropertyUpdated():
		fmt.Println("Updated")
	case lib.SortPropertyPaid():
		fmt.Println("Paid")
		// unsafe를 쓰지 않는이상 위의 세 값 이외에 다른 값을 탄생시킬 수
		// 없기때문에, default 블럭이 없어도 위의 세 케이스가 exhaustive
		// 하다는걸 확신할 수 있음

	default:
		// 그러나 불필요한 default 문이 있다고해서 컴파일러가 경고하지는 않는다
		panic("unreachable")
	}

	switch p {
	case lib.SortPropertyStarted():
		fmt.Println("Started")
		// golang 특성상 non-exhaustive switch 문은 컴파일러가 경고하지 않음
	}
}
