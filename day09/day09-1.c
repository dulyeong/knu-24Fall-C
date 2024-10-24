#include <stdio.h>


struct vector
{
	int x, y, z;
};
struct vector vec_res; //����� �ޱ� ���� ���� ����

void plus(struct vector a, struct vector b);

void minus(struct vector a, struct vector b);

void outer(struct vector a, struct vector b);

int inner(struct vector a, struct vector b);   //int �� ��ȯ�̱⿡ int�� ����?


int main_aa() {
	struct vector vec1;
	struct vector vec2;
	int order;
	int inn;


	printf("ù��° ���� (x, y, z) : ");
	scanf_s("%d %d %d", &vec1.x, &vec1.y, &vec1.z);

	printf("�ι�° ���� (x, y, z) : ");
	scanf_s("%d %d %d", &vec2.x, &vec2.y, &vec2.z);

	printf("�Էµ� ù��° ���� : %d %d %d\n", vec1.x, vec1.y, vec1.z);
	printf("�Էµ� �ι�° ���� : %d %d %d\n", vec2.x, vec2.y, vec2.z);

	printf("----------------------------------\n");
	printf("1. ������ ��\n");
	printf("2. ������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");
	printf("----------------------------------\n");
	printf("��� �Է�: ");
	scanf_s("%d", &order);

	switch (order)
	{
		case 1:
			plus(vec1, vec2);
			printf("������ ���� x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;

		case 2:
			minus(vec1, vec2);
			printf("������ ���� x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;

		case 3:
			outer(vec1, vec2);
			printf("������ ������ x: %d    y: %d    z: %d\n", vec_res.x, vec_res.y, vec_res.z);
			break;
		
		case 4:
			inn=inner(vec1, vec2);
			printf("������ ������ vec1 . vec2=%d\n", inn);
			break;
		
		case 5:
			break;

		default:
		break;
	}

	return 0;
}



//���������� ����ü �ᵵ ��?
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