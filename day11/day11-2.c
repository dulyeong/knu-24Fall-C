#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
//log10(x)+sin(x)
int main() {
	int start, end, area;
	printf("목표 함수 : -log10(1/x)+sin(x) \n");

	printf("적분할 시작 값을 입력하세요 : ");
	scanf_s("%d",&start);

	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%d", &end);

	printf("시행할 최대구간을 입력하세요(2^n) : ");
	scanf_s("%d", &area);
	float bottom = end - start;	//길이
	float extent = 0;

	
	for (int i = 0; i < area; i++)
	{
		extent = 0;
		for (int j = 1; j <= pow(2, i); j++)
		{
			extent += (bottom / pow(2, i)) * //밑변(길이 표현됨)
			(log10(start + (bottom / pow(2, i))*j) + sin(start + (bottom / pow(2, i))*j));
			//높이(점 표현됨)	
		}
		printf("구간 \t\t%.0f 적분 결과 : %lf\n", pow(2, i),extent);
	}
	

	return 0;
}
