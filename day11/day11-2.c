#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
//log10(x)+sin(x)
int main() {
	int start, end, area;
	printf("��ǥ �Լ� : -log10(1/x)+sin(x) \n");

	printf("������ ���� ���� �Է��ϼ��� : ");
	scanf_s("%d",&start);

	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%d", &end);

	printf("������ �ִ뱸���� �Է��ϼ���(2^n) : ");
	scanf_s("%d", &area);
	float bottom = end - start;	//����
	float extent = 0;

	
	for (int i = 0; i < area; i++)
	{
		extent = 0;
		for (int j = 1; j <= pow(2, i); j++)
		{
			extent += (bottom / pow(2, i)) * //�غ�(���� ǥ����)
			(log10(start + (bottom / pow(2, i))*j) + sin(start + (bottom / pow(2, i))*j));
			//����(�� ǥ����)	
		}
		printf("���� \t\t%.0f ���� ��� : %lf\n", pow(2, i),extent);
	}
	

	return 0;
}
