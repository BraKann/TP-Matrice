#include "matrix.hpp"

/*
  Supposons, nous avons une matrice de taille n x m. 
  Dans pluesieures langage de programmation, les indices dans les tableaux/listes commencent par 0.
  Alors, les éléments de la matrice A sont A_i,j pour 0<=i<=n-1 et 0<=j<=m-1.

  Nous allons stocker des matrices dans des tablaux à 1 dimension:
  Par exemple, notre matrixe A de taille n x m est stockée comme:
        tabA = [A_0,0   A_0,1  ...  A_0,m-1   A_10, ... A_1,m-1,  ... ,  A_0,n-1  ..., A_n-1,m-1]

    Par conséquant, un élement A_ij aurait quelle indice dans le tableau tabA ? 

 */

/* Memory allocation for a matrix of size n x m and initilization to 0  */
double *allocateMatrix(uint64_t n,uint64_t m) {
  double *A;
  A = (double *) calloc (n * m, sizeof(double));
  return A;
}


/* Frees the memory allocated to matrix A
*/
void freeMatrix(double *A) {
    free(A);
}

/* Allocates a n sized vector and initializes all entries to 0 
*/
double *allocateVector(uint64_t n) {
  double *v; 
  v = (double *) calloc(n, sizeof(double));
  return v;
}

/* Frees the memory allocated to a vector
*/
void freeVector(double *v) {
  free(v);
}


/* Sets a n x m matrix A to all zeros */
void setMatrixZero(double *A, uint64_t n, uint64_t m) {
  uint64_t i, j;

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
        /* Note that for a n x m matrix flattened to a 1D array, 
        element A_ij has index i * m + j
        */
      A[i * m + j] = 0.0; 
    }
  }
}

/* Sets a n x n matrix A to identity */
void setMatrixIdentity(double *A, uint64_t n) {
  uint64_t i, j;

  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
     A[i * n + j] = 0.0;
    }
    A[i * n + i] = 1.0;
  }
}



/* Copies a matrix  */
void copyMatrix(double *B, double *A, uint64_t n, uint64_t m) {
  uint64_t i,j;

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
      B[i * m + j] = A[i * m + j]; 
    }
  }
}

/*
Writes a matrix to a stream. For example, writing a matrix to standard output is
writeMatrix(stdout, A, n, m);
A sream can also be a file. 
*/
void writeMatrix(FILE *stream, double *A, uint64_t n, uint64_t m)
{
	fprintf(stream, "%d %d \n", (uint64_t)n, (uint64_t)m);
	uint64_t i, j;
	for(i = 0; i < n; ++i)
	{
	      for(j = 0; j < m; ++j)
	      {
		      fprintf(stream, "%f \t", A[i * m + j]);
	      }
	      fprintf(stream, "\n");
	}
}



//The function computes the element-by-element abs of matrix A
void absMatrix(double *Aabs,double *A, uint64_t n, uint64_t m)
{
	uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            Aabs[i*m + j] = fabs(A[i*m + j]);
		}
	}

}


/*
Performs addition of two matrix A (size n x m) and B (size n x m).
The result S = A + B is a n x m matrix.
We consider that S is allocated outside the function.
*/
void matrixAdd(double *S, double *A, double *B, uint64_t n, uint64_t m){
    uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            S[i*m + j] = A[i*m + j] + B[i*m + j];
		}
	}
}

/*
Performs subtraction of two matrix A (size n x m) and B (size n x m).
The result S = A - B is a n x m matrix.
We consider that S is allocated outside the function.
*/
void matrixSub(double *S, double *A, double *B, uint64_t n, uint64_t m){
    uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            S[i*m + j] = A[i*m + j] - B[i*m + j];
		}
	}
}



/* For a double m x n matrix A the function returns its maximum in absolute value
element. */
double getMaxInMatrix(double max, double *A, uint64_t n, uint64_t m)
{
	double maxA = fabs(A[0]);
	double current = fabs(A[0]);
	uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
			current = fabs(A[i * m + j]);
			if(current > maxA)
				maxA = current;
		}
	}
    return maxA;

}


/* Rajouter les prototypes de vos méthodes ici. Par exemple */

/* Performs naive multiplication of matrix A (size p x k) by a matrix B (size k x r).
The result matrix S = A*B  is of size (p x r).
We assume that S has already been allocated outside the function.
*/
void matrixMultiplyNaive(double *S, double *A, double *B, uint64_t l_A, uint64_t lc_AB, uint64_t c_B)
{
  //float sum = 0.0;
  for (uint64_t i = 0; i < l_A ; i++)
  {
    for (uint64_t j = 0; j < c_B ; j++)
    {
      float sum = 0.0;
      for (uint64_t k = 0; k < lc_AB ; k++)
      {
        sum = sum + ((A[i*lc_AB+k]) * (B[k*c_B+j]));
        S[i*c_B + j] = sum;
      }
    }
  }
}

/* (Bonus question) Performs a multiplication of two square matrices A and B (size n x n) by Strassen algorithm.
    We assume that S has already been allocated outside the function.
*/
void matrixMultiplyStrassen(double *S, double *A, double *B, uint64_t n){

    /* Votre code ici */
}

/* 
    Solves a system of linear equations Ax=b for a double-precision matrix A (size n x n).
    Uses iterative ascension algorithm. 
    After the procedure, x contains the solution of Ax=b.
    We assume that x has been allocated outside the function.
*/
void SolveTriangularSystemUP(double *x, double *A, double *b, uint64_t n)
{
  for (int i = n; i > 0; i--)
  {
    x[i-1] = b[i-1];
    for (int j = i; j <= n; j++)

    {
      x[i-1] = x[i-1] - A[(i-1)*n+j] * x[j];
    }

    x[i-1] = (1/A[(i-1)*n+i-1]) * x[i-1];
  }
}


/* 
double* redMat(double* A, uint64_t n)
{
  double *B = allocateMatrix(n,n);
  for(uint16_t i = 0; i < n; i++){
    for (uint64_t j = 0; j < n; j++)
    {
      B[i*n+j] = A[i*n+j];
    }
    
  }

  return B;
}
*/

/* 
    Performs Gauss elimination for given a matrix A (size n x n) and a vector b (size n).
    Modifies directly matrix A and vector b.
    In the end of the procedure, A is upper truangular and b is modified accordingly.
    Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is impossible to triangularize. 
*/
bool Triangularize(double *A, double *b, uint64_t n){
    
    /* Votre code ici */

    return false;
}

/*
    Solves a system of linear equations Ax=b, given a matrix A (size n x n) and vector b(size n).
    Uses Gauss elimination algorithm based on truangularization and the ascension solving.
    After the procedure, vector x contains the solution to Ax=b.
    We assume that x has been allocated outside the function.
        Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is of rank <n .
*/
bool SolveSystemGauss(double *x, double *A, double *b, uint64_t n){
    
    /* Votre code ici */

    return false;
}

