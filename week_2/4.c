#include <stdio.h>
#include <string.h>
#include <omp.h>

int main () {
	char str[1000];
	char res[1000];
	gets(str);
	int count = 0;
	int i = 0, j = 0;
	omp_set_num_threads(strlen(str));
	#pragma omp parallel for
	for(i = 0; i < strlen(str); i++){
		#pragma omp critical
		for(j = 0; j < omp_get_thread_num() + 1; j++, count++){
			res[count] = str[i];
		}
	}
	res[count] = '\0';
	printf("%s", res);
}
