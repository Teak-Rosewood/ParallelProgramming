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
	
	omp_set_num_threads(m);
	int sum[m];
	#pragma omp parallel for 
	for(i = 0; i < m; i++){
		sum[omp_get_thread_num()] = 0;
		for(j = 0; j < n; j++){
			sum[omp_get_thread_num()] = sum[omp_get_thread_num()] + mat[omp_get_thread_num()][j]*vec[j];
		}
		res[omp_get_thread_num()] = sum[omp_get_thread_num()];
	}

	for(i = 0; i < m; i++)
		printf("%d ", res[i]);
}
