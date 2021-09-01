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
	var operacion string
	operacionNum := 0
	var nums []int
	//nums := make([]int,)

	if len(params) <= 2 {
		fmt.Printf("Ingresa add, sub o mult y los enteros necesarios para la operacon\n")
		return
	} else {
		operacion = params[0]
		//lenArr := len(params) - 1
		//var nums [lenArr]int
		//var nums [lenArr]int = [lenArr]int{0}

		for i := 1; i < len(params); i++ {
			//numInt := strconv.ParseInt(params[i], 0, 10)
			//strconv.Atoi(params[i])
			currentNum, err := strconv.Atoi(params[i])

			if err != nil {
				// Add code here to handle the error!
			} else {
				//fmt.Printf("Entra\n")
				nums = append(nums, currentNum)
			}
		}
	}

	if operacion == "add" {
		operacionNum = 1
	} else if operacion == "sub" {
		operacionNum = 2
	} else if operacion == "mult" {
		operacionNum = 3
	} else {
		fmt.Println("Operador no valido")
		return
	}

	res := calc(operacionNum, nums)
	fmt.Println(res)
	return

}
