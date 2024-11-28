#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int count = 0;

    int elder[100001] = { 0 };  //인덱스로 종을 표현
    int younger[100001] = { 0 };
    int elder_topp = 0;   //종의 수
    int younger_topp = 0;

    for (int i = 0; i < topping_len; i++) {     //토핑 종 도감 채우기, 토핑 종 세기
        if (elder[topping[i]] == 0) {
            elder_topp++;
        }
        elder[topping[i]]++;    //종에 따른 개수
    }


    for (int i = 0; i < topping_len; i++) {
        //동생 하나씩 추가
        if (younger[topping[i]] == 0) {
            younger_topp++;
        }
        younger[topping[i]]++;

        //형 하나 씩 제거
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

