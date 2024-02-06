#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

void sumReduction(int first, int last){
	int sum = 0;
	#pragma omp parallel for reduction (+:sum)
	for (int i=first;i<= last;i++)
  		sum=sum+i;
  		
	printf("Sum of numbers from %d to %d is %d using Reduction. \n", first, last, sum);
}  

int main () {
	printf("Enter the interval of the numbers to sum: \n");
	int a, b;
	scanf("%d %d", &a, &b);
	sumReduction(a, b);
}
