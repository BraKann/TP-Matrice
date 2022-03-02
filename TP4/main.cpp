#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <stdint.h>

#include "matrix.hpp"

using namespace std;

int main(int argc, char** argv){

    /***Allocation des matrices***/
    double* A = allocateMatrix(2,3);
    double* B = allocateMatrix(3,2);
    double* C = allocateMatrix(4,2);
    double* D = allocateMatrix(2,2);
    double* E = allocateMatrix(3,3);
    double* F = allocateMatrix(4,4);
    double* G = allocateMatrix(5,5);

    /***Allocation des vecteurs***/
    double* V1 = allocateVector(4);
    
    /***Construction de la matrice A***/
    A[0] = 1 ; A[1] = 2 ; A[2] = 3 ;
    A[3] = 4 ; A[4] = 5 ; A[5] = 6 ;
    /***Construction de la matrice B***/
    B[0] = 1 ; B[1] = 2 ; 
    B[2] = 3 ; B[3] = 4 ; 
    B[4] = 5 ; B[5] = 6 ;

    /***Multiplication naive entre les matrices A et B***/
    matrixMultiplyNaive(D,A,B,2,3,2);
    /***Ecriture de la matrice D***/
    writeMatrix(stdout, D, 2, 2);

    /***Addition entre les matrices A et B***/
    matrixAdd(C, A, B, 2, 3);
    writeMatrix(stdout, C, 2, 3);
    

    cout << "Do or do not. There is no try." << endl;
    
    
    /***Desallocation des matrices***/
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(D);
    freeMatrix(E);
    freeMatrix(F);
    freeMatrix(G);
    
    /***Desallocation des vecteurs***/
    freeVector(V1);
    
    return 0;
}