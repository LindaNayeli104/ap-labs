package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
)

type Point struct {
	x, y float64
}

func (p Point) GetX() float64 {
	return p.x
}

func (p Point) GetY() float64 {
	return p.y
}

func OnSegment(p, q, r Point) bool {
	if q.GetX() <= math.Max(p.GetX(), r.GetX()) && q.GetX() >= math.Min(p.GetX(), r.GetX()) && q.GetY() <= math.Max(p.GetY(), r.GetY()) && q.GetY() >= math.Min(p.GetY(), r.GetY()) {
		return true
	}
	return false
}

func Orientation(p, q, r Point) int {
	var val float64 = (q.GetY()-p.GetY())*(r.GetX()-q.GetX()) - (q.GetX()-p.GetX())*(r.GetY()-q.GetY()) //int

	if val == 0 {
		return 0 // colinear
	}

	if val > 0 { // clock or counterclock wise
		return 1
	}

	return 2
}

func DoIntersect(inicio1, fin1, inicio2, fin2 Point) bool {
	// Find the four orientations needed for general and
	// special cases
	var o1 int = Orientation(inicio1, fin1, inicio2)
	var o2 int = Orientation(inicio1, fin1, fin2)
	var o3 int = Orientation(inicio2, fin2, inicio1)
	var o4 int = Orientation(inicio2, fin2, fin1)

	// Special Cases
	// inicio1, fin1 and inicio2 are colinear and inicio2 lies on segment inicio1fin1
	if o1 == 0 && OnSegment(inicio1, inicio2, fin1) {
		return false
	}

	// inicio1, fin1 and fin2 are colinear and fin2 lies on segment inicio1fin1
	if o2 == 0 && OnSegment(inicio1, fin2, fin1) {
		return true
	}

	// inicio2, fin2 and inicio1 are colinear and inicio1 lies on segment inicio2fin2
	if o3 == 0 && OnSegment(inicio2, inicio1, fin2) {
		return true
	}

	// inicio2, fin2 and fin1 are colinear and fin1 lies on segment inicio2fin2
	if o4 == 0 && OnSegment(inicio2, fin1, fin2) {
		return false
	}

	// General case
	if o1 != o2 && o3 != o4 {
		return true
	}

	return false // Doesn't fall in any of the above cases
}

func main() {
	params := os.Args[1:]
	sides, err := strconv.Atoi(params[0])

	if err != nil {
		fmt.Printf("No es un string valido\n")
	}

	var points []Point

	//x := rand.Intn(200) - 100 //200 o 201
	var randNum1 float64 = 0.0
	var randNum2 float64 = 0.0
	var min float64 = -100.0
	var max float64 = 101.0

	for i := 0; i < sides; i++ {
		//new(Point)
		randNum1 = min + rand.Float64()*(max-min)
		randNum2 = min + rand.Float64()*(max-min)
		//fmt.Printf("%.2f\n", randNum1)

		point := Point{randNum1, randNum2}
		points = append(points, point)

	}

	fmt.Println(points[0])
	fmt.Println(points[1])
	fmt.Println(points[2])
	fmt.Println(points[3])

	//-------------------------------------------------------Pruebas

	inicio1 := Point{-3.00, 58.79}
	fin1 := Point{-13.68, 25.08}
	inicio2 := Point{-88.68, 16.16}
	fin2 := Point{-90.06, -83.95}

	if DoIntersect(inicio1, fin1, inicio2, fin2) {
		fmt.Printf("Yes\n")
	} else {
		fmt.Printf("No\n")
	}

} //acaba main

//!-path
