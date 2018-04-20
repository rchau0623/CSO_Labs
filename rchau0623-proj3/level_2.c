/*
 * author: Ryan Chau
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_2_opt. It should perform the same 
// task as the implemented level_2 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 

// Note: you may observe that this function performs "useless" looping
// over an array of structures that are all filled with zero bits. 
// Your task is not to remove that "useless" code, but modify it 
// so that it is more cache friendly. 
// You also should not be removing any parts of the structures.
//
// (In an actual application, the structures would be populated with
// real data and the loop would be computing some real results.) 


char * level_2()
{
    data_2 * B = (data_2 * ) calloc( LARGER, sizeof(data_2) ) ;
	if (!B) return 0; 
	double sum_f = 0.0;
	double sum_n = 0; 
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );	
	sum_c[2*LARGER] = '\0'; 
	
    int i; 

	for(i = 0; i < LARGER; i++){
		sum_f += B[i].f1 + B[i].f2; 
		sum_n += B[i].n1 + B[i].n2; 
		sum_c[2*i] = B[i].c1;
		sum_c[2*i+1] = B[i].c2;
	}
	
	
    free(B); 
    return sum_c;
}

char * level_2_opt()
{	
	// create the array of structures (same or equivalent to the one
	// in the function above: 
	
	// Using an optimized variation of the data_2 struct in order 
	// to minimize padding and size. 
    data_2_opt * B = (data_2_opt * ) calloc( LARGER, sizeof(data_2_opt) ) ;
	if (!B) return 0; 
	
	// DO NOT modify the following declarations 
	double sum_f = 0.0;
	double sum_n = 0; 
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );	
	sum_c[2*LARGER] = '\0'; 	
	
	// enter your code here (make sure to free the array B once 
	// before returning) 
  	
    int i; 

	for(i = 0; i < LARGER; i++){
		sum_f += B[i].f1 + B[i].f2; 
		sum_n += B[i].n1 + B[i].n2; 
		sum_c[2*i] = B[i].c1;
		sum_c[2*i+1] = B[i].c2;
	}
	
	
    free(B); 
	//DO NOT modify the rest of this function 
    return sum_c;
}

