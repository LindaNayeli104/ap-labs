// Clock Server is a concurrent TCP server that periodically writes the time.
package main

import (
	"io"
	"flag"
	"log"
	"net"
	"time"
	"fmt"
	"os"
	"strconv"
)


func TimeIn(t time.Time, name string) (time.Time, error) {
    loc, err := time.LoadLocation(name)
    if err == nil {
        t = t.In(loc)
    }
    return t, err
}


func handleConn(c net.Conn, tzStr, timeZForm string) {
	defer c.Close()

	_, err := io.WriteString(c, tzStr + "          :  " +  timeZForm)

	if err != nil {
		return // e.g., client disconnected
	}
}


func server(portNum, tzStr, timeZForm string) {
	listener, err := net.Listen("tcp", "localhost:" + portNum)
	if err != nil {
		log.Fatal(err)
	}
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err) // e.g., connection aborted
			continue
		}
		go handleConn(conn, tzStr, timeZForm) // handle connections concurrently
	}
}


func main() {

	params := os.Args[1:]

	if len(params) < 2 {
		fmt.Println("Agrega la bandera '-port' y el número de puerto como se muestra en el ejemplo")
		fmt.Println("TZ=US/Eastern    go run clockServer.go -port 8010")
		return
	}

	portNum := flag.String("port", "-1", "Port number")
	flag.Parse()

	intVar, err := strconv.Atoi(*portNum)

	if intVar <= 999 || intVar >= 10000{
		fmt.Printf("Ingrese un número de puerto de 4 dígitos como se muestra en el ejemplo\n")
		fmt.Printf("TZ=US/Eastern    go run clockServer.go -port 80100\n")
		return
	} 
	
	fmt.Println("portNum: ", *portNum)

	os.Setenv("TZ", os.Getenv("TZ"))

	tzStr := os.Getenv("TZ")

	if( tzStr == ""){
		fmt.Printf("Ingrese TZ= y su Zona horaria como se muestra en el ejemplo\n")
		fmt.Printf("TZ=US/Eastern    go run clockServer.go -port 80100\n")
		return
	}

	fmt.Println("TZ:", tzStr)
	fmt.Println("")

	timeZ, err := TimeIn(time.Now(), tzStr)
	if err != nil {
		fmt.Println(err)
		return
	} else {
		timeZForm := timeZ.Format("15:04:05\n")
		server(*portNum, tzStr, timeZForm)
	}
}