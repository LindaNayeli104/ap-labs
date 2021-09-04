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
)

type Point struct {
	X, Y float64
}

/* type Point struct { //mio
	x, y float64
}

func (p Point) X    //p.X( )      x := p.X()
func (p Point) Y
*/
// traditional function
func Distance(p, q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// same thing, but as a method of the Point type
func (p Point) Distance(q Point) float64 { //no entiendo
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

//!-point

//!+path
// A Path is a journey connecting the points with straight lines.
type Path []Point

// Distance returns the distance traveled along the path.
func (path Path) Distance() float64 {
	sum := 0.0
	for i := range path {
		if i > 0 {
			sum += path[i-1].Distance(path[i])
		}
	}
	return sum
}

func main() {
	params := os.Args[1:]
	sides, err := strconv.Atoi(params[0])

	if err != nil {
		fmt.Printf("No es un string valido\n")
	}

	//var points []Point
	var points Path

	fmt.Printf("- Generating a [%d] sides figure\n", sides)
	fmt.Printf("- Figure's vertices\n")
	// - (  -3,   1)
	fmt.Printf("- Figure's Perimeter\n")
	//- 5.38 + 3.60 + 3.92 + 3.80 = 16.70

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

	//------------------------------------------------------
	perimeter := points.Distance()

	fmt.Println(points[0])
	fmt.Println(points[1])
	fmt.Println(points[2])
	fmt.Println(points[3])
	fmt.Printf("%.2f\n", perimeter)

} //acaba main

//!-path

// -100 y 100 inclusivo??
//go tiene operador ternario??
//Tengo que usar a fuerza las funciones que van func (p Point) Distance(q Point) float64 { ?? //no entiendo
// Como se hacde un if en una linea??
