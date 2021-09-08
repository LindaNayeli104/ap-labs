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

func DoIntersect(p1, q1, p2, q2 Point) bool {
	// Find the four orientations needed for general and
	// special cases
	var o1 int = Orientation(p1, q1, p2)
	var o2 int = Orientation(p1, q1, q2)
	var o3 int = Orientation(p2, q2, p1)
	var o4 int = Orientation(p2, q2, q1)

	// General case
	if o1 != o2 && o3 != o4 {
		return true
	}

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if o1 == 0 && OnSegment(p1, p2, q1) {
		return true
	}

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1
	if o2 == 0 && OnSegment(p1, q2, q1) {
		return true
	}

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if o3 == 0 && OnSegment(p2, p1, q2) {
		return true
	}

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if o4 == 0 && OnSegment(p2, q1, q2) {
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

	p1 := Point{-3, 1}
	q1 := Point{2, 3}
	p2 := Point{2, 3}
	q2 := Point{0, 0}

	if DoIntersect(p1, q1, p2, q2) {
		fmt.Printf("Yes\n")
	} else {
		fmt.Printf("No\n")
	}

} //acaba main

//!-path
