package main

import (
	"fmt"
	"time"
)

func main() {
	ticker := time.NewTicker(time.Second * 2)
	quit := make(chan struct{})
	go func() {
		for {
			select {
			case <-ticker.C:
				fmt.Println("ㅇㅅㅇ")
			case <-quit:
				ticker.Stop()
				return
			}
		}
	}()

	<-quit
}
