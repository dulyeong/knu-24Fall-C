#include <stdio.h>

int pa(int a);

int main() {
	int num,ans;
	scanf_s("%d", &num);
	ans = pa(num);
	printf("%d! = %d", num, ans);
	return 0;
}

int pa(int a) {
	int res = 0;
	if (a == 1)
		return 1;
	res = a * pa(a - 1);
	return res;
}