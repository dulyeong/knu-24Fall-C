#include <stdio.h>

void swap(int* a,int *b);

int main() {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2);
	swap(&num1, &num2);
	printf("%d %d", num1, num2);
	return 0;
}


void swap(int* a, int* b) {
	int ptr = 0;
	ptr = *b;
	*b = *a;
	*a = ptr;
}