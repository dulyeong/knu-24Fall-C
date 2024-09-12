#include <stdio.h>

int main() {
	int way = 0;
	double x, y=0;
	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &way);
	printf("숫자 1을 입력하세요 :");
	scanf_s("%lf", &x);
	printf("숫자 2을 입력하세요 :");
	scanf_s("%lf",&y);

	if (way == 1)
		printf("%lf + %lf = %lf\n", x, y, x + y);
	else if (way == 2)
		printf("%lf - %lf = %lf\n", x, y, x - y);
	else if (way == 3)
		printf("%lf * %lf = %lf\n", x, y, x * y);
	else
		printf("%lf / %lf = %lf\n", x, y, x / y);
	return 0;
}