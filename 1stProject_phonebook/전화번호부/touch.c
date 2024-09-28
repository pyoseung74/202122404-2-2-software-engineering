#include "functions.h"

void touch(PhoneBook* pb) {
    char buf[BUFFER_SIZE];           // 수정할 이름을 저장할 버퍼
    char newNum[BUFFER_SIZE];        // 새로운 전화번호를 저장할 버퍼
    char formattedNum[BUFFER_SIZE];  // 형식화된 전화번호를 저장할 버퍼

    printf("수정할 이름을 입력하세요: ");
    scanf(" %[^\n]", buf); // 이름 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    int index = -1; // 수정할 인덱스 초기화
    for (int i = 0; i < pb->n; i++) {
        if (strcmp(pb->entries[i].name, buf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("해당 이름이 전화번호부에 없습니다.\n");
        return;
    }

    printf("새로운 전화번호를 입력하세요 (숫자만 입력하거나 '-'를 포함할 수 있습니다): ");
    scanf("%s", newNum); // 새로운 번호 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    if (strlen(newNum) >= BUFFER_SIZE) {
        printf("전화번호가 너무 깁니다.\n");
        return;
    }

    // 전화번호 형식화
    formatNum(newNum, formattedNum);

    // 번호 수정
    strcpy(pb->entries[index].num, formattedNum);

    printf("전화번호가 수정되었습니다.\n");

    saveload(pb, 1); // 데이터 저장
}
