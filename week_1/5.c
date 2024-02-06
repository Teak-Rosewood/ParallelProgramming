#include <stdio.h>

int main()
{
	printf("Enter length of strings\n");
	int len;
	scanf("%d\n",&len);
	char string1[len],string2[len],string3[2*len];
	printf("Enter the strings");
	gets(string1);
	gets(string2);
	int turn = 0;
	int i=0,j=0,k=0;
	while(string1[i] != '\0' || string2[j] != '\0')
	{
		if(!turn)
		{
		     	string3[k] = string1[i];
			i++;
		}
		else
		{
			string3[k] = string2[j];
			j++;
		}
		k++;
		turn = !turn;
	}
	puts(string3);
}
