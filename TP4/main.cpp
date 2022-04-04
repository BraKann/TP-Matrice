/*
*ALGO. NUM. - TP 4 - MATRICES 
*ALISA HASANLI & CHIABERGE CHRISTOPHER - GR.485 - 2021/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <stdint.h>

#include "matrix.hpp"

using namespace std;

int main(int argc, char** argv)
{

  uint64_t n,m;

  n = 3;
  m = 3;

    /*** Allocations des matrices pour tester la triangularizations ***/
    double* A = allocateMatrix(n,m);
    double* B = allocateVector(n);
    A[0] = 1 ;  A[1] = -3 ; A[2] = 2 ;
    A[3] = 2 ;  A[4] =  1 ; A[5] = 1 ;
    A[6] = 3 ;  A[7] = -1 ; A[8] = 5 ;
    

    B[0] =  1;
    B[1] = -2;
    B[2] =  3;

    Triangularize(A,B,n);

    writeMatrix(stdout,A,n,m);

    freeMatrix(A);
    freeVector(B);   
    return 0;
}