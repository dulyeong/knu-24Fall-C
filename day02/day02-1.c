#include <stdio.h>

int main() {
	int way = 0;
	double x, y=0;
	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &way);
	printf("���� 1�� �Է��ϼ��� :");
	scanf_s("%lf", &x);
	printf("���� 2�� �Է��ϼ��� :");
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