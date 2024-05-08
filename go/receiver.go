package main

type MyType struct {
	internal int
}

func (m MyType) GetInternal() int {
	return m.internal
}

func (m *MyType) SetInternal(i int) {
	m.internal = i
}

func main() {
	var m MyType = MyType{internal: 5}
	println(m.GetInternal())
	m.SetInternal(10)
	println(m.GetInternal())
}
