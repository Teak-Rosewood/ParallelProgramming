#include <stdio.h>
#include<limits.h>
#include<omp.h>
#include <time.h>

void Sort(int[],int);
void SortParallel(int[],int);
void swap(int*,int*);

int main()
{
	printf("Enter array size:\n");
	int n;
	scanf("%d",&n);
	int arr[n],arr2[n];
	printf("Enter array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		arr2[i] = arr[i];
	}
	clock_t clock1;
	clock1 = clock();
	Sort(arr,n);
	clock1 = clock()-clock1;
	double time_taken1 = ((double)clock1)/CLOCKS_PER_SEC;
	printf("%f",time_taken1);
	
	clock_t clock2;
	clock2 = clock();
	SortParallel(arr2,n);
	clock2 = clock()-clock2;
	double time_taken2 = ((double)clock2)/CLOCKS_PER_SEC;
	
	printf("%f\n",time_taken2);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}
}

void swap(int *a, int* b)
{
 	 int temp = *a;
	 *a = *b;
	 *b = temp;	
}

int partition(int arr[],int low,int high)
{
  int pivot=arr[high];
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

            
void quickSort(int arr[],int low,int high)
{
  if(low<high)
  {
    int pi=partition(arr,low,high);
    #pragma omp task
    quickSort(arr,low,pi-1);
    #pragma omp task
    quickSort(arr,pi+1,high);
  }
}
        

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
   
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void Sort(int arr[],int n){
	 int mid = n/2;
	 insertionSort(arr,mid);
	 quickSort(arr,mid,n);
	 mergeSort(arr,0,n);
}

void SortParallel(int arr[],int n){
	int mid = n/2;
	#pragma omp parallel
	#pragma omp single
	{
		#pragma omp task
		insertionSort(arr,mid);
		#pragma omp task
		quickSort(arr,mid,n);
		#pragma omp taskwait
		mergeSort(arr,0,n);
	}
}


