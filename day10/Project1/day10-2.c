#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum rank {
	Platinum = 1,
	Gold = 2,
	Silver = 3
};
struct Customer {
	char* customerName;
	enum rank Rank;
	int order_amount;
	int point;

	struct Customer* prev;		//head�� link?		*prev�� next�� ����
	struct Customer* next;		//link�� ���� ����
};
struct Customer* head = NULL;

struct Customer* create_node(char* customerName, enum rank Rank, int order_amount, int point) {
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	new_node->customerName = (char*)malloc(50 * sizeof(char));
	strcpy_s(new_node->customerName, 50, customerName);
	new_node->Rank = Rank;
	new_node->order_amount = order_amount;
	new_node->point = point;

	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

struct Customer* last_node() {
	struct Customer* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}

struct Customer* set_priority(struct Customer* new_node) {
	struct Customer* prev = head;
	struct Customer* cur = head->next;

	if (cur == NULL) {
		return head;
	}

	while (cur != NULL) {
		if (cur->Rank > new_node->Rank) { // rank�� ���� ��带 ã��
			printf("!!r\n");

			prev = cur;
			cur = cur->next;
		}
		else if (cur->Rank == new_node->Rank && cur->order_amount < new_node->order_amount) {
			printf("!!o\n");
			prev = cur;
			cur = cur->next;
		}
		else if (cur->Rank == new_node->Rank && cur->order_amount == new_node->order_amount && cur->point < new_node->point)
		{
			printf("!!p\n");
			prev = cur;
			cur = cur->next;
		}
		else
		{
			printf("!!ddddd\n");
			return cur;
			break;
		}
	}
	printf("retrned\n");
	return prev;
}



void insert_node_sorted(struct Customer* new_node) {	//


	struct Customer* sorted = set_priority(new_node);

	//sorted->prev = new_node;
	new_node->next = sorted->next;
	new_node->prev = sorted;

	if (sorted->next != NULL)
		sorted->next->prev = new_node;

	sorted->next = new_node;

}


void print_nodes() {
	struct Customer* cur = head->next;
	int count = 0;
	printf("--------------------\n");
	while (cur != NULL)
	{
		count++;
		printf("%d. %s %d\n ", count, cur->customerName, cur->Rank);

		cur = cur->next;
	}
	printf("--------------------\n");
}


int delete_node(char* customerName) {
	struct Customer* prev = head;
	struct Customer* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(customerName, cur->customerName) == 0) {		//���ڿ� ��
			prev->next = cur->next;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	return 0;
}


int main() {

	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->next = NULL;
	char customerName[50];
	enum rank Rank;
	int order_amount;
	int point;
	int way = 0;

	while (way != 4)
	{

		printf("1.���� ������ �Է�\n");
		printf("2.�� ���� ����\n");
		printf("3.�� �켱���� ���\n");
		printf("4.���α׷� ����\n");
		printf("input : ");
		scanf_s("%d", &way);

		switch (way)
		{
		case 1:
			printf("\n�� ���� : ");
			scanf_s("%s", customerName, 50);
			printf("%s�� ��� : ", customerName);
			scanf_s("%d", &Rank);
			printf("%s�� �ֹ��� : ", customerName);
			scanf_s("%d", &order_amount);
			printf("%s�� ����Ʈ : ", customerName);
			scanf_s("%d", &point);
			insert_node_sorted(create_node(customerName, Rank, order_amount, point));
			printf("\n");
			break;
		case 2:
			printf("������ ���� �̸� : ");
			scanf_s("%s", customerName, 50);
			delete_node(customerName);
			break;
		case 3:
			print_nodes();
			break;
		case 4:

		default:
			break;
		}

	}

	return 0;
}