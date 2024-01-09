#include <stdio.h>
int main() {
	int m, n;
	printf("Enter the dimentions of matrix: ");
	scanf("%d", &m);
	scanf("%d", &n);
	int mat[m][n];
	for( int i = 0; i < m; i++){
		for( int j = 0; j < n; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	printf("Enter a vector of dimentions %d: ", n);
	int vec[n];

	for(int i = 0; i < n; i++)
		scanf("%d", &vec[i]);	

	int res[m];

	for( int i = 0; i < m; i++){
		int sum = 0;
		for( int j = 0; j < n; j++){
			sum = sum + mat[i][j]*vec[j];
		}
		res[i] = sum;
	}

	for(int i = 0; i < m; i++)
		printf("%d ", res[i]);
}
