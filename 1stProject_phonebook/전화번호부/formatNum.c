#include "functions.h"

void formatNum(const char* input, char* output) {
    char temp[BUFFER_SIZE]; // 숫자만 추출한 전화번호를 저장할 임시 버퍼
    int idx = 0;

    // 입력된 전화번호에서 숫자만 추출
    for (int i = 0; input[i] != '\0' && idx < BUFFER_SIZE - 1; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp[idx++] = input[i];
        }
    }
    temp[idx] = '\0'; // 문자열 종료

    int len = strlen(temp);

    // 전화번호의 앞 두 자리 확인
    if (strncmp(temp, "01", 2) == 0) {
        // 01로 시작하는 번호 (예: 010-1234-5678)
        if (len == 11) {
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5], temp[6],
                temp[7], temp[8], temp[9], temp[10]);
        }
        else {
            // 형식을 적용할 수 없는 경우 숫자만 반환
            strcpy(output, temp);
        }
    }
    else if (strncmp(temp, "02", 2) == 0) {
        // 02로 시작하는 번호 (예: 02-1234-5678)
        if (len == 10) {
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
    else {
        // 그 외의 경우 (예: 031-123-1245)
        if (len == 10) {
            // 지역번호 3자리 - 국번 3자리 - 번호 4자리
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5],
                temp[6], temp[7], temp[8], temp[9]);
        }
        else if (len == 11) {
            // 지역번호 3자리 - 국번 4자리 - 번호 4자리
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5], temp[6],
                temp[7], temp[8], temp[9], temp[10]);
        }
        else {
            // 형식을 적용할 수 없는 경우 숫자만 반환
            strcpy(output, temp);
        }
    }
}
