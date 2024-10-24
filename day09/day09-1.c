#include <stdio.h>


struct vector
{
	int x, y, z;
};
struct vector vec_res; //결과를 받기 위한 전역 변수

void plus(struct vector a, struct vector b);

void minus(struct vector a, struct vector b);

void outer(struct vector a, struct vector b);

int inner(struct vector a, struct vector b);   //int 값 반환이기에 int로 선언?


int main_aa() {
	struct vector vec1;
	struct vector vec2;
	int order;
	int inn;


	printf("첫번째 벡터 (x, y, z) : ");
	scanf_s("%d %d %d", &vec1.x, &vec1.y, &vec1.z);

	printf("두번째 벡터 (x, y, z) : ");
	scanf_s("%d %d %d", &vec2.x, &vec2.y, &vec2.z);

	printf("입력된 첫번째 벡터 : %d %d %d\n", vec1.x, vec1.y, vec1.z);
	printf("입력된 두번째 벡터 : %d %d %d\n", vec2.x, vec2.y, vec2.z);

	printf("----------------------------------\n");
	printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 외적\n");
	printf("4. 벡터의 내적\n");
	printf("5. 종료\n");
	printf("----------------------------------\n");
	printf("명령 입력: ");
	scanf_s("%d", &order);

	switch (order)
	{
		case 1:
			plus(vec1, vec2);
			printf("벡터의 합은 x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;

		case 2:
			minus(vec1, vec2);
			printf("벡터의 차는 x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;

		case 3:
			outer(vec1, vec2);
			printf("벡터의 외적은 x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;
		
		case 4:
			inn=inner(vec1, vec2);
			printf("벡터의 내적은 vec1 . vec2=%d\n", inn);
			break;
		
		case 5:
			break;

		default:
		break;
	}

	return 0;
}



//전역변수로 구조체 써도 됨?
void plus(struct vector a, struct vector b) {
	vec_res.x = a.x + b.x;
	vec_res.y = a.y + b.y;
	vec_res.z = a.z + b.z;
	return 0;
}

void minus(struct vector a, struct vector b) {
	vec_res.x = a.x - b.x;
	vec_res.y = a.y - b.y;
	vec_res.z = a.z - b.z;
	return 0;
}

void outer(struct vector a, struct vector b) {
	vec_res.x = (a.y * b.z) - (a.z * b.y);
	vec_res.y = (a.z * b.x) - (a.x * b.z);
	vec_res.z = (a.x * b.y) - (a.y * b.x);
	return	0;
}

int inner(struct vector a, struct vector b) {
	int inn = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return inn;
}