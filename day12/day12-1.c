#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int count = 0;

    int elder[100001] = { 0 };  //�ε����� ���� ǥ��
    int younger[100001] = { 0 };
    int elder_topp = 0;   //���� ��
    int younger_topp = 0;

    for (int i = 0; i < topping_len; i++) {     //���� �� ���� ä���, ���� �� ����
        if (elder[topping[i]] == 0) {
            elder_topp++;
        }
        elder[topping[i]]++;    //���� ���� ����
    }


    for (int i = 0; i < topping_len; i++) {
        //���� �ϳ��� �߰�
        if (younger[topping[i]] == 0) {
            younger_topp++;
        }
        younger[topping[i]]++;

        //�� �ϳ� �� ����
        elder[topping[i]]--;
        if (elder[topping[i]] == 0) {
            elder_topp--;
        }


        if (elder_topp == younger_topp) {
            count++;
        }
    }
    return count;
}

