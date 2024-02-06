#include <stdio.h>
#include<limits.h>
#include<omp.h>
#include <time.h>

int search(int[],int,int);
int searchParallel(int[],int,int);

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
	
	printf("Enter search value:\n");
	int a;
	scanf("%d",&a);
	clock_t clock1;
	clock1 = clock();
	int pos1 = search(arr,n,a);
	clock1 = clock()-clock1;
	double time_taken1 = ((double)clock1)/CLOCKS_PER_SEC;
	printf("%f",time_taken1);
	
	clock_t clock2;
	clock2 = clock();
	int pos2 = searchParallel(arr,n,a);
	clock2 = clock()-clock2;
	double time_taken2 = ((double)clock2)/CLOCKS_PER_SEC;
	
	printf("%f\n",time_taken2);
	printf("found at %d",pos1);
}

int search(int arr[],int n,int a){
	for(int i=0;i<n;i++){
		if(arr[i]==a){
			return i;
		}
	}
	return -1;
}
int searchParallel(int arr[], int n, int a) {
    int result = -1;

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            #pragma omp critical
            {
                if (result == -1) {
                    result = i;
                }
            }
        }
    }

    return result;
}
