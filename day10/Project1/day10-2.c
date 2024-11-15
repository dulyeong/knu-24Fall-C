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

	struct Customer* prev;		//head의 link?		*prev의 next는 현재
	struct Customer* next;		//link와 같은 역할
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
		// 새 노드의 순위가 더 높은 경우 (숫자가 더 작은 경우)
		if (new_node->Rank < cur->Rank) {
			return prev;
		}
		// 순위가 같은 경우
		else if (new_node->Rank == cur->Rank) {
			// 주문량이 더 많은 경우
			if (new_node->order_amount > cur->order_amount) {
				return prev;
			}
			// 주문량도 같은 경우
			else if (new_node->order_amount == cur->order_amount) {
				// 포인트가 더 많은 경우
				if (new_node->point > cur->point) {
					return prev;
				}
			}
		}
		prev = cur;
		cur = cur->next;
	}

	// 마지막까지 왔다면 맨 뒤에 삽입
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
		if (strcmp(customerName, cur->customerName) == 0) {		//문자열 비교
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

		printf("1.고객의 정보를 입력\n");
		printf("2.고객 정보 제거\n");
		printf("3.고객 우선순위 출력\n");
		printf("4.프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &way);

		switch (way)
		{
		case 1:
			printf("\n고객 성명 : ");
			scanf_s("%s", customerName, 50);
			printf("%s의 등급 : ", customerName);
			scanf_s("%d", &Rank);
			printf("%s의 주문량 : ", customerName);
			scanf_s("%d", &order_amount);
			printf("%s의 포인트 : ", customerName);
			scanf_s("%d", &point);
			insert_node_sorted(create_node(customerName, Rank, order_amount, point));
			printf("\n");
			break;
		case 2:
			printf("삭제할 고객의 이름 : ");
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