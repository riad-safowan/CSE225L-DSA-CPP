package main

func main() {
	x := new(int) //returns a pointer
	*x = 10
	double(x)
	println(*x)

	y := newInt(12)
	println(*y)

	a := int64(5)
	p := &a
	*p++
	println(*p, a)

	*&a++   //not like cpp
	*&*&a++ //the precedence of the pointer dereference operator * is higher than the increment operator ++ and decrement operator --
	**&p++
	*&*p++
	println(*p, a)

	//make a custom type
	type MyInt int64
	type Ta *int64
	type Tb *MyInt

	//declere variable
	var pa0 Ta
	var pa1 *int64
	var pb0 Tb
	var pb1 *MyInt

	println(pa0, pa1, pa0 == pa1)
	println(pb0, pb1, pb0 == pb1)
	/*println(pa0, pb0, pa0 == pb0)
	println(pa1, pb1, pa1 == pb1)*/

}

//returns a pointer
func double(x *int) {
	*x += *x
}

func newInt(x int) *int {
	return &x
}
