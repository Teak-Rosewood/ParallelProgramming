#include <stdio.h>
#include <math.h>

int getOnesComplement(int num){
	int i = 0;
	int bin = 0;
	while(num > 0){
		int rem = num % 2;
		if(rem == 0)
  		    bin = bin + (pow(10, i));
		i++;
		num = num / 2;
	}
	return bin;
}

int binaryToDecimal(int bin){
	int num = bin; 
    int dec_value = 0; 
    int base = 1; 
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
    return dec_value; 
}

int main(){
	
	int m, n, i, j;
	printf("Enter the dimentions of matrix: ");
	scanf("%d", &m);
	scanf("%d", &n);
	int A[m][n];
	int B[m][n];
	int C[m][n];
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &A[i][j]);
			B[i][j] = A[i][j];
			C[i][j] = B[i][j];
		}
	}
	
	for(i = 1; i < m-1; i++){
		for(j = 1; j < n-1; j++){
			B[i][j] = getOnesComplement(A[i][j]);
			C[i][j] = binaryToDecimal(B[i][j]);
		}
	}
	
	printf("Matrix A: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("Matrix B: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
	printf("Matrix C: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
}
