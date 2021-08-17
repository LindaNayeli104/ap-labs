package main

import (
	"fmt"
	"os"
)

func main() {
	name := os.Args[1:]
	
	if(len(name) == 0){
		fmt.Printf("Please enter the required parameter \n")
	}else{
		fmt.Printf("Welcome ")
		for i := 0; i < len(name); i++{
			fmt.Printf(name[i] + " ")
		}	
		fmt.Printf("to the jungle \n")
	}
}


