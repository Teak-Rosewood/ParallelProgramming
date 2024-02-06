#include <stdio.h>

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
    int i = 0;
	for(i=0;i<9;i++)
    {
        scanf("%d",&my_arr[i]);
    }
    printf("Reversing digits...\n");
    for(i=0;i<9;i++)
    {
        int value = my_arr[i];
	int rev = 0;
        while(value>0)
	{
	    int digit = value%10;
	    value /= 10;
	    rev = 10*rev+digit;
	}
        my_arr[i] = rev;
	printf("%d ",my_arr[i]);
    }
}
