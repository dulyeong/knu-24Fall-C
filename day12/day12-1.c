#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], int topping_len) {
    int count = 0;
    int elder_cake[100000];   //ö���� ���� ����(����ũ)
    int younger_cake[100000];    //������ ���� ����


    for (int i = 0; i < topping_len; i++) {     //������ ��
        printf("%d\n", topping_len);
        int elder_topping = 0;  //���� ����
        int younger_topping = 0;

        for (int j = 0; j <= i; j++) {
            elder_cake[j] = topping[j];
        }
        for (int j = topping_len; j > i; j--) {
            younger_cake[j-1] = topping[j-1];
        }

        int topp_spec = 0;
        while (topp_spec <= 10000) {
            for (int j = 0; j < strlen(elder_cake); j++) {  //���ΰ��� ����
                if (elder_cake[j] == topp_spec) {
                    elder_topping++;
                }
            }
            for (int j = 0; j <= strlen(younger_cake); j++) {
                if (younger_cake[j] == topp_spec) {
                    younger_topping++;
                }
            }
            topp_spec++;
        }

        if (elder_topping == younger_topping) {
            printf("%d\n", i);
            count++;
        }
    }

    return count;
}

int main() {
    int t[100000] = {1, 2, 1, 3, 1, 4, 1, 2};
    
    printf("%d", sizeof(t) / sizeof(int));
    printf("%d",solution(t, sizeof(t) / sizeof(int)));

}