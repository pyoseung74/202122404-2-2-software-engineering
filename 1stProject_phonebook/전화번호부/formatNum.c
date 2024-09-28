#include "functions.h"

void formatNum(const char* input, char* output) {
    char temp[BUFFER_SIZE];
    int len = 0;
    int idx = 0;

    // 입력된 전화번호에서 숫자만 추출
    for (int i = 0; input[i] != '\0' && idx < BUFFER_SIZE - 1; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp[idx++] = input[i];
        }
    }
    temp[idx] = '\0'; // 문자열 종료
    len = idx;        // 숫자만 있는 전화번호의 길이

    // 전화번호 길이에 따라 형식 적용
    if (len == 11) {
        // 예: 010-1234-5678
        snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
            temp[0], temp[1], temp[2],
            temp[3], temp[4], temp[5], temp[6],
            temp[7], temp[8], temp[9], temp[10]);
    }
    else if (len == 10) {
        // 예: 02-1234-5678
        snprintf(output, BUFFER_SIZE, "%c%c-%c%c%c%c-%c%c%c%c",
            temp[0], temp[1],
            temp[2], temp[3], temp[4], temp[5],
            temp[6], temp[7], temp[8], temp[9]);
    }
    else {
        // 형식을 적용할 수 없는 경우 숫자만 반환
        strcpy(output, temp);
    }
}
