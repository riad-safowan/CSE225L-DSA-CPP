package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

func main() {
	// allocating memory address for a int variable with new(T) function
	var a = new(int)
	*a = 10
	println(*a)

	// array
	var arr [3]int
	for i := 0; i < 3; i++ {
		var a int
		fmt.Scan(&a)
		arr[i] = a
	}

	updateslice(arr[:]) 
	updateArray(arr) // will not change the value
	updateArray2(&arr) // will change the value
	for _, v := range arr {
		print(v, " ")
	}
}

func updateslice(funarr []int) {

	// updating the value
	// at specified index
	funarr[2] = 750
}

func updateArray(a [3]int) {
	a[2] = 1000
}

func updateArray2(a *[3]int) {
	(*a)[2] = 2000
}