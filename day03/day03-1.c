#include <stdio.h>

int sosu(int a);


int main_ss() {
	int num;
	scanf_s("%d", &num);
	num = sosu(num);
	if (num == 1)
		printf("소수입니다.\n");
	else
		printf("소수가 아닙니다.\n");
	return 0;
}

int sosu(int a) {
	int count=0;

	if (a == 1)
		return 0;

	for (int i = 1; i <= a; i++)
		if (a % i == 0)
			count++;
		else
			continue;
	if (count == 2)
		return 1;
	else
		return 0;
}