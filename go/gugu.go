package main

import "fmt"

func main() {
	for a := 2; a <= 9; a++ {
		for b := 1; b <= 9; b++ {
			fmt.Printf("%d * %d = %2d\n", a, b, a*b)
		}
		fmt.Println()
	}
}
