#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int snum;
	char name[100];
	int score;
};





int main_s() {
	int N;
	struct student* per;
	scanf_s("%d", &N);

	per = (struct student*)malloc(N * sizeof(struct student));
	for (int i = 0; i < N; i++)
	{
		printf("%d��° �л� �й�: ", i + 1);
		scanf_s("%d", &per[i].snum);
		printf("%d��° �л� �̸�: ", i + 1);
		scanf_s("%s", per[i].name, 100);
		

		printf("%d��° �л� ����: ", i + 1);
		scanf_s("%d", &per[i].score);
	}

	free(per);




	return 0;
}