/*
 * author: Ryan Chau
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_3_opt. It should perform the same 
// task as the implemented level_3 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry. 

long level_3(long * B, long * A, int x)
{
	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 
	
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] = B[ r*N + c ] + A[ c*N + r ] ;
	
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}



long level_3_opt(long * B, long * A, int x)
{
	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 

    int r;
    	
    	// Due to the way the original code is written, C[r] is constantly being
    	// overwritten per each iteration of c, so the final iteration of c, when
    	// c = N - 1 defines C[r]. Therefore a substitution of c for N - 1 is made.
        for(r = 0; r < N; r++) 
            C[ r ] = B[ r*N + N - 1 ] + A[ (N - 1)*N + r ] ;
            
	//DO NOT modify the rest of this function 
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}


