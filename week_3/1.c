#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void displayMatrix(int n, int m, int matrix[][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void generateRandomMatrix(int n, int m, int matrix[][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void matrixMultiplicationParallelized(int m, int n, int p, int mat1[][n], int mat2[][p], int result[][p]) {
	#pragma omp parallel for collapse(3)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrixMultiplication(int m, int n, int p, int mat1[][n], int mat2[][p], int result[][p]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
        	result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main () {
	
	// Getting user input for matrix size
	printf("Enter the dimentions of matrices in matrix multiplication in the form M x N N x P: \n");
	int m, n, p;
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%d", &p);
	
	// Matrix initializatin to random numbers
 	int mat1[m][n], mat2[n][p], res[m][p];
	memset(res, 0, sizeof res);
	generateRandomMatrix(m, n, mat1);
	generateRandomMatrix(n, p, mat2);

	// Reviewing time for Parallelized code 
	clock_t begin = clock();
	matrixMultiplicationParallelized(m, n, p, mat1, mat2, res);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	displayMatrix(m, n, mat1);
	printf("\n \n");
	displayMatrix(n, p, mat2);
	printf("\n \n");
	displayMatrix(m, p, res);
	
	printf("Parallelizing the process gave a time of: %lf \n", time_spent);
	
	// Reviewing time for Parallelized code 
	begin = clock();
	matrixMultiplication(m, n, p, mat1, mat2, res);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("Process without parallelizing gave a time of: %lf", time_spent);
}
