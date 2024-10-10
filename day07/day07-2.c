#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	double x = 0;
	double y = 0;
	//������ 1
	int count = 0;
	double circle = 0;

	srand(time(NULL));

	while (count <= 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;//0~1���� ����
		if (sqrt(pow(x,2)+pow(y,2))<1)
		{
			circle++;
		}
		count++;
		if (count%10000000==0)
		{
			printf("%d%%����.. ������ : ",count/10000000);
			printf("%f", 4 * (circle / count));
			
			for (int i = 0; i < (count/ 100000000); i++)
			{
				printf("��");
			}
			for (int i = 10; i > (count / 100000000); i--)
			{
				printf("��");
			}

			printf("\n");
		}
		
	}
	printf("������ : %f\n", 4 * (circle / count));  //������ ������

	return 0;
}

