#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int snum;
	char name[100];
	int score;
};





int main() {
	int N;
	struct student* per;
	scanf_s("%d", &N);

	per = (struct student*)malloc(N * sizeof(struct student));
	for (int i = 0; i < N; i++)
	{
		printf("%d번째 학생 학번: ", i + 1);
		scanf_s("%d", &per[i].snum);
		printf("%d번째 학생 이름: ", i + 1);
		scanf_s("%s", per[i].name, 100);
		

		printf("%d번째 학생 점수: ", i + 1);
		scanf_s("%d", &per[i].score);
	}
	int max = 0;
	int min = 1000;
	int sum = 0;
	for (int i = 0; i < N - 1; i++)
	{
		max = per[i].score > per[i+1].score ? per[i].score : per[i+1].score;
		min = per[i].score < per[i+1].score ? per[i].score : per[i+1].score;
		sum += per[i].score;
		if (i+1==N)
		{
			sum += per[i + 1].score;
		}
		sum += per[i+1].score;
	}

	printf("%d %d %d\n", max, min, sum);

	free(per);




	return 0;
}