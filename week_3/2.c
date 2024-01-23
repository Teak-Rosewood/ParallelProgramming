#include <stdio.h>
#include <omp.h>

int main() {
	int m, n, i, j;
	printf("Enter the dimentions of matrix: ");
	scanf("%d", &m);
	scanf("%d", &n);
	int mat[m][n];
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	printf("Enter a vector of dimentions %d: ", n);
	int vec[n];

	for(i = 0; i < n; i++)
		scanf("%d", &vec[i]);	

	int res[m];
	int sum[m];
	for(int i = 0; i < m; i++){
		sum[i] = 0;
	}
	#pragma omp parallel for collapse(2)
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			sum[i] = sum[i] + mat[i][j]*vec[j];
			if(j = n-1)
			res[i] = sum[i];
		}
	}

	for(i = 0; i < m; i++)
		printf("%d ", res[i]);
}
