//Ryan Chau

#ifndef _PROJECT2_H_
#define _PROJECT2_H_

// provide the listing of all the methods implemented in the 
// problems1-5 in this header file

//This function takes 2 long arguments, returning the larger of the two.

long problem1(long x, long y); 

//This function takes 2 long arguments, arithmetically left shifting the first one, 
//and applying a right shift to the second one. 
//The return value is the result of the boolean and operation between 
//the first and the second arguments.

long problem2(long x, long y); 

//This function takes 2 long arguments, checking if the second argument is 
//between 0 and 7. It then shifts the first argument by the second argument 
//multiplied by 8, returning the last byte of the result. 

char problem3(long x, int y); 

//This function takes a long array and its length, computing and 
//returning the sum of the values from each index of the array.

long problem4(long* x, int y); 

//This function generates an array with 10 indexes, 
//filling it with random numbers. Using a helper function, 
//the sum and the product of the array values are calculated,
//and the product divided by the sum is returned.
  
long problem5();

#endif



