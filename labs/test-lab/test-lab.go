package main

import (
	"fmt"
	"os"
)

func main() {
	name := os.Args[1]
	fmt.Printf("Welcome %v to the jungle \n", name)
}
