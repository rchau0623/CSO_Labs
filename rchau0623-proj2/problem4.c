//Ryan Chau

//This function takes a long array and its length, computing and 
//returning the sum of the values from each index of the array. 

long comp4(long* x, long y) {
	long z = *x;
	*x = y + z;
	return z;
}

long problem4(long* x, int y) {
	long a = 0;
	int i;
	for (i = 0; i < y; i++) {
		a = a + comp4(x + i, 2);
	}
	return a;
}