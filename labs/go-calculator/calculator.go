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
	}

	return res
}

func main() {
	params := os.Args[1:]
	var operacion string
	operacionNum := 0
	var nums []int
	var cadena string

	if len(params) < 2 {
		fmt.Printf("Ingresa add, sub o mult y los enteros necesarios para la operacon\n")
		return
	} else {
		operacion = params[0]

		for i := 1; i < len(params); i++ {
			currentNum, err := strconv.Atoi(params[i])

			cadena = fmt.Sprintf("%d", currentNum)

			if params[i] == "0" && currentNum == 0 || params[i] != cadena || currentNum > 2147483647 || currentNum < -2147483648 {
				fmt.Printf("Por favor ingresa solo numeros enteros\n")
				return
			}

			if err != nil {
				fmt.Printf("No es un string valido\n")
			} else {
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

	for i := 1; i < len(params)-1; i++ {
		//Agregar validacion de numeros
		if operacionNum == 1 {
			fmt.Printf("%d + ", nums[i-1])
		} else if operacionNum == 2 {
			fmt.Printf("%d - ", nums[i-1])
		} else if operacionNum == 3 {
			fmt.Printf("%d * ", nums[i-1])
		}
	}
	fmt.Printf("%d = %d\n", nums[len(params)-2], res)
	return

}
