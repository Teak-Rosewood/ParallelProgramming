#include <stdio.h>
#include<limits.h>
#include<omp.h>
#include <time.h>

void selectionSort(int[],int);
void selectionSortParallel(int[],int);
void swap(int*,int*);

int main()
{
	printf("Enter array size:\n");
	int n;
	scanf("%d",&n);
	int arr[n];
	printf("Enter array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	clock_t clock1;
	clock1 = clock();
	selectionSort(arr,n);
	clock1 = clock()-clock1;
	double time_taken1 = ((double)clock1)/CLOCKS_PER_SEC;
	printf("%f",time_taken1);
	
	clock_t clock2;
	clock2 = clock();
	selectionSort(arr,n);
	clock2 = clock()-clock2;
	double time_taken2 = ((double)clock2)/CLOCKS_PER_SEC;
	
	printf("%f\n",time_taken2);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

void swap(int *a, int* b)
{
 	 int temp = *a;
	 *a = *b;
	 *b = temp;	
}

void selectionSort(int arr[],int n)
{
	for(int i=0;i<n;i++){
		int high = INT_MAX,low_key = i;
		for(int j=i;j<n;j++){
			if(arr[j]<high){
				high = arr[j];
				low_key = j;
			}
		}
		swap(&arr[i],&arr[low_key]);
	}
}

void selectionSortParallel(int arr[],int n)
{
	#pragma omp parallel for
	for(int i=0;i<n;i++){
		int high = INT_MAX,low_key = i;
		for(int j=i;j<n;j++){
			if(arr[j]<high){
				high = arr[j];
				low_key = j;
			}
		}
		swap(&arr[i],&arr[low_key]);
	}
}
