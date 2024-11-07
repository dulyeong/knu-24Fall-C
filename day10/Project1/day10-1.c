
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 



struct Node {
	char name[100];
	int score;

	struct Node* link;
};
struct Node* head;

struct Node* create_node(char* name, int score)			//문자열을 매개변수로 할 땐* 즉 첫번째 문자의 주소를 알려야함
{	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));	
	strcpy_s(new_node->name,100,name);			//비주얼 스튜디오 전용?
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

struct Node* insert_sort_node(int score) {	//지금 입력한 노드의 위치를 설정, 즉 아래 sorted를 설정
	struct Node* prev = head;				//첫 번째 노드(이전 노드)
	struct Node* cur = head->link;			//두 번째 노드(지금 노드)

	if (cur == NULL ) {
		return head;
	}

	while (cur != NULL && cur->score > score)//new_node가 중간에 오도록, 즉 prev가 sorted가 되도록, cur이 끝노드가 되면 탈출 /
	{
		prev = cur;
		cur = cur->link;
	}
	return prev;

}

void insert_node_sorted(struct Node* new_node) {	//지금 입력한 노드
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

struct Node* find_node(int value) {			//활용처가 없음 무엇?
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
		if (strcmp(name,cur->name) == 0) {		//문자열 비교
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
		
		printf("1.학생의 성적을 입력\n");
		printf("2.학생 정보 제거\n");
		printf("3.프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &way);

		switch (way)
		{
		case 1:
			printf("학생 이름 : ");
			scanf_s("%s", name, 100);
			printf("%s의 성적 : ", name);
			scanf_s("%d", &score);
			insert_node_sorted(create_node(name, score));
			break;
		case 2:
			printf("삭제할 학생의 이름 : ");
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