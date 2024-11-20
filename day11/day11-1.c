#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	
	int a, b, c;
	float D;
	printf("ax^2 + bx + c = 0\n");
	printf("a, b, c 입력: ");
	scanf_s("%d %d %d", &a, &b, &c);
	D = pow(b, 2) - 4 * a * c;
	
	if (D>0)
	{
		printf("%lf\n", (-1 * b + sqrt(D)) / 2 * a);
		printf("%lf\n", (-1 * b - sqrt(D)) / 2 * a);
	}
	else if (D==0)
	{
		printf("%d\n", -b / 2 * a);
	}
	else
	{
		printf("허수입니다.\n");
	}
	return 0;
}