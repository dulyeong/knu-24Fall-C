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
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� ID�� 0 �Է�)\n");
		
		printf("��ǰ ID : ");
		scanf_s("%d", &pr_list[i].id);
		if (pr_list[i].id == 0) {
			printf("\n");
			break;
		}

		printf("��ǰ�� : ");
		scanf_s("%s", pr_list[i].name,100); //�̰� �� �����ɸ� !!!name,100!!!

		printf("���� : ");
		scanf_s("%d", &pr_list[i].price);
		printf("\n");
	}

	printProduct(pr_list);

	return 0;
}



void printProduct(struct Product pr[]) {	//[] ���� Ȯ��
	printf("<<�Էµ� ��ǰ ���>>\n");

	for (int i = 0; i < 5; i++)				//���� �̷�?
	{
		if (pr[i].id==0)
		{
			break;
		}
		printf("��ǰ ID : %d\n", pr[i].id);
		printf("��ǰ�� : %s\n", pr[i].name);
		printf("���� : %d��\n\n", pr[i].price);
	}
}
