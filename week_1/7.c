#include <stdio.h>
#include <limits.h>

int max(int arr[5])
{
	int max = INT_MIN;
	for(int i=0;i<5;i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int min(int arr[5])
{
	int min = INT_MAX;
	for(int i = 0;i<5;i++)
	{
		if(arr[i]<min)
			min = arr[i];
	}
	return min;
}	


int main()
{
	int mat[5][5];
	printf("Enter elements in the matrix(row-wise)\n");
	for(int i =0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Before transformatiom...\n");
	for(int i=0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	for(int i = 0;i<5;i++)
	{
		int low = min(mat[i]);
		int high = max(mat[i]);
		for(int j=0;j<5;j++)
		{
			if(i==j)
				mat[i][i] = 0;
			else if(j>i)
			{
				mat[i][j] = low;
			}
			else
			{
				mat[i][j] = high;
			}
		}
	}
	printf("After transformatiom...\n");
	for(int i=0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}
	
