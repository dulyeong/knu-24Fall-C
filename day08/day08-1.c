#include <stdio.h>
#include <string.h>

void reverse(char* a);

int main_wsa() 
{
	int count_arr = 0;
	char arr[100];

	printf("문자열을 입력하세요 : ");
	scanf_s("%s", arr, 100);

	reverse(arr);

	

	printf("%s\n", arr);


	return 0;
}



void reverse(char* a) {
	
	char tmp;
	char* alp = a;
	char* ome = a+(strlen(a)-1);
	while (alp<=ome)
	{
		tmp = *alp;
		*alp= *ome;   ///a 
		*ome = tmp;

		alp++;
		ome--;
	}
	

}