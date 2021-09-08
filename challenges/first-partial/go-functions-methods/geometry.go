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

func main() {
	params := os.Args[1:]
	sides, err := strconv.Atoi(params[0])

	if err != nil {
		fmt.Printf("No es un string valido\n")
	}

	var points []Point
	var distances []float64

	fmt.Printf("- Generating a [%d] sides figure\n", sides)
	fmt.Printf("- Figure's vertices\n")

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

	//------------------------------------------------------
	perimeter := 0.0
	for i := 0; i < sides-1; i++ {
		perimeter += points[i].Distance(points[i+1])
		distances = append(distances, points[i].Distance(points[i+1]))
	}

	perimeter += points[sides-1].Distance(points[0])
	distances = append(distances, points[sides-1].Distance(points[0]))

	//----------------------------------------------------------

	for i := 0; i < sides; i++ {
		fmt.Printf("  - ( %.2f, %.2f)\n", points[i].GetX(), points[i].GetY())
	}

	fmt.Printf("- Figure's Perimeter\n")
	fmt.Printf("  - ")
	for i := 0; i < sides-1; i++ {
		fmt.Printf("%.2f + ", distances[i])
	}

	fmt.Printf("%.2f = %.2f\n", distances[sides-1], perimeter)

} //acaba main

//No mando puntos
//Mando mas de 3 puntos
