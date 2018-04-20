//Ryan Chau

//This function takes 2 long arguments, checking if the second argument is 
//between 0 and 7. It then shifts the first argument by the second argument 
//multiplied by 8, returning the last byte of the result. 

char problem3(long x, int y) { //Returning char to get the last byte.
	if (y < 0) {
		return 0;
	}
	if (y > (unsigned) 7) {
		return 0;
	} 
	return x >> y * 8;
}