golang에서 enum 그나마 좀 타입세이프하게 쓰는법 예제
--------

[lib/lib.go]가 enum을 제공하는 쪽 코드이고, [main.go]가 enum을 사용하는 쪽
코드입니다. 요약하자면, enum을 정의하는 쪽에선 아래와 같은 식으로 정의하고:

```go
type SortProperty struct {
	internal uint8
}

func SortPropertyStarted() SortProperty { return SortProperty{internal: 0} }
func SortPropertyUpdated() SortProperty { return SortProperty{internal: 1} }
func SortPropertyPaid() SortProperty    { return SortProperty{internal: 2} }
```

사용하는 쪽에서는 아래와 같이 하면 됩니다:

```go
p := lib.SortPropertyStarted()

switch p {
case lib.SortPropertyStarted():
	fmt.Println("Started")
case lib.SortPropertyUpdated():
	fmt.Println("Updated")
case lib.SortPropertyPaid():
	fmt.Println("Paid")
}
```

자세한 rationale이 궁금하다면, [lib/lib.go]와 [main.go]를 참고하세요.

[lib/lib.go]: lib/lib.go
[main.go]: main.go
