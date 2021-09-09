// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 156.

// Package geometry defines simple types for plane geometry.
//!+point
package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
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

func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.GetX()-p.GetX(), q.GetY()-p.GetY())
}

func generatePoints(sides int) []Point {
	var points []Point
	var randNum1 float64 = 0.0
	var randNum2 float64 = 0.0
	var min float64 = -100.0
	var max float64 = 101.0

	for i := 0; i < sides; i++ {
		rand.Seed(time.Now().UnixNano())
		randNum1 = min + rand.Float64()*(max-min)
		randNum2 = min + rand.Float64()*(max-min)

		point := Point{randNum1, randNum2}
		points = append(points, point)

	}

	return points
}

func checkIfIntersect(sides int, points []Point) bool {
	intersection := false
	for i := 0; i < sides-1; i++ { // 0 -> 1,2,3   1-> 2, 3  2 -> 3
		for j := i; j < sides-1; j++ {
			if j == sides-2 {
				intersection = DoIntersect(points[i], points[i+1], points[j], points[0])
			} else {
				intersection = DoIntersect(points[i], points[i+1], points[j+1], points[j+2])
			}

			if intersection == true {
				return true
			}

		}
	}
	return false
}

func printPoints(sides int, points []Point) {
	for i := 0; i < sides; i++ {
		fmt.Printf("  - ( %.2f, %.2f)\n", points[i].GetX(), points[i].GetY())
	}
}

//--------------
func OnSegment(p, q, r Point) bool {
	if q.GetX() <= math.Max(p.GetX(), r.GetX()) && q.GetX() >= math.Min(p.GetX(), r.GetX()) && q.GetY() <= math.Max(p.GetY(), r.GetY()) && q.GetY() >= math.Min(p.GetY(), r.GetY()) {
		return true
	}
	return false
}

func Orientation(p, q, r Point) int {
	var val float64 = (q.GetY()-p.GetY())*(r.GetX()-q.GetX()) - (q.GetX()-p.GetX())*(r.GetY()-q.GetY())

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

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if o1 == 0 && OnSegment(p1, p2, q1) {
		return false
	}

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1
	if o2 == 0 && OnSegment(p1, q2, q1) {
		return false
	}

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if o3 == 0 && OnSegment(p2, p1, q2) {
		return false
	}

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if o4 == 0 && OnSegment(p2, q1, q2) {
		return false
	}

	// General case
	if o1 != o2 && o3 != o4 {
		return true
	}

	return false // Doesn't fall in any of the above cases
}

//---------- Main

func main() {
	params := os.Args[1:]

	if len(params) <= 0 {
		fmt.Printf("Por favor ingrese un numero de puntos\n")
		return
	}

	sides, err := strconv.Atoi(params[0])

	if err != nil {
		fmt.Printf("No es un numero entero valido\n")
		return
	}

	if sides < 3 {
		fmt.Printf("Por favor ingrese un numero de puntos mayor a 2\n")
		return
	}

	var distances []float64

	fmt.Printf("- Generating a [%d] sides figure\n", sides)
	fmt.Printf("- Figure's vertices\n")

	//Generate points
	var points []Point = generatePoints(sides)

	//---------------------- Check if lines intersect

	intersection := checkIfIntersect(sides, points)

	for intersection != false {
		rand.Shuffle(len(points), func(i, j int) { points[i], points[j] = points[j], points[i] })
		intersection = checkIfIntersect(sides, points)
	}
	printPoints(sides, points)

	//---------------------- Calculate distances and perimeter
	perimeter := 0.0
	for i := 0; i < sides-1; i++ {
		perimeter += points[i].Distance(points[i+1])
		distances = append(distances, points[i].Distance(points[i+1]))
	}

	perimeter += points[sides-1].Distance(points[0])
	distances = append(distances, points[sides-1].Distance(points[0]))

	//----------------------------------------------------------

	fmt.Printf("- Figure's Perimeter\n")
	fmt.Printf("  - ")
	for i := 0; i < sides-1; i++ {
		fmt.Printf("%.2f + ", distances[i])
	}

	fmt.Printf("%.2f = %.2f\n", distances[sides-1], perimeter)

}
