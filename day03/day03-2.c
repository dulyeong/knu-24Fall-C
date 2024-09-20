#include <stdio.h>

int fa(int a);

int main() {
	int num,ans;
	scanf_s("%d", &num);
	ans = fa(num);
	printf("%d! = %d", num, ans);
	return 0;
}

int fa(int a) {
	int res = 0;
	if (a == 1||a==0)
		return 1;
	res = a * fa(a - 1);
	return res;
}