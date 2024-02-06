#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>


void matrixMultiplication(int m, int n, int p, int mat1[][n], int mat2[][p], int result[][p]) {
	#pragma omp parallel for collapse(3)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrixAddition(int m, int n, int mat1[][n], int mat2[][n], int result[][n]){
	#pragma omp parallel for collapse(2)
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			result[i][j] = mat1[i][j]+mat2[i][j];
		}
	}
}

void matrixSubtraction(int m, int n, int mat1[][n], int mat2[][n], int result[][n]){
	#pragma omp parallel for collapse(2)
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			result[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

void displayMatrix( int m, int n, int mat[][m]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n"); 
	}
}

int main () {
	printf("Enter the dimentions of the two matrices of the form MxN: \n");
	int m, n;
	scanf("%d %d", &m, &n);
	int mat1[m][n], mat2[m][n], res[m][n];
	
	printf("Enter values of Matrix one: \n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	
	printf("Enter values of Matrix two: \n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			res[i][j] = 0;
		}
	}
	
	printf("Matrix Multiplication \n");
	matrixMultiplication(m, n, n, mat1, mat2, res);
	displayMatrix(m , n, res);
	
	printf("Matrix Addition \n");
	matrixAddition(m, n, mat1, mat2, res);
	displayMatrix(m , n, res);
	
	printf("Matrix Subtraction \n");
	matrixSubtraction(m, n, mat1, mat2, res);
	displayMatrix(m , n, res);
}
