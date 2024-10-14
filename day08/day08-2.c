#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);  //*�� ���� �����ּ� ((0,0)�� �ּ�)�� �޾ƿԱ� ����?
								//void ���� ��
int main()
{
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);




	return 0;
}


void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			array[i][j] = rand() % 20 + 1;     //1~20
		}
	}
}


void printArray(int array[SIZE][SIZE]) {
	printf("�迭 ��� : \n");


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

}

void movePointer(void* array) {
	int a = 0;
	while (*(int*)array <= 20 && *(int*)array >= 1)   //�ٸ� ���� ����?
	{
		printf("���� ��ġ : (%d, %d) ", a / 10, a % 10);
		printf("�迭�� �� : %d\n", *(int*)array);	//void*�� �޾ұ⿡ *(int*)�� ����ȯ �� �� ȣ��

		a = a + *(int*)array;
		(int*)array += *(int*)array;		//*(int*),(int*) ���� Ȯ��

	}
}

