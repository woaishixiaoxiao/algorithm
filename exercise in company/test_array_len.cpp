#include<stdio.h>
void get_len(char arr[10]) {
	int len = sizeof(*arr);
	printf("%d", len);
	getchar();
}
int main() {
	char arr[10];
	get_len(arr);
}
