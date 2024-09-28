#include "functions.h"

void search(PhoneBook* pb) {
    char buf[BUFFER_SIZE]; // 검색할 이름 또는 번호를 저장할 버퍼
    printf("검색할 이름 또는 전화번호를 입력하세요: ");
    scanf(" %[^\n]", buf); // 검색어 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    if (strlen(buf) >= BUFFER_SIZE) {
        printf("검색어가 너무 깁니다.\n");
        return;
    }

    int found = 0; // 검색 결과 여부를 저장할 변수

    for (int i = 0; i < pb->n; i++) {
        // 이름, 학번 또는 전화번호 비교
        if (strstr(pb->entries[i].name, buf) != NULL ||
            strstr(pb->entries[i].studentNumber, buf) != NULL ||
            strstr(pb->entries[i].num, buf) != NULL) {
            printf("이름: %s, 학번: %s, 전화번호: %s\n",
                pb->entries[i].name,
                pb->entries[i].studentNumber,
                pb->entries[i].num);
            found = 1;
        }
    }

    if (!found) {
        printf("'%s'와 일치하는 항목이 없습니다.\n", buf);
    }
}
