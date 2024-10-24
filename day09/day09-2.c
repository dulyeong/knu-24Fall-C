#include <stdio.h>

struct Product {
	int id;
	char *name[100];
	int price;
};

void printProduct(struct Product pr[]);


int main() {
	struct Product pr_list[5];
	for (int i = 0; i < 5; i++)
	{
		printf("상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");
		
		printf("상품 ID : ");
		scanf_s("%d", &pr_list[i].id);
		if (pr_list[i].id == 0) {
			printf("\n");
			break;
		}

		printf("상품명 : ");
		scanf_s("%s", pr_list[i].name,100); //이게 왜 오래걸림 !!!name,100!!!

		printf("가격 : ");
		scanf_s("%d", &pr_list[i].price);
		printf("\n");
	}

	printProduct(pr_list);

	return 0;
}



void printProduct(struct Product pr[]) {	//[] 이유 확인
	printf("<<입력된 상품 목록>>\n");

	for (int i = 0; i < 5; i++)				//원래 이런?
	{
		if (pr[i].id==0)
		{
			break;
		}
		printf("상품 ID : %d\n", pr[i].id);
		printf("상품명 : %s\n", pr[i].name);
		printf("가격 : %d원\n\n", pr[i].price);
	}
}
