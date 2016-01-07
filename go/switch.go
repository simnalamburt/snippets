package main

import "fmt"

func check(input string) bool {
	switch input {
	case "m", "km", "mi", "ft":
		return true
	}

	return false
}

func main() {
}
