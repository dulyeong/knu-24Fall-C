#include <stdio.h>
#include <string.h>


int main_aa() 
{
	int count_arr = 0;
	char arr[100];
	char* parr = arr;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", arr, 100);
	count_arr = strlen(arr);
	printf("�������� ���ڿ� : ");

	for (int i = 0; i < count_arr; i++) {
		printf("%c", *(parr+(count_arr-1)-i));
	}
	

	return 0;
}