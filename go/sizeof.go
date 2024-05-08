package main

import (
	"unsafe"
	"time"
)

func main() {
	var t time.Time

	println(unsafe.Sizeof(t))
}
