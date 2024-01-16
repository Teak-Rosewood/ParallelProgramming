#include <stdio.h>
#include <omp.h>

void swap(int* a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int my_arr[9];
    printf("Enter 9 numbers\n");
    int i;
	for(i=0;i<9;i++)
    {
        scanf("%d",&my_arr[i]);
    }
    printf("Reversing digits...\n");
    omp_set_num_threads(9);
    #pragma omp parallel for
	for(i=0;i<9;i++)
    {
        int value = my_arr[omp_get_thread_num()];
		int rev = 0;
        while(value>0)
		{
  		 int digit = value%10;
     	 value /= 10;
	     rev = 10*rev+digit;
	    }
        my_arr[omp_get_thread_num()] = rev;
    }
    for(i=0;i<9;i++)
    {
        printf("%d ",my_arr[i]);
    }
}
