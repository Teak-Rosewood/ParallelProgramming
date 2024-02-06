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

void sumCriticalSection(int first, int last){
    int sum = 0;
    #pragma omp parallel for
    for (int i=first;i<= last;i++){
        #pragma omp critical
        sum=sum+i;
    }
    printf("Sum of numbers from %d to %d is %d using Critical Section. \n", first, last, sum);
} 

void sumAtomic(int first, int last){
    int sum = 0;
    #pragma omp parallel for
    for (int i=first;i<= last;i++){
        #pragma omp atomic
        sum=sum+i;
    }
    printf("Sum of numbers from %d to %d is %d using Atomic. \n", first, last, sum);
} 

void sumLocks(int first, int last){
    int sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int i=first;i<= last;i++){
        omp_set_lock(&lock);
        sum=sum+i;
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
    printf("Sum of numbers from %d to %d is %d using Locks. \n", first, last, sum);
} 

void sumMaster(int first, int last){
    int sum = 0;
    #pragma omp parallel for reduction (+:sum)
    for (int i=first;i<= last;i++)
          sum=sum+i;
          
    #pragma omp master
    printf("Sum of numbers from %d to %d is %d using Master. \n", first, last, sum);
} 

int main () {
	printf("Enter n for sum of natural numbers up to n: \n");
	int b;
	scanf("%d", &b);
	sumCriticalSection(1, b);
	sumAtomic(1, b);
	sumReduction(1, b);
	sumMaster(1, b);
	sumLocks(1, b);
}
