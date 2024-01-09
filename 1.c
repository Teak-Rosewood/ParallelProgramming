#include <stdio.h>
int main() {
	int arr[9];
	for(int i = 0; i < 9; i++){
		scanf("%d", &arr[i]);
		int temp = arr[i];
		int count = 1;
		int num = 0;
		while(temp != 0){
			int temp1 = temp % 10;
			num = num + (temp1*count*10); 
			count++;
			temp = temp / 10;
		}
		arr[i] = num;
	}
	for(int i = 0; i < 9; i++){
		printf("%d ", arr[i]);
	}
}
