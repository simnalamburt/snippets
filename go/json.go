package main

import (
	"encoding/json"
	"fmt"
	"math/big"
)

type SampleJson[T any] struct {
	X T `json:"x"`
}

func parse[T any](input string) SampleJson[T] {
	var a SampleJson[T]
	err := json.Unmarshal([]byte(input), &a)
	if err != nil {
		panic(err)
	}
	fmt.Println(a)
	return a
}

type BigDecimal big.Rat

func (b *BigDecimal) UnmarshalJSON(data []byte) error {
	var s json.Number
	if err := json.Unmarshal(data, &s); err != nil {
		return err
	}
	i, ok := new(big.Rat).SetString(s.String())
	if !ok {
		return fmt.Errorf("invalid big.Int value %q", s)
	}
	*b = BigDecimal(*i)
	return nil
}

func (b BigDecimal) MarshalJSON() ([]byte, error) {
	r := big.Rat(b)
	return json.Marshal(r.String())
}

func (b BigDecimal) String() string {
	r := big.Rat(b)
	// r.Denom() 를 소인수분해 하여 2와 5 이외의 인수없다는 사실을 체크
	return r.RatString()
}

func main() {
	parse[uint32](`{"x":4294967295}`)
	parse[int64](`{"x":9223372036854775807}`)
	parse[int64](`{"x":-9223372036854775808}`)
	parse[big.Int](`{"x":9223372036854775807999999999999999999999999999999999999999}`)
	parse[json.Number](`{"x":9223372036854775807999999999999999999999999999999999999999}`)
	x := parse[json.Number](`{"x":9223372036854775807999999999999999999999999999999999999999.99999999999999999999999999999999999999999999999999999999999999999999999999}`)
	fmt.Println(x.X.Float64()) // 부정확한 결과 반환
	fmt.Println(x.X.Int64()) // i64로 표현 가능한 Most significant digits 일부와 함꼐 에러를 반환

	parse[BigDecimal](`{"x":9223372036854775807999999999999999999999999999999999999999.99999999999999999999999999999999999999999999999999999999999999999999999999}`)
	parse[BigDecimal](`{"x":0.5}`)

	// errors
	//parse[int32](`{"x":9223372036854775807}`)
	//parse[int](`{"x":9223372036854775807999999999999999999999999999999999999999}`)
	//parse[big.Int](`{"x":9223372036854775807999999999999999999999999999999999999999.5}`)
	//parse[big.Rat](`{"x":9223372036854775807999999999999999999999999999999999999999.99999999999999999999999999999999999999999999999999999999999999999999999999}`)
}
