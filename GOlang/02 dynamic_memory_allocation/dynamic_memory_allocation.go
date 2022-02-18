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

	// array itself return the first elements memory address
	var arr [3]int
	for i := 0; i < 3; i++ {
		var a int
		fmt.Scan(&a)
		arr[i] = a
	}

	for _, v := range arr {
		print(v, " ")
	}

}
