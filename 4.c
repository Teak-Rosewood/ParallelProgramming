#include <stdio.h>
#include <string.h>
int main () {
	char str[1000];
	char res[1000];
	gets(str);
	int count = 0;
	for(int i = 0; i < strlen(str); i++){
		for(int j = 0; j < i + 1; j++, count++){
			res[count] = str[i];
		}
	}
	res[count] = '\0';
	printf("%s", res);
}
