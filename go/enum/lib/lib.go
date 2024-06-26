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
//const SortPropertyPaid = SortProperty{internal: 2}

// const 대신 var로 만드는것은 가능함
//var SortPropertyPaid = SortProperty{internal: 2}
//
// 그러나 이 경우 외부에서 전역변수의 값을 마구 바꿀 수 있음
//
//     var zero lib.SortProperty
//     lib.SortPropertyPaid = zero

// 그래서 아래와 같이 여러개의 전역함수를 선언할것임
func SortPropertyStarted() SortProperty { return SortProperty{internal: 0} }
// Go는 타입 만든 사람이 허락하지 않더라도 무조건 모든 타입에 대해 zero
// value를 만들 수 있음. 그래서 internal이 0일때의 값에 유효한 의미를
// 정의해두지 않으면, 아래와 같이 타입 사용자가 무효한 값을 만들 수 있다:
//
//     var zero lib.SortProperty
//
// 그래서 항상 zero value에 유효한 값을 할당해줘야함
func SortPropertyUpdated() SortProperty { return SortProperty{internal: 1} }
func SortPropertyPaid() SortProperty    { return SortProperty{internal: 2} }

// 다만 이렇게 해줘도 enum이 정의된것과 같은 패키지에선 여전히 무효한 값을
// 만들 수 있다. 따라서 이 방법은 enum을 여러 모듈이 공유할때에만 의미가 있고,
// 한 모듈 안에서 사용할떄엔 무의미하다.
func getInvalidSortProperty() SortProperty {
	return SortProperty{internal: 123}
}
