package main

import (
	"net"
	"fmt"
	"os"
	"log"
	"io"
)

func mustCopy(dst io.Writer, src io.Reader) {
	if _, err := io.Copy(dst, src); err != nil {
		log.Fatal(err)
	}
}


func client(portNum string) {
	//var tzTimeRes string
	conn, err := net.Dial("tcp", "localhost:" + portNum)
	if err != nil {
		log.Fatal(err)  
	}
	defer conn.Close()
	mustCopy(os.Stdout, conn)
}


func main() {

	params := os.Args[1:]
	if len(params) < 1 {
		fmt.Printf("Ingrese el nombre de la ciudad y el numero de localhost como se muestra en el ejemplo\n")
		fmt.Printf("go run clockWall.go NewYork=localhost:8010 Tokyo=localhost:8020 London=localhost:8030\n")
		return
	}else {

		for i := 0; i < len(params); i++ {
			cityPort := params[i]
			portNum := cityPort[len(cityPort)-4:]
			client(portNum)
		}
	}
}