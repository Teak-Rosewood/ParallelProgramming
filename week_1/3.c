#include <stdio.h>

int main()
{
    char my_str[100];
    printf("Enter a string\n");
    gets(my_str);
    for(int i=0;my_str[i] != '\0';i++)
    {
        int val = my_str[i];
        if(val>=65 && val<=90)
	    my_str[i] += 32;
	else if(val>=97 && val<= 122)
	    my_str[i] -= 32;
    }
    puts(my_str);
}
