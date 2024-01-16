#include <stdio.h>
#include <omp.h>

int main() {
	int num1, num2;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	int i = 0;
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		if(omp_get_thread_num() == 0)	
			 printf("Sum: %d \n", num1+num2);
		else if (omp_get_thread_num() == 1)
			 printf("Difference: %d \n", num1-num2);
		else if (omp_get_thread_num() == 2)
			 printf("Product: %d \n", num1*num2);
		else
			printf("Division: %f \n", 1.0*(num1)/num2);
	}
}
