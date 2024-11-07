
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 



struct Node {
	char name[100];
	int score;

	struct Node* link;
};
struct Node* head;

struct Node* create_node(char* name, int score)			//���ڿ��� �Ű������� �� ��* �� ù��° ������ �ּҸ� �˷�����
{	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));	
	strcpy_s(new_node->name,100,name);			//���־� ��Ʃ��� ����?
	new_node->score = score;

	new_node->link = NULL;

	return new_node;
}

struct Node* last_node() {
	struct Node* cur = head;
	while (cur->link != NULL)
	{
		cur = cur->link;
	}
	return cur;
}

struct Node* insert_sort_node(int score) {	//���� �Է��� ����� ��ġ�� ����, �� �Ʒ� sorted�� ����
	struct Node* prev = head;				//ù ��° ���(���� ���)
	struct Node* cur = head->link;			//�� ��° ���(���� ���)

	if (cur == NULL ) {
		return head;
	}

	while (cur != NULL && cur->score > score)//new_node�� �߰��� ������, �� prev�� sorted�� �ǵ���, cur�� ����尡 �Ǹ� Ż�� /
	{
		prev = cur;
		cur = cur->link;
	}
	return prev;

}

void insert_node_sorted(struct Node* new_node) {	//���� �Է��� ���
	struct Node* sorted = insert_sort_node(new_node->score);
	new_node->link = sorted->link;	
	sorted->link = new_node;
}

void print_nodes() {
	struct Node* cur = head->link;
	printf("--------------------\n");
	while (cur != NULL)
	{
		printf("%s : ", cur->name);
		printf("%d\n", cur->score);

		cur = cur->link;
	}
	printf("--------------------\n");

}

struct Node* find_node(int value) {			//Ȱ��ó�� ���� ����?
	struct Node* cur = head->link;
	while (cur != NULL)
	{
		if (cur->score == value) return cur;
		cur = cur->link;
	}
	return NULL;
}

int delete_node(char* name) {
	struct Node* prev = head;
	struct Node* cur = head->link;
	while (cur != NULL)
	{
		if (strcmp(name,cur->name) == 0) {		//���ڿ� ��
			prev->link = cur->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}


int main() {

	head = (struct Node*)malloc(sizeof(struct Node));
	head->link = NULL;

	int way = 0;
	char name[100];
	int score;
	while (way!=3)
	{
		
		printf("1.�л��� ������ �Է�\n");
		printf("2.�л� ���� ����\n");
		printf("3.���α׷� ����\n");
		printf("input : ");
		scanf_s("%d", &way);

		switch (way)
		{
		case 1:
			printf("�л� �̸� : ");
			scanf_s("%s", name, 100);
			printf("%s�� ���� : ", name);
			scanf_s("%d", &score);
			insert_node_sorted(create_node(name, score));
			break;
		case 2:
			printf("������ �л��� �̸� : ");
			scanf_s("%s", name, 100);
			delete_node(name);
			break;
		case 3:

		default:
			break;
		}
		print_nodes();
	}

	
	return 0;
}