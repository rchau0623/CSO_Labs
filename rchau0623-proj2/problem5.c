//Ryan Chau

//This function generates an array with 10 indexes, 
//filling it with random numbers. Using a helper function, 
//the sum and the product of the array values are calculated,
//and the product divided by the sum is returned.
  
#include <stdlib.h> 

long comp5(long* x, int y) {
	long a = 0;
	long b = 1;
	int i;
	for (i = 0; y - 1 > i; i++) {
		a = a + x[i];
		b = b * x[i];
	}
	return b / a;
}

long problem5() {
	long x[10];
	int i;
	for (i = 0; i < 10; i++) {
		long y = rand() % 201;
		x[i] = y; //Using this extra step to match the assembly.
	}
	return comp5(x, 10);
}