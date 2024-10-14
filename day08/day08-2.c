#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);  //*의 이유 시작주소 ((0,0)의 주소)을 받아왔기 때문?
								//void 이유 모름
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
	printf("배열 출력 : \n");


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
	while (*(int*)array <= 20 && *(int*)array >= 1)   //다른 기준 가능?
	{
		printf("현재 위치 : (%d, %d) ", a / 10, a % 10);
		printf("배열의 값 : %d\n", *(int*)array);	//void*로 받았기에 *(int*)로 형변환 및 값 호출

		a = a + *(int*)array;
		(int*)array += *(int*)array;		//*(int*),(int*) 차이 확인

	}
}

