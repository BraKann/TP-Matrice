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

  n = 4;
  m = 4;

    /*** Allocations des matrices ***/
    double* A = allocateMatrix(n,m);
    double* B = allocateVector(n);
    double* S = allocateMatrix(n,m);
    double* x = allocateVector(n);
    A[0] = 10 ;  A[1]  = 7 ; A[2]  = 8  ; A[3]  = 7  ;
    A[4] = 7  ;  A[5]  = 5 ; A[6]  = 6  ; A[7]  = 5  ;
    A[8] = 8  ;  A[9]  = 6 ; A[10] = 10 ; A[11] = 9  ;
    A[12] = 7 ;  A[13] = 5 ; A[14] = 9  ; A[15] = 10 ;
    

    B[0] = 32;
    B[1] = 23;
    B[2] = 33;
    B[3] = 31;

    /*** Test des fonctions ***/

    matrixMultiplyNaive(S,A,B,n,m,n);

    SolveTriangularSystemUP(x,A,B,n);

    Triangularize(A,B,n);

    SolveSystemGauss(x,A,B,n);

    freeMatrix(A);
    freeMatrix(S);
    freeVector(B);
    freeVector(x);  
    return 0;
}