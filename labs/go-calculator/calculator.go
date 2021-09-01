package main

// adds/subtracts/multiplies all values that are in the *values array.
// nValues is the number of values you're reading from the array
// operator will indicate if it's an addition (1), subtraction (2) or
// multiplication (3)

import (
	"fmt"
	"os"
	"strconv"
)

func calc(operator int, values []int) int {
	res := values[0]

	for i := 1; i < len(values); i++ {
		if operator == 1 {
			res += values[i]
		} else if operator == 2 {
			res -= values[i]
		} else if operator == 3 {
			res *= values[i]
		}
		//fmt.Println(i)
	}

	return res
}

func main() {
	params := os.Args[1:]
	operacion := "empty"
	operacionNum := 0

	if len(params) == 0 {
		fmt.Printf("Please enter the required parameter \n")
		return
	} else {
		operacion := params[0]
		lenArr := len(params) - 1
		//var nums [lenArr]int
		var nums [lenArr]int = [lenArr]int{0}
		for i := 1; i < len(params); i++ {
			//numInt := strconv.ParseInt(params[i], 0, 10)
			//strconv.Atoi(params[i])
			nums[i] = strconv.Atoi(params[i])
		}
	}

	if operacion == "add" {
		operacionNum = 1
	} else if operacion == "sub" {
		operacionNum = 2
	} else if operacion == "mult" {
		operacionNum = 3
	} else {
		fmt.Println("Operador no valido\n")
		return
	}
}
