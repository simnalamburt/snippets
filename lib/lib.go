package lib

// 보통 Go에서 enum을 만들때는 아래와 같이 iota를 쓴다
type OldEnum uint8
const (
	OldEnumStarted OldEnum = iota
	OldEnumUpdated
	OldEnumPaid
)
// 그러나 이 경우 사용자가 제작자가 허락하지 않은 무효한 값을 마구 만들 수
// 있어서 타입세이프하지 않다. main.go 의 `getInvalidOldEnum` 함수 참조

// 그래서 아래와 같이 하는게 더 나음
type SortProperty struct {
	// internal은 외부에서 접근할 수 없는 private 필드로, 이 필드를 통해
	// SortProperty의 값이 결정되고, 이 필드가 private 필드이기 때문에
	// 사용자가 무효한 값을 만들 수 없다
	internal uint8
}

// struct는 const를 선언할 수 없음
//const NewTypeConst = NewType { value: "NewConst" }

// 그래서 아래와 같이 전역변수르 선언할것임
var (
	// Go는 타입 만든 사람이 허락하지 않더라도 무조건 모든 타입에 대해 zero
	// value를 만들 수 있음. 그래서 internal이 0일때의 값에 유효한 의미를
	// 정의해두지 않으면, 아래와 같이 타입 사용자가 무효한 값을 만들 수 있다:
	//
	//     var zero lib.SortProperty
	//
	// 그래서 항상 zero value에 유효한 값을 할당해줘야함
	SortPropertyStarted = SortProperty{internal: 0}
	SortPropertyUpdated = SortProperty{internal: 1}
	SortPropertyPaid = SortProperty{internal: 2}
)
