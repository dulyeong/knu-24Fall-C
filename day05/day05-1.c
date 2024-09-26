#include <stdio.h>
#include <stdlib.h>

int main_a() {

	int N;
	int* snum;
	int* score;
	char** name;

	scanf_s("%d", &N);


	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++)
	{
		printf("%d번째 학생 학번: ",i+1);
		scanf_s("%d", &snum[i]);
		printf("%d번째 학생 이름: ", i+1);
		name[i] = (char*)malloc(100 * sizeof(char));
		scanf_s("%s", name[i], 100);

		printf("%d번째 학생 점수: ", i+1);
		scanf_s("%d", &score[i]);
	}

	printf("%d\n", score[1]);
	int max = 0;
	int min = 1000;
	int sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		max = score[i] > score[i + 1] ? score[i] : score[i + 1];
		min = score[i] < score[i + 1] ? score[i] : score[i + 1];
		sum += score[i];
		if (i + 1 == N)
		{
			sum += score[i + 1];
		}
	}
	

	printf("%d %d %d\n",max,min,sum );


	free(snum);
	free(score);
	for (int i = 0; i < N; i++)
		free(name[i]);
	free(name);
	
	

	return 0;
}