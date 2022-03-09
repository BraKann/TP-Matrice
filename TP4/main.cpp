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

int main(int argc, char** argv){

/*
int isUpperMatrix() 
{
    for (i = 1; i < n; i++)
    {
      for (j = 0; j < i; j++)
      {
        if (mat[i][j] != 0)
        {
          flag = 0;
        }else{
          flag = 1;
        }
      }
    }
    if (flag == 1)
    {
      cout << "Upper Triangular Matrix"<<endl;
    }else{
      cout << "Not an Upper Triangular Matrix"<<endl;
    }
    return 0;
}
*/



    /***Allocation des matrices***/
    double* A = allocateMatrix(2,3);
    double* B = allocateMatrix(3,2);
    double* C = allocateMatrix(4,2);
    double* D = allocateMatrix(2,2);

     /*** Allocations des matrices pour tester la triangularizations ***/
     double* Aa = allocateMatrix(3,3);
     double* Bb = allocateVector(3);
    Aa[0] = 1; Aa[1] = -3; Aa[2] = 2;
    Aa[3] = 2; Aa[4] = 1; Aa[5] = 1;
    Aa[6] = 3; Aa[7] = -1; Aa[8] = 5;

    Bb[0] = 1;
    Bb[1] = -2;
    Bb[2] = 3;

    Triangularize(Aa,Bb,3);

    writeMatrix(stdout,Aa,3,3);
    writeMatrix(stdout,Bb,3,1);

    freeMatrix(Aa);
    freeVector(Bb);

    /*** Allocation des matrices et des vecteur pour Ax=b ***/
    double* a = allocateMatrix(3,3);
    double* b = allocateVector(3);
    double* x = allocateVector(3);

    a[0] = 3; a[1] = 1; a[2] = -5;
    a[3] = 0; a[4] = -2; a[5] = 4;
    a[6] = 0; a[7] = 0; a[8] = 2;

    b[0] = 1;
    b[1] = 10;
    b[2] = 6;

    //SolveTriangularSystemUP(x,a,b,3);
    //writeMatrix(stdout,x,3,1);

    /*** Desallocation des matrices et des vecteurs pour Ax=b ***/
    freeMatrix(a);
    freeVector(b);
    freeVector(x);

    

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
    //matrixMultiplyNaive(D,A,B,2,3,2);

    /***Ecriture de la matrice D***/
    //writeMatrix(stdout, D, 2, 2);

    /***Addition entre les matrices A et B***/
    //matrixAdd(C, A, B, 2, 3);
    //writeMatrix(stdout, C, 2, 3);
    

    cout << "Do or do not. There is no try." << endl;

    double *b = allocateVector(4);
    double *x = allocateVector(4);
    b[0] = 3;
    b[1] = 2;
    b[2] = 3;
    b[3] = 3;

    double *TS = allocateMatrix(4, 4);
    TS[0] = 10;
    TS[1] = 7;
    TS[2] = 8;
    TS[3] = 7;
    TS[4] = 0;
    TS[5] = 5;
    TS[6] = 13;
    TS[7] = 5;
    TS[8] = 0;
    TS[9] = 0;
    TS[10] = 20;
    TS[11] = 13;
    TS[12] = 0;
    TS[13] = 0;
    TS[14] = 0;
    TS[15] = 6;

    //SolveTriangularSystemUP(x, TS, b, 4);

    //cout << "TS =" << endl;
    //writeMatrix(stdout, TS, 4, 4);

    //cout << "b = " << b[0] << endl
     //    << "    " << b[1] << endl
     //    << "    " << b[2] << endl
     //    << "    " << b[3] << endl;

    //cout << "x.B = b" << endl;
    
    //cout << "x = " << x[0] << endl
      //   << "    " << x[1] << endl
      //   << "    " << x[2] << endl
      //   << "    " << x[3] << endl;
            /***Desallocation des matrices***/
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(D);
    
    /***Desallocation des vecteurs***/
    freeVector(V1);

    
    
    return 0;
}