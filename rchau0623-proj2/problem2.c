//Ryan Chau

//This function takes 2 long arguments, arithmetically left shifting the first one, 
//and applying a right shift to the second one. 
//The return value is the result of the boolean and operation between 
//the first and the second arguments.

long problem2(long x, long y) {
	x = (x * 3) << 4;
	y = y / 32; //Dividing rather than shifting to achieve the same assembly code.
	return x & y;
}

