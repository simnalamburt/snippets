package main

func main() {
	var foo interface{}

	foo = 1

	switch foo {
	case "hello":
		println("hello")
	case 1:
		println("one")
	}
}
