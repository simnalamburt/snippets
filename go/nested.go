package main

type Nesting struct {
	a    int
	b    int
	nest []Inner
	e    int
}
type Inner struct {
	c int
	d int
}

func (i Inner) foo() int {
	return i.c + i.d
}

type NoNesting struct {
	a    int
	b    int
	nest []struct {
		c int
		d int
	}
	e int
}

func (n NoNesting) foo(i uint) int {
	return n.nest[i].c + n.nest[i].d
}

func foo(i struct {
	c int
	d int
}) int {
	return i.c + i.d
}

func main() {
	x := Nesting{
		a: 1,
		b: 2,
		nest: []Inner{
			{c: 3, d: 4},
			{c: 30, d: 40},
		},
		e: 5,
	}
	println(x.nest[0].foo())
	println(x.nest[1].foo())

	y := NoNesting{
		a: 1,
		b: 2,
		nest: []struct {
			c int
			d int
		}{
			{c: 3, d: 4},
			{c: 30, d: 40},
		},
		e: 5,
	}
	println(y.foo(0))
	println(y.foo(1))
	println(foo(y.nest[0]))
	println(foo(y.nest[1]))
}
