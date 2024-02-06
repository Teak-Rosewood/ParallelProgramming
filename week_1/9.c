#include <stdio.h>
#include <string.h>  

int main()
{
	printf("Enter m\n");
	int n,m;
	scanf("%d",&m);
	printf("Enter n\n");
	scanf("%d",&n);
	char array1[m][n];
	int array2[m][n];
	char output[100];

	printf("Enter character array(row-wise)\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %c",&array1[i][j]);
		}
	}
	printf("Enter integer array(row-wise)\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&array2[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%c",array1[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",array2[i][j]);
		}
		printf("\n");
	}
	printf("Output string\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k = 0;k<array2[i][j];k++)
			{
				char temp[2];
				temp[0] = array1[i][j];
				temp[1] = '\0';
				strcat(output,temp);
			}
		}
	}
	puts(output);
}

